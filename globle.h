#ifndef GLOBLE_H
#define GLOBLE_H
#include <QMap>
#include "util.h"
class Util;

class Globle
{
public:
    Globle();

    static const QHostAddress groupAddr;
    static const QHostAddress localAddr;
    static const int groupPort = 45454;
};

#endif // GLOBLE_H
