#ifndef CLIENT_H
#define CLIENT_H
#include <QUdpSocket>
#include <QHostAddress>
#include <QThread>
#include <QHostInfo>
#include "util.h"
#include "enum.h"

class Client: public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Client
     * @param addr 目的ip
     * @param port 目的端口
     */
    Client(QHostAddress addr, int port);
    /**
     * @brief login 通知登陆
     */
    void login();
    /**
     * @brief online 当收到别人登陆的消息时告诉他自己在线
     * @param ip
     */
    void online(QString daddr);
    /**
     * @brief logout 通知注销
     */
    void logout();
    /**
     * @brief peer 发起私聊
     * @param port 自己的监听端口,就是server监听的端口
     */
    void peer(int port, QString msg);

    /**
     * @brief peerClose 私聊关闭
     */
    void peerClose();
    /**
     * @brief sendDatagram 发送数据包
     * @param msg 数据
     * @param type 数据类型
     */
    /**
     * @brief sendDatagram
     * @param type
     * @param ip
     * @param port 端口为负数时表示忽略该参数
     * @param msg
     */
    void sendDatagram(MessageType type, QString addr, int port, QString msg);
    void sendDatagram(MessageType type, QString addr, int port);
    void sendDatagram(MessageType type, QString addr);
public:
    QUdpSocket *udpSocket;
    QHostAddress addr;
    int port;
};

#endif // CLIENT_H
