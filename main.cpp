#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QUdpSocket>

#include "group.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile f(":qdarkstyle/style.qss");
    if (!f.exists())
    {
        printf("Unable to set stylesheet, file not found\n");
    }
    else
    {
        f.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&f);
        qApp->setStyleSheet(ts.readAll());
    }
    Group w;
    w.show();
    return a.exec();
}
