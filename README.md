# socket实验
实现的功能有局域网(路由器和电脑放出的wifi测试过。如果学校局域网不支持的话，说明学校路由器过滤了)组播群聊和私聊,不支持单机,功能相对简单。
所有用户默认在同一个组中，不支持自己分组，在组中，可以选择私聊对象(单播)，上下线提示，丢包没有处理。
套接字实现都使用的udp。
# 类文件说明
1. client(客户端)负责将用户的登陆、注销、在线、私聊、私聊退出、状态和输入信息发送给对方,server负责接收client发过来消息(服务端). 
2. globel存放的是一些全局变量和常量,util是一些工具类,包含常用的转换方法,enum是枚举文件包含MessageType(消息类型)枚举类型.
3. group和peer是可视化窗口，将操作可视化。group是群聊窗口，在群聊窗口中选择私聊对象就能进行私聊(peer)了。
# 开发环境
开发环境：win7 和 Qt Creator

关于部署：将相应的exe拷贝至某个空目录下，然后cmd进入该目录，执行windeployqt exe文件名，就会自动把相关的dll拷贝过来，如果在目标机上还不能运行，提示缺少动态链接库，则需要自己到qt安装目录下的bin目录底下拷贝缺少的dll文件就可以了。

代码写的相对较乱，不易懂。

github在线地址：https://github.com/TcpIpGroup/socket
