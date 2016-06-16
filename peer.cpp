#include "peer.h"
#include "ui_peer.h"

Peer::Peer(QString addr, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Peer)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("私聊模式 对方ip(").append(addr).append(")"));
    QHostAddress hostAddr = QHostAddress(addr);
    server = new Server(hostAddr);
    client = new Client(hostAddr, Globle::groupPort);//暂时使用组播端口
    connect(server, SIGNAL(receiveDatagram(MessageType,QString,int,QString)), this, SLOT(on_receiveDatagram(MessageType,QString,int,QString)));
}

Peer::~Peer()
{
    delete ui;
}

void Peer::closeEvent(QCloseEvent *event) {

    client->peerClose();
    emit closed(this->server->addr.toString());
}

void Peer::receiveDatagram(MessageType type, QString addr, int port, QString msg) {
    qDebug()<<"Peer::on_receiveDatagram"<<type<<addr<<port<<msg;
    switch(type) {
    case MessageType::RECEIVE: {
        QListWidgetItem *item = new QListWidgetItem(tr("来自对方的消息:\n").append(msg));
        ui->listWidgetShow->addItem(item);
        break;
        }
    case MessageType::PEERCLOSE: {
        client->port = Globle::groupPort;
        break;
        }
    default:
        break;
    }
}

void Peer::on_receiveDatagram(MessageType type, QString addr, int port, QString msg) {
    receiveDatagram(type, addr, port, msg);
}

void Peer::on_btnSend_clicked() {
    QString msg = ui->textInput->toPlainText().trimmed();
    if (!msg.isEmpty()) {
        QListWidgetItem *item = new QListWidgetItem(tr("来自您的消息:\n").append(msg));
        ui->listWidgetShow->addItem(item);
        item->setTextAlignment(Qt::AlignRight);
        if (client->port != Globle::groupPort) {
            client->sendDatagram(MessageType::RECEIVE, Util::getLocalAddr().toString(), -1, msg);
        } else {
            client->peer(this->server->port, msg);
        }
    } else {
        Util::info(tr("不能发送空白信息"));
    }
    ui->textInput->clear();
}

void Peer::on_btnClear_clicked() {
    ui->listWidgetShow->clear();
}
