#include "globle.h"

Globle::Globle()
{

}
const QHostAddress Globle::groupAddr = QHostAddress("224.0.1.2");
const QHostAddress Globle::localAddr = Util::getIpv4Address();
