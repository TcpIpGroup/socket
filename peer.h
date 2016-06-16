#ifndef PEER_H
#define PEER_H

#include <QMainWindow>

#include "client.h"
#include "server.h"

/**
 * 发起方先进入私聊窗口,当发起方发送第一条消息时,接收方接收消息并自动打开窗口
 */
namespace Ui {
class Peer;
}

class Peer : public QMainWindow
{
    Q_OBJECT

public:
    explicit Peer(QString addr, QWidget *parent = 0);
    ~Peer();
    void receiveDatagram(MessageType type, QString addr, int port, QString msg);

signals:
    void closed(QString addr);

protected:
    void closeEvent(QCloseEvent *event);

protected slots:
    void on_receiveDatagram(MessageType type, QString addr, int port, QString msg);
    void on_btnSend_clicked();
    void on_btnClear_clicked();

public:
    Client *client;
    Server *server;
private:
    Ui::Peer *ui;
};

#endif // PEER_H
