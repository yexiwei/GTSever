#ifndef  GT_DEFINITION_
#define  GT_DEFINITION_

#ifndef WIN32_LEAN_AND_MEAN         // The declarations in the Winsock.h header file will conflict with the declarations in the Winsock2.h header file required by Windows Sockets 2.0. The WIN32_LEAN_AND_MEAN macro prevents the Winsock.h from being included by the Windows.h header. An example illustrating this is shown below.
#define WIN32_LEAN_AND_MEAN         // https://msdn.microsoft.com/en-us/library/windows/desktop/ms737629(v=vs.85).aspx
#endif

#ifndef FD_SETSIZE
#define FD_SETSIZE  1048   /* native select have the 64 limited */
#endif

#include <windows.h>
#include <winsock2.h>


/* GT Select Event type */
enum EVENT_TYPE {		
	EVENT_READ = 0,
	EVENT_WRITE = 1,
	EVENT_EXCEPTION = 2,
	EVENT_ACCEPT = EVENT_READ
};


/* this idea is from libevent */
struct fd_set_pri {
    unsigned int sock_count;
    SOCKET fd_sock_array[1];
};


typedef void(*gt_event_callback)(PULONG_PTR fd, const char* data, int len);

#endif //  GT_DEFINITION_
