#ifndef GROUP_H
#define GROUP_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QHostAddress>
#include <QListWidgetItem>
#include <QMap>
#include <QStatusBar>

#include "client.h"
#include "server.h"
#include "peer.h"

namespace Ui {
class Group;
}

class Group : public QMainWindow
{
    Q_OBJECT

public:
    explicit Group(QWidget *parent = 0);
    ~Group();

protected slots:
    void on_receiveDatagram(MessageType type, QString addr, int port, QString msg);
    void on_btnSend_clicked();
    void on_btnClear_clicked();
    void on_listWidgetIp_itemDoubleClicked(QListWidgetItem* item);
    void on_peer_closed(QString addr);

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::Group *ui;
    Client *client;
    Server *server;
    QMap<QString, Peer *> addrPeerMap;
};

#endif // GROUP_H
