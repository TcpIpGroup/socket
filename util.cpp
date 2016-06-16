#include "util.h"

Util::Util()
{

}

QHostAddress Util::getIpv4Address() {
    QHostInfo info = QHostInfo::fromName(QHostInfo::localHostName());
    QList<QHostAddress> addresses = info.addresses();
    for (QList<QHostAddress>::const_iterator it = addresses.cbegin(); it != addresses.cend(); ++it) {
        if (it->protocol() == QAbstractSocket::IPv4Protocol) {
            return *it;
        }
    }
    Util::info(tr("ip地址无法获取,程序无法继续运行"));
    exit(0);
    return QHostAddress::Null;
}

QHostAddress Util::getLocalAddr() {
    if (Globle::localAddr != getIpv4Address()) {
        info(tr("您的ip已改变,程序将关闭,请重新启动."));
        exit(0);
    }
    return Globle::localAddr;
}

QByteArray Util::qstirng2QByteArray(QString value) {
    return value.toUtf8();
}

QString Util::qbyteArray2QString(QByteArray value) {
    return QString::fromUtf8(value);
}

int Util::getUsePort(QUdpSocket *udpSocket, QHostAddress addr) {
    int port = 4999;
    while (!udpSocket->bind(QHostAddress::AnyIPv4, ++port, QUdpSocket::DontShareAddress));
    return port;
}

void Util::info(QString msg) {
    QMessageBox::information(nullptr, "提示", msg,
                             QMessageBox::Yes);
}
