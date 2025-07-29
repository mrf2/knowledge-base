/*
 * filename: echo_client.c 
 * compile (with debugging info): gcc -g -o echo_client echo_client.c
 * run: ./echo_client
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>

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
	if ((hostptr = gethostbyname(host)) == NULL)
		return -2;	/* Check h_error for cause of error */
       /* void bzero(void s[.n], size_t n); */
	bzero((char *)&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;	/* Address Family: Internet */
       /* [[deprecated]] void bcopy(const void src[.n], void dest[.n], size_t n); */
	/* char **h_addr_list;		// List of addresses from name server.	*/
	bcopy((char *)hostptr->h_addr_list[0], (char *)&serveraddr.sin_addr.s_addr,
			hostptr->h_length);
	serveraddr.sin_port = htons(port);

	/* Establish a connection with the server */
       /* int connect(int sockfd, const struct sockaddr *addr,
		   socklen_t addrlen); */
	
	if (connect(clientfd, (struct sockaddr *)&serveraddr, 
			sizeof(serveraddr)) < 0)
		return -1;
	/*
	#define RIO_BUFSIZE 8192
	typedef struct {
	    int rio_fd;                // descriptor for this internal buf 
	    int rio_cnt;               // unread bytes in internal buf 
	    char *rio_bufptr;          // next unread byte in internal buf 
	    char rio_buf[RIO_BUFSIZE]; // internal buffer 
	} rio_t; */

	int nread;
	char RBUF[1023];
	/*
       ssize_t recv(int sockfd, void buf[.len], size_t len,
			int flags);*/

/*	 if ((nread = read(clientfd, RBUF, 1023) < 0)
		perror("error");
	if ((nread = recv(clientfd, RBUF, 1023, 0)) < 0)
		perror("read socket");
	printf("%s", RBUF); */
	while (recv(clientfd, RBUF, 1023, 0) != NULL) {
		printf("%s\n", RBUF);
		send(clientfd, RBUF, strlen(RBUF), 0);	
	}
		

	close(clientfd);

	return 0;
}


