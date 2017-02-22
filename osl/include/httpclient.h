#ifndef __ARS_HTTPCLIENT_H__
#define __ARS_HTTPCLIENT_H__

#ifdef __cplusplus
extern "C"
{
#endif
    
#if 0
/***********************************************************************************************
* CONTENT: 与Http服务器建立连接
* PARAM:
	[in] ip: http服务器地址
	[in] port: http服务器端口
* RETURN:
	还回连接成功后的句柄
* NOTE:
************************************************************************************************/
void* ars_httpclient_connect( unsigned int ip, unsigned short port, int timeout );

/***********************************************************************************************
* CONTENT: 断开与Http服务器建立的连接
* PARAM: 要断开的套接字  
* RETURN:
	连接服务器是否成功
* NOTE:
************************************************************************************************/
void ars_httpclient_disconnect( void* hHttpclient );

/***********************************************************************************************
* CONTENT: 发送HTTP Request
* PARAM:
	[in] hHttpclient:建立连接后的句柄 
	[in] pMethod: 请求方式
	[in] pURL:请求的URL
	[in] pHost:主机名称
	[in] pAcceptType:接收的文件类型
	[in] pContentType:post 的内容类型
	[in] pContent:post 的内容
	[in] nLength: post 内容长度
* RETURN:
	请求是否发送成功
* NOTE:
************************************************************************************************/
int ars_httpclient_send_data( void* hHttpclient, char* sendbuf, int sendsize, int timeout );

/***********************************************************************************************
* CONTENT: 接收HTTP数据
* PARAM:
	[in]  hHttpclient:建立连接后的句柄
	[in] pBuf:接收缓冲区
	[in] pHost:缓冲区大小
	[in] timeout:接收超时
* RETURN:
	接收到的数据长度
* NOTE:
************************************************************************************************/
int ars_httpclient_recv_data( void* hHttpclient, char* recvbuf, int recvsize, int timeout );

#endif
    
#ifdef __cplusplus
}
#endif

#endif /* __ARS_HTTPCLIENT_H__ */

