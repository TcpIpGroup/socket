#include "server.h"

Server::Server(QHostAddress addr)
{
    this->addr = addr;
    udpSocket = new QUdpSocket(this);

    if (isGroupAddr()) {//组播地址
        this->port = Globle::groupPort;
        if (!udpSocket->bind(QHostAddress::AnyIPv4, this->port, QUdpSocket::ShareAddress)) {
            Util::info(tr("\"").append(QString::number(port)).append("\"端口绑定失败,\n程序无法继续运行"));
            exit(0);
        }
        udpSocket->joinMulticastGroup(addr);
        udpSocket->setSocketOption(QAbstractSocket::MulticastLoopbackOption, 0);
    } else {//
        this->port = Util::getUsePort(udpSocket, this->addr);
    }
    connect(udpSocket, SIGNAL(readyRead()), this, SLOT(on_udpSocket_readyRead()));
}


Server::~Server() {
    if (isGroupAddr()) {
        udpSocket->leaveMulticastGroup(addr);
    }
}

bool Server::isGroupAddr() {
    if (this->addr  == Globle::groupAddr) {
        return true;
    }
    return false;
}

void Server::on_udpSocket_readyRead() {
    while (udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(), datagram.size());
        QString data = Util::qbyteArray2QString(datagram);
        //得到消息类型
        int msgTypeIndex = data.indexOf(",");
        int msgType = data.left(msgTypeIndex).toInt();
        data = data.mid(msgTypeIndex + 1);
        //得到源ip
        int addrIndex = data.indexOf(",");
        QString saddr = data.left(addrIndex);
        data = data.mid(addrIndex + 1);

        int sport = -1;
        QString smsg = data;

        switch(msgType) {
        case MessageType::PEER: {
            int portIndex = data.indexOf(",");
            sport = data.left(portIndex).toInt();
            smsg = data.mid(portIndex + 1);
            }
        case MessageType::RECEIVE:
        case MessageType::LOGIN:
        case MessageType::LOGOUT:
        case MessageType::ONLINE:
        case MessageType::PEERCLOSE:
        default:
            break;
        }
        qDebug()<<"Server::on_udpSocket_readyRead"<<msgType<<saddr<<sport<<smsg;
        emit receiveDatagram(MessageType(msgType), saddr, sport, smsg);
    }
}

