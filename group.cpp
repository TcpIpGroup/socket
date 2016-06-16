#include "group.h"
#include "ui_group.h"

Group::Group(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Group)
{
    qDebug()<<"Group";
    ui->setupUi(this);
    this->setWindowTitle(tr("群聊模式 本机ip(").append(Util::getLocalAddr().toString()).append(")"));
    server = new Server(Globle::groupAddr);
    client = new Client(Globle::groupAddr, Globle::groupPort);
    connect(server, SIGNAL(receiveDatagram(MessageType,QString,int,QString)), this, SLOT(on_receiveDatagram(MessageType,QString,int,QString)));
    client->login();
}

Group::~Group()
{
    delete ui;
}

void Group::on_receiveDatagram(MessageType type, QString addr, int port, QString msg) {
    qDebug()<<"Group::on_receiveDatagram"<<type<<addr<<port<<msg;
    switch(type) {
    case MessageType::PEER: {
        qDebug()<< "Peer";
        Peer *peer;
        if (addrPeerMap.contains(addr)) {//私聊窗口已经打开
            peer = addrPeerMap.value(addr);
        } else {//私聊窗口未打开
            peer = new Peer(addr);
            addrPeerMap.insert(addr, peer);
            connect(peer, SIGNAL(closed(QString)), this, SLOT(on_peer_closed(QString)));
            peer->show();
        }

        if (!msg.isEmpty()) {//发起方的第一条私聊消息,并告诉对方自己监听的的端口
            peer->client->peer(peer->server->port, "");
            peer->receiveDatagram(MessageType::RECEIVE, addr, port, msg);
        }
        //设置客户端的发送端口为对方服务器的监听端口
        peer->client->port = port;
        break;
        }
    case MessageType::RECEIVE: {
        QListWidgetItem *item = new QListWidgetItem(tr("来自(").append(addr).append(")的消息:\n").append(msg));
        ui->listWidgetShow->addItem(item);
        break;
        }
    case MessageType::LOGIN: {
        if (ui->listWidgetIp->findItems(addr, Qt::MatchExactly).size() == 0) {
            ui->listWidgetIp->addItem(new QListWidgetItem(addr));
            statusBar()->showMessage(tr("(").append(addr).append(")上线了"));
        }
        client->online(addr);
        break;
        }
    case MessageType::LOGOUT: {
        QList<QListWidgetItem *> items = ui->listWidgetIp->findItems(addr, Qt::MatchExactly);
        if (items.size() > 0) {
            ui->listWidgetIp->takeItem(ui->listWidgetIp->row(items.at(0)));
            statusBar()->showMessage(tr("(").append(addr).append(")下线了"));
            if (addrPeerMap.contains(addr)) {
                Peer *peer = addrPeerMap.value(addr);
                peer->close();
                addrPeerMap.remove(addr);
            }
        }
        break;
        }
    case MessageType::ONLINE: {
        if (ui->listWidgetIp->findItems(addr, Qt::MatchExactly).size() == 0) {
            ui->listWidgetIp->addItem(new QListWidgetItem(addr));
        }
        break;
        }
    default:
        break;
    }
}

void Group::on_btnSend_clicked() {
    QString msg = ui->textInput->toPlainText().trimmed();
    if (!msg.isEmpty()) {
        QListWidgetItem *item = new QListWidgetItem(tr("来自您的消息:\n").append(msg));
        ui->listWidgetShow->addItem(item);
        item->setTextAlignment(Qt::AlignRight);
        client->sendDatagram(MessageType::RECEIVE, Util::getLocalAddr().toString(), -1, msg);
    } else {
        Util::info(tr("不能发送空白信息"));
    }
    ui->textInput->clear();
}

void Group::on_btnClear_clicked() {
    ui->listWidgetShow->clear();
}

void Group::on_listWidgetIp_itemDoubleClicked(QListWidgetItem* item) {
    if (item->text() != Util::getLocalAddr().toString()) {
        if (!addrPeerMap.contains(item->text())) {
            Peer *peer = new Peer(item->text());
            addrPeerMap.insert(item->text(), peer);
            connect(peer, SIGNAL(closed(QString)), this, SLOT(on_peer_closed(QString)));
            peer->show();
        }
    }
}

void Group::on_peer_closed(QString addr) {
    addrPeerMap.remove(addr);
}

void Group::closeEvent(QCloseEvent *event) {
    client->logout();
    exit(0);
}

