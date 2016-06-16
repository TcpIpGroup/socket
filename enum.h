#ifndef ENUM_H
#define ENUM_H


enum MessageType
{
    NONE = 0,
    LOGIN = 1,//登陆,告诉对方ip,并得到回应ip
    LOGOUT = 2,//注销,告诉对方ip
    RECEIVE = 3,//消息,告诉对方ip和消息
    ONLINE = 4,//在线,告诉对方ip
    PEER = 5,//私聊,告诉对方ip和端口
    PEERCLOSE = 6//私聊关闭
};
#endif // ENUM_H
