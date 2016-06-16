#ifndef UTIL_H
#define UTIL_H
#include <QHostInfo>
#include <QByteArray>
#include <QUdpSocket>
#include <QMessageBox>
#include <enum.h>
#include <globle.h>
class Globle;

class Util: QObject
{
    Q_OBJECT
public:
    Util();
    static QHostAddress getIpv4Address();
    static QHostAddress getLocalAddr();
    static QByteArray qstirng2QByteArray(QString value);
    static QString qbyteArray2QString(QByteArray value);
    static int getUsePort(QUdpSocket *udpSocket, QHostAddress addr);
    static void info(QString msg);
};

#endif // UTIL_H
