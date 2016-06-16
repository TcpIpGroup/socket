#ifndef SERVER_H
#define SERVER_H
#include <QUdpSocket>
#include <QHostAddress>
#include <QThread>
#include <util.h>
#include <enum.h>

class Server: public QObject
{
    Q_OBJECT
signals:
    /**
     * @brief receiveDatagram 接收数据包
     * @param type 接收的数据包类型
     * @param ip 源ip
     * @param port 源端口
     * @param msg 源消息
     */
    void receiveDatagram(MessageType type, QString addr, int port, QString msg);
public:
    /**
     * @brief Server
     * @param groupAddress 组播地址,如果存在的话
     * @param port 监听端口
     */
    Server(QHostAddress addr);
    ~Server();
    bool isGroupAddr();
protected slots:
    void on_udpSocket_readyRead();

public:
    QUdpSocket *udpSocket;
    QHostAddress addr;
    int port;
};

#endif // SERVER_H
