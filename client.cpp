#include "client.h"

Client::Client(QHostAddress addr, int port)
{
    this->addr = addr;
    this->port = port;
    udpSocket = new QUdpSocket();
}

void Client::login() {
    sendDatagram(MessageType::LOGIN, Util::getLocalAddr().toString());
}

void Client::online(QString daddr) {
    QString data = QString::number(MessageType::ONLINE).append(",").append(Util::getLocalAddr().toString()).append(",");
    QByteArray array = Util::qstirng2QByteArray(data);
    qDebug()<<"Client::sendDatagram"<<data<<daddr<<this->port;
    udpSocket->writeDatagram(array.data(), array.size(), QHostAddress(daddr), this->port);
}

void Client::logout() {
    sendDatagram(MessageType::LOGOUT, Util::getLocalAddr().toString());
}

void Client::peer(int port, QString msg) {
    sendDatagram(MessageType::PEER, Util::getLocalAddr().toString(), port, msg);
}

void Client::peerClose() {
    sendDatagram(MessageType::PEERCLOSE, Util::getLocalAddr().toString());
}

void Client::sendDatagram(MessageType type, QString addr, int port, QString msg) {
    QString data = QString::number(type).append(",").append(addr).append(",");
    if (port > 0) {
        data.append(QString::number(port)).append(",");
    }
    data.append(msg);
    QByteArray array = Util::qstirng2QByteArray(data);
    qDebug()<<"Client::sendDatagram"<<data<<this->addr<<this->port;
    udpSocket->writeDatagram(array.data(), array.size(), this->addr, this->port);
}

void Client::sendDatagram(MessageType type, QString addr, int port) {
    sendDatagram(type, addr, port, "");
}

void Client::sendDatagram(MessageType type, QString addr) {
    sendDatagram(type, addr, -1, "");
}
