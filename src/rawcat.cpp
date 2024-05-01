// Additional source files if needed
#include "rawcat.h"

const char* test(void){ return "(+) Compiling script works"; }

struct Interface
{
	char name[16]; // in Linux an interface name size is 15 characters
	unsigned long address = 0; // 4 bytes IP address (IPv4)
	
	// constructors
	Interface ( char* InterfaceName, char* InterfaceAddress ) 
	{ 
		strcpy(name, InterfaceName); 
		address = inet_addr(InterfaceAddress); 
	}
	Interface ( char* InterfaceName, unsigned long InterfaceAddress ) 
	{ 
		strcpy(name, InterfaceName); 
		address = InterfaceAddress; 
	}
	Interface ( unsigned long InterfaceAddress ) { address = InterfaceAddress; }
	Interface ( char* InterfaceAddress ) { address = inet_addr(InterfaceAddress); }
	Interface ( void ) { memset( this, 0 , sizeof(*this) ); }
};

bool InterfaceHook ( Interface& device, int sockfd )
{
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = device.address;

	if ( // bind the socket to a specific IP address and Interface
		setsockopt( sockfd, SOL_SOCKET, SO_BINDTODEVICE, device.name, strlen(device.name) ) < 0 
	){	// dependency fail condition	
		std::cerr	<<	"(x) Failed to hook on interface"
					<<	device.name << std::endl ;
		return false;
	}
	return true;
}

int InterfaceHook ( Interface& device )
{
	int sockfd = socket( AF_INET, SOCK_RAW, IPPROTO_RAW );
	if (sockfd < 0)
	{	// Failure condition
		std::cerr	<<	"(x) Failed to create a raw socket" 
					<<	std::endl;
		return sockfd;
	}
	if ( InterfaceHook (device, sockfd) ) return sockfd;
	else { close(sockfd); return -1 ;}
}

// captures an IP packet from a device 
// into the said buffer and return it's size
int capture ( Interface device, void* buffer, size_t size)
{	// clear buffer before any modification
	memset( buffer, 0, size );
	// TODO read from a raw socket into buffer
	return 1;
}

// captures N size bytes from X interface
void* capture ( Interface device, size_t size )
{	// create a memory buffer and return it	
	void* buffer = malloc(size);
	capture(device, buffer, size);
	return buffer;
}

