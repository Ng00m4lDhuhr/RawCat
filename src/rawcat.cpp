// Additional source files if needed
#include "rawcat.h"

const char* test(void){ return "Compiling script works"; }

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

bool InterfaceHook(Interface& device, int sockfd)
{
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = device.address;

	if (bind (sockfd, (struct sockaddr *) &addr, sizeof(addr)) < 0)
	{
		std::cerr << "(x) Failed to hook on interface" << device.name << std::endl ;
		return false;
	}
	return true;
}

int InterfaceHook(Interface& device)
{
	int sockfd = socket( AF_INET, SOCK_RAW, IPPROTO_RAW );
	if (sockfd < 0)
	{
		std::cerr << "(x) Failed to create a raw socket" << std::endl;
		return -1;
	}
	if ( InterfaceHook (device, sockfd) ) return sockfd;
	else { close(sockfd); return -1 ;}
}

int capture( BYTE &buffer )
{
	// clear buffer before any modification
	memset(&buffer, 0, sizeof(buffer));
	// TODO a loop to receive data till buffer is consumed
	return sizeof(buffer);
}

bool release(BYTE &buffer){ return false; }
