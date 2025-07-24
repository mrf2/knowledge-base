/*
 * filename: echo_client.c 
 * compile (with debugging info): gcc -g -o echo_client echo_client.c
 * run: ./echo_client
 */
#include <stdio.h>
#include <stdlib.h>

#define	MAXLINE	 8192  /* Max text line length */

int main(int argc, char **argv)
{
	int clientfd, port;
	char *host;
	char buf[MAXLINE];

	/* Description of data base entry for a single host.
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
	
	/* Structure describing an Internet (IP) socket address. 
	#if  __UAPI_DEF_SOCKADDR_IN
	#define __SOCK_SIZE__	16		// sizeof(struct sockaddr)	
	struct sockaddr_in {
	  __kernel_sa_family_t	sin_family;	// Address family		
	  __be16		sin_port;	// Port number			
	  struct in_addr	sin_addr;	// Internet address		

	  // Pad to size of `struct sockaddr'. 
	  unsigned char		__pad[__SOCK_SIZE__ - sizeof(short int) -
				sizeof(unsigned short int) - sizeof(struct in_addr)];
	};
	#define sin_zero	__pad		// for BSD UNIX comp. -FvK	
	#endif */

	struct sockaddr_in serveraddr;


       /* int fprintf(FILE *restrict stream,
		   const char *restrict format, ...); */
	if (argc != 3) {
		fprintf(stderr, "usage: %s <host> <port>\n", argv[0]);
		
       /* [[noreturn]] void exit(int status); */
		exit(0);
	}

	host = argv[1];
	
       /* int atoi(const char *nptr); */
	port = atoi(argv[2]);

	clientfd = 

