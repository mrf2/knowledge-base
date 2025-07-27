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

	/* Now fill the server's IP address and port. */
       /* int socket(int domain, int type, int protocol); */

	if ((clientfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		return -1;	/* Check error for cause of error */
       /* [[deprecated]] struct hostent *gethostbyname(const char *name); */
	if ((hp = gethostbyname(host)) == NULL)
		return -2;	/* Check h_error for cause of error */
       /* void bzero(void s[.n], size_t n); */
	bzero((char *)&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;	/* Address Family: Internet */
       /* [[deprecated]] void bcopy(const void src[.n], void dest[.n], size_t n); */
	/* char **h_addr_list;		// List of addresses from name server.	*/
	bcopy((char *)hp->h_addr_list[0], (char *)&serveraddr.sin_addr.s_addr,
			hp->h_length);
	serveraddr.port = htons(port);

	/* Establish a connection with the server */
       /* int connect(int sockfd, const struct sockaddr *addr,
		   socklen_t addrlen); */




//	clientfd = 

