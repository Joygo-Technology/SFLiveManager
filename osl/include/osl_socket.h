//
//  osl_socket.h
//  StarFactory
//
//  Created by Sunniwell on 2016/10/25.
//  Copyright © 2016年 Joygo. All rights reserved.
//

#ifndef osl_socket_h
#define osl_socket_h

#ifdef __cplusplus
extern "C"
{
#endif
    
    /** 创建socket, af=AF_INET,..., type=SOCK_STREAM, ... , protocol=IPPROTO_TCP,... */
    SOCKET osl_socket_create(int32_t af, int32_t type, int32_t protocol);
    
    /** 销毁socket */
    void osl_socket_destroy(SOCKET skt);
    
    /**
     连接远端
     
     0：表示连接成功，1：表示等待，-1：表示错误，应关闭
     */
    int32_t osl_socket_connect(SOCKET skt, char *host, uint16_t port);
    
    /**
     连接状态
     
     0：表示连接成功，1：表示等待，-1：表示错误，应关闭
     */
    int32_t osl_socket_get_connect_state(SOCKET skt);
    
    /**
     在调用 send/recv 返回 -1 时，立即调用此接口判断socket是否出现异常。
     
     0：正常，-1：socket出错
     */
    int32_t osl_socket_get_state(SOCKET skt);
    
    /**
     开始绑定，在 connect() 或 listen() 调用前使用
     
     0：成功，-1：错误
     */
    int32_t osl_socket_bind(SOCKET skt, uint32_t ip, uint16_t port);
    
    /**
     开始监听, max为悬挂队列长度，建议设为5
     
     无错误，返回0，否则，返回SOCKET ERROR，可以调用函数WSAGetLastError取得错误代码。
     */
    int32_t osl_socket_listen(SOCKET skt, int32_t max);
    
    /**
     等待远程连接
     
     0：成功，-1：失败
     */
    SOCKET osl_socket_accept(SOCKET skt, uint32_t *ip, uint16_t *port);
    
    /**
     输入输出控制
     
     0：成功，-1：出错
     */
    int32_t osl_socket_ioctl(SOCKET skt, unsigned long type, uint32_t *val);
    
    /**
     设置参数
     
     若无错误发生，setsockopt()返回0。否则的话，返回SOCKET_ERROR错误，应用程序可通过WSAGetLastError()获取相应错误代码。
     错误代码：
     WSANOTINITIALISED：在使用此API之前应首先成功地调用WSAStartup()。
     WSAENETDOWN：套接口实现检测到网络子系统失效。
     WSAEFAULT：optval不是进程地址空间中的一个有效部分。
     WSAEINPROGRESS：一个阻塞的套接口调用正在运行中。
     WSAEINVAL：level值非法，或optval中的信息非法。
     WSAENETRESET：当SO_KEEPALIVE设置后连接超时。
     WSAENOPROTOOPT：未知或不支持选项。其中，SOCK_STREAM类型的套接口不支持SO_BROADCAST选项，SOCK_DGRAM类型的套接口不支持SO_DONTLINGER 、SO_KEEPALIVE、SO_LINGER和SO_OOBINLINE选项。
     WSAENOTCONN：当设置SO_KEEPALIVE后连接被复位。
     WSAENOTSOCK：描述字不是一个套接口。
     */
    int32_t osl_socket_set_opt(SOCKET skt, int32_t level, int32_t optname, const char* optval, int32_t optlen);
    
    /**
     取得参数
     
     若无错误发生，getsockopt()返回0。否则的话，返回SOCKET_ERROR错误，应用程序可通过WSAGetLastError()获取相应错误代码。
     错误代码：
     WSANOTINITIALISED：在使用此API之前应首先成功地调用WSAStartup()。
     WSAENETDOWN：WINDOWS套接口实现检测到网络子系统失效。
     WSAEFAULT：optlen参数非法。
     WSAEINPROGRESS：一个阻塞的WINDOWS套接口调用正在运行中。
     WSAENOPROTOOPT：未知或不支持选项。其中，SOCK_STREAM类型的套接口不支持SO_BROADCAST选项，SOCK_DGRAM类型的套接口不支持SO_ACCEPTCONN、SO_DONTLINGER 、SO_KEEPALIVE、SO_LINGER和SO_OOBINLINE选项。
     WSAENOTSOCK：描述字不是一个套接口。
     */
    int32_t osl_socket_get_opt(SOCKET skt, int32_t level, int32_t optname, int32_t* optval, int32_t* optlen);
    
    /** 返回socket所绑定的本地地址端口 */
    int32_t osl_socket_get_sockname(SOCKET skt, uint32_t *ip, uint16_t *port);
    
    /**
     发送数据
     
     成功返回发送的字节数，-1：出错，并置错误号errno
     */
    int32_t osl_socket_send(SOCKET skt, void *buf, int32_t size);
    
    /**
     接收数据
     
     成功返回拷贝的字节数，失败返回-1
     */
    int32_t osl_socket_recv(SOCKET skt, void *buf, int32_t size);
    
    /**
     加入多播组, ip必须是组播地址
     
     若无错误发生，setsockopt()返回0。否则的话，返回SOCKET_ERROR错误，应用程序可通过WSAGetLastError()获取相应错误代码。
     错误代码：
     WSANOTINITIALISED：在使用此API之前应首先成功地调用WSAStartup()。
     WSAENETDOWN：套接口实现检测到网络子系统失效。
     WSAEFAULT：optval不是进程地址空间中的一个有效部分。
     WSAEINPROGRESS：一个阻塞的套接口调用正在运行中。
     WSAEINVAL：level值非法，或optval中的信息非法。
     WSAENETRESET：当SO_KEEPALIVE设置后连接超时。
     WSAENOPROTOOPT：未知或不支持选项。其中，SOCK_STREAM类型的套接口不支持SO_BROADCAST选项，SOCK_DGRAM类型的套接口不支持SO_DONTLINGER 、SO_KEEPALIVE、SO_LINGER和SO_OOBINLINE选项。
     WSAENOTCONN：当设置SO_KEEPALIVE后连接被复位。
     WSAENOTSOCK：描述字不是一个套接口。
     */
    int32_t osl_socket_join(SOCKET skt, uint32_t ip);
    
    /**
     退出组播组, ip必须是组播地址
     
     若无错误发生，setsockopt()返回0。否则的话，返回SOCKET_ERROR错误，应用程序可通过WSAGetLastError()获取相应错误代码。
     错误代码：
     WSANOTINITIALISED：在使用此API之前应首先成功地调用WSAStartup()。
     WSAENETDOWN：套接口实现检测到网络子系统失效。
     WSAEFAULT：optval不是进程地址空间中的一个有效部分。
     WSAEINPROGRESS：一个阻塞的套接口调用正在运行中。
     WSAEINVAL：level值非法，或optval中的信息非法。
     WSAENETRESET：当SO_KEEPALIVE设置后连接超时。
     WSAENOPROTOOPT：未知或不支持选项。其中，SOCK_STREAM类型的套接口不支持SO_BROADCAST选项，SOCK_DGRAM类型的套接口不支持SO_DONTLINGER 、SO_KEEPALIVE、SO_LINGER和SO_OOBINLINE选项。
     WSAENOTCONN：当设置SO_KEEPALIVE后连接被复位。
     WSAENOTSOCK：描述字不是一个套接口。
     */
    int32_t osl_socket_drop(SOCKET skt, uint32_t ip);
    
    /**
     发送数据
     
     成功返回发送的字节数，-1：失败
     */
    int32_t osl_socket_sendto(SOCKET skt, uint32_t ip, uint16_t port, void *buf, int32_t size);
    
    /**
     接收数据
     
     成功返回拷贝的字节数，-1：失败
     */
    int32_t osl_socket_recvfrom(SOCKET skt, uint32_t *ip, uint16_t *port, void *buf, int32_t size);
    
    /**
     判断是否为IPv6状态
     */
    int osl_isIPv6OnlyNetwork();

#ifdef __cplusplus
}
#endif

#endif /* osl_socket_h */
