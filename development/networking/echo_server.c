/*
 * filename: echo_server.c
 */
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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
	 
	// Internet address.
	typedef uint32_t in_addr_t;
	struct in_addr
	  {
	    in_addr_t s_addr;
	  };

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
	
	if (argc != 2) {
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

	
	/* Create a socket descriptor */
	/* /usr/include/sys/socket.h
	 * Create a new socket of type TYPE in domain DOMAIN, using
	   protocol PROTOCOL.  If PROTOCOL is zero, one is chosen automatically.
	   Returns a file descriptor for the new socket, or -1 for errors.

	extern int socket (int __domain, int __type, int __protocol) __THROW; */
	
	if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		return -1;


	/* Set socket FD's option OPTNAME at protocol level LEVEL
	   to *OPTVAL (which is OPTLEN bytes long).
	   Returns 0 on success, -1 for errors. 

	#ifndef __USE_TIME_BITS64
	extern int setsockopt (int __fd, int __level, int __optname,
			       const void *__optval, socklen_t __optlen) __THROW;*/

	/* Eliminates "Address already in use" error from bind */

	int optval = 1;
	if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR,
				(const void *)&optval, sizeof(int)) < 0)
		return -1;
	struct sockaddr_in serveraddr;
	
	/* /usr/include/strings.h 
	 * Set N bytes of S to 0.
	extern void bzero (void *__s, size_t __n) __THROW __nonnull ((1)); */
	
	/* The zero() function erases the data in the n bytes of the memory
	 * starting at the location pointed by the s, by writing zeros (bytes
	 * containing '\0') to that area. */
	bzero((char *)&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons((unsigned short) port);

	/* /usr/include/sys/socket.h
	 * Give the socket FD the local address ADDR (which is LEN bytes long).
	extern int bind (int __fd, __CONST_SOCKADDR_ARG __addr, socklen_t __len)
	     __THROW; */
	if (bind(listenfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0)
		return -1;

	/* Make it a listenening socket ready to acccept connection requests */

	/* Prepare to accept connections on socket FD.
	   N connection requests will be queued before further requests are refused.
	   Returns 0 on success, -1 for errors. 

	extern int listen (int __fd, int __n) __THROW; */
	if (listen (listenfd, 1024) < 0)
		return -1;

	char *hstaddrptr;
	struct hostent *hostptr;

	while (1) {
		clientlen = sizeof (clientaddr);
		
	/* Await a connection on socket FD.
	   When a connection arrives, open a new socket to communicate with it,
	   set *ADDR (which is *ADDR_LEN bytes long) to the address of the connecting
	   peer and *ADDR_LEN to the address's actual length, and return the
	   new socket's descriptor, or -1 for errors.

	   This function is a cancellation point and therefore not marked with
	   __THROW.  
	extern int accept (int __fd, __SOCKADDR_ARG __addr,
			   socklen_t *__restrict __addr_len); */

		if ((connectfd = accept(listenfd, 
				(struct sockaddr *) &clientaddr, 
				clientlen)) < 0) {
			fprintf(stderr, "%s: %s\n", "accept", strerror(connectfd));
			exit(0);
		}

		/* Determine the domain name and IP address of the client */
	/* /usr/include/netdb.h 
	 * Return entry from host data base which address match ADDR with
	   length LEN and type TYPE.

	   This function is a possible cancellation point and therefore not
	   marked with __THROW.  
	extern struct hostent *gethostbyaddr (const void *__addr, __socklen_t __len,
					      int __type); */
		if ((hostptr = gethostbyaddr((const char *)
				&clientaddr.sin_addr.s_addr,
				sizeof(clientaddr), AF_INET)) == NULL) {
			fprintf(stderr, "%s\n", "gethostbyfaddr() error");
			exit(0);
		}
       /* #include <sys/socket.h>
	* #include <netinet/in.h>
	* #include <arpa/inet.h>
	* int inet_aton(const char *cp, struct in_addr *inp); */
		hstaddrptr = inet_ntoa(clientaddr.sin_addr);
		printf("server connected to %s (%s)\n", hostptr-> h_name, hstaddrptr);
		if ( close(connectfd) < 0)
			perror("Close error");
	}

	exit(0);
}
