//
//  fw_socket.h
//  SocketServer
//
//  Created by Sunniwell on 2016/10/19.
//  Copyright © 2016年 FunWay. All rights reserved.
//

#ifndef osl_gcd_socket_h
#define osl_gcd_socket_h

#ifdef __cplusplus
extern "C"
{
#endif
    
    /**
     创建socket
     */
    SOCKET osl_gcd_socket_create();
    
    /**
     连接socket
     
     @param sock socket
     @param host 主机（域名或IP地址）
     @param port 端口号
     
     @return 连接是否成功
     */
    int osl_gcd_socket_connect(SOCKET sock, char *host, int32_t port);
    
    /**
     发送数据
     
     @param sock   socket
     @param data   要发送的数据
     @param length 发送的数据的长度
     
     @return 已发送的数据长度
     */
    int osl_gcd_socket_send(SOCKET sock, unsigned char *data, int32_t length);
    
    /**
     接收数据
     
     @param sock   socket
     @param buf    接收的缓冲信息
     @param length 接收的长度
     
     @return 已接收的数据长度
     */
    int osl_gcd_socket_recive(SOCKET sock, unsigned char *buf, int32_t length);
    
    
    /**
     socket的状态
     
     @return 0：可用，-1：出错
     */
    int osl_gcd_socket_state();
    
    /**
     socket连接的状态
     
     @return 0：成功，1：等待，-1：错误，应关闭
     */
    int osl_gcd_socket_get_connect_state(SOCKET sock);
    
    /**
     销毁socket
     
     @param sock socket
     */
    void osl_gcd_socket_destroy(SOCKET sock);
    
    /**
     判断是否为IPv6状态
     */
    int osl_gcd_isIPv6OnlyNetwork();
    
#ifdef __cplusplus
}
#endif

#endif /* osl_gcd_socket_h */
