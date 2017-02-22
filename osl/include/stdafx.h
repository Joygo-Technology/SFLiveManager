#ifndef __STDAFX_H__
#define __STDAFX_H__

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdarg.h>
#include <ctype.h>
#include <assert.h>

#define PRINTF printf
#define IPHONE 1


#ifdef WIN32
    //#define VC_EXTRALEAN
    // Exclude rarely-used stuff from Windows headers

	#define _WIN32_WINNT 0x0501
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <conio.h>
	#include <Winsock2.h>
	#include <ws2tcpip.h>
	#include <io.h>
	#include <errno.h>
	#include <Iphlpapi.h>

	#pragma comment( lib, "Ws2_32.lib" )
	#pragma comment( lib, "Iphlpapi.lib" )

	typedef unsigned char bool_t;
	typedef char int8_t;
	typedef unsigned char uint8_t;
	typedef unsigned char uchar_t;
	typedef char char_t;
	typedef unsigned int uint32_t;
	typedef unsigned short uint16_t;
	typedef unsigned __int64 uint64_t;
	typedef short int16_t;
	typedef int int32_t;
	typedef __int64 int64_t;

	#ifdef WIN64
		#define	PSTRING	LPCWSTR
	#else
		#define	PSTRING	LPCSTR
	#endif

#elif IPHONE
    /* IPHONE */

    #ifndef __USE_GNU
    #define __USE_GNU
    #endif
    #include <string.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <sched.h>
    #include <ctype.h>
    #include <pthread.h>
    #include <semaphore.h>
    #include <errno.h>
    #include <inttypes.h>
    #include <signal.h>
    #include <fcntl.h>
    #include <getopt.h>
    #include <termios.h>
    #include <netdb.h>
    #include <stdint.h>
    #include <arpa/inet.h>

    #include <netinet/in.h>
    #include <netinet/ip.h>
    //#include <netinet/udp.h>
    #include <netinet/tcp.h>

    #include <net/if.h>
    //#include <net/if_arp.h>

    #include <sys/socket.h>
    #include <sys/stat.h>
    #include <sys/ioctl.h>
    #include <sys/param.h>
    #include <sys/types.h>
    #include <sys/timeb.h>
    #include <sys/time.h>
    //#include <sys/reboot.h>
    #include <sys/mount.h>
    #include <dlfcn.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <errno.h>
    //#include <linux/if_packet.h>
    #include <sys/mman.h>
    //#include <linux/fb.h>
    //#include <linux/ethtool.h>
    #include <sys/sockio.h>
    //#include <linux/prctl.h>
    #define IS_MULTICAST_IP(ip) ( 0xE0<=(ip&0xFF) && (ip&0xFF)<0xF0 )
    typedef unsigned char bool_t;
    typedef unsigned char uchar_t;
    typedef char char_t;
    //typedef int64_t SOCKET;
    #undef SOCKET
    typedef int64_t SOCKET;
    #define INVALID_SOCKET (-1)
#define LOGE printf
#define LOGI printf
#define LOGD printf
#define LOGW printf

#else
	/* LINUX */
	#include<unistd.h>
	#ifndef __USE_GNU
	#define __USE_GNU 
	#endif
	#include<sched.h> 
	#include<ctype.h> 
	#include <pthread.h>
	#include <semaphore.h>
	#include <errno.h>
	#include <inttypes.h>
	#include <signal.h>
	#include <fcntl.h>
	#include <getopt.h>
	#include <termios.h>
	#include <errno.h>
	#include <netdb.h>
	#include <stdint.h>
	#include <arpa/inet.h>
		
	#include <netinet/in.h>
	#include <netinet/ip.h>
	#include <netinet/udp.h>
	#include <netinet/tcp.h>
		
	#include <net/if.h> 
	#include <net/if_arp.h> 
		
	#include <sys/socket.h>
	#include <sys/stat.h>
	#include <sys/ioctl.h>
	#include <sys/param.h> 
	#include <sys/types.h>
	#include <sys/timeb.h>
	#include <sys/time.h>
	#include <sys/reboot.h>
	#include <sys/mount.h>
	#include <dlfcn.h>
	#include <linux/reboot.h>
	#include <linux/if_ether.h>
	#include <string.h>
	#include <unistd.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <arpa/inet.h>
	#include <sys/types.h>
	#include <sys/wait.h>
	#include <errno.h>
	#include <linux/if_packet.h>
	#include <sys/mman.h>
	#include <linux/fb.h>
	//#include <linux/ethtool.h>
	#include <linux/sockios.h>
	#include <linux/prctl.h>
	#define IS_MULTICAST_IP(ip) ( 0xE0<=(ip&0xFF) && (ip&0xFF)<0xF0 )	
	typedef unsigned char bool_t;
	typedef unsigned char uchar_t;
	typedef char char_t;
	//typedef int64_t SOCKET;
	#undef SOCKET
	typedef unsigned int SOCKET;
	#define INVALID_SOCKET -1
#endif

#ifndef __cplusplus
	#ifndef bool
	#define bool uint8_t
	#endif	

	#ifndef true
	#define true 1
	#endif	

	#ifndef false
	#define false 0
	#endif 
#endif /* __cplusplus */


#endif /* __STDAFX_H__ */
