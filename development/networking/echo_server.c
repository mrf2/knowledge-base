/*
 * filename: echo_server.c
 */
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int listenfd;
	int connectfd;
	int port;
	int clientlen;

	/* /usr/include/bits/sockaddr.h
	  POSIX.1g specifies this type name for the `sa_family' member.

	  typedef unsigned short int sa_family_t;
	 
	 #define __SOCKADDR_COMMON(sa_prefix) \
	   sa_family_t sa_prefix##family
	*/

	/* /usr/include/netinet/in.h
	 struct sockaddr_in
	  {
	    __SOCKADDR_COMMON (sin_);
	    in_port_t sin_port;			// Port number.	 
	    struct in_addr sin_addr;		// Internet address.  

	    // Pad to size of `struct sockaddr'.  
	    unsigned char sin_zero[sizeof (struct sockaddr)
				   - __SOCKADDR_COMMON_SIZE
				   - sizeof (in_port_t)
				   - sizeof (struct in_addr)];
	  };*/

	struct sockaddr_in clientaddr;
	
	/* /usr/include/netdb.h
	struct hostent
	{
	  char *h_name;			// Official name of host.  
	  char **h_aliases;		// Alias list.	
	  int h_addrtype;		// Host address type.  
	  int h_length;			// Length of address.  
	  char **h_addr_list;		// List of addresses from name server.	
	#ifdef __USE_MISC
	# define	h_addr	h_addr_list[0] // Address, for backward compatibility.
	#endif
	}; */
	
	struct hostent *hostptr;
	char *hstaddrptr;
	if (agrc != 2) {
       /* <stdio.h>
	* int fprintf(FILE *restrict stream,
		   const char *restrict format, ...); */
		fprintf(stderr, "usage: %s <port>\n", argv[0]);
       /* <stdlib.h>
	* [[noreturn]] void exit(int status);*/
		exit(0);
	}
       /* <stdlib.h>
	* int atoi(const char *nptr); */
	port = atoi(argv[1]);

	int optval = 1;
	

	// listenfd = 
