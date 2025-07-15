#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

#define BUF_SIZE 500

int
main(int argc, char **argv)
{
	int			sockfd, status;
	char			buf[BUF_SIZE];
	size_t			len;
	ssize_t			nread;
	struct addrinfo		hints;
	struct addrinfo		*result, *resptr;

	if (argc < 3) {
		fprintf(stderr, "Usage: %s host port msg...\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	/* Obtain address(es) maching host/port. */
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;		/* Allow IPv4 or IPv6 */
	hints.ai_socktype = SOCK_DGRAM;		/* Datagram socket */
	hints.ai_flags = 0;
	hints.ai_protocol = 0;			/* Any protocol */

	status = getaddrinfo(argv[1], argv[2], &hints, &result);
	if (status != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
		exit (EXIT_FAILURE);
	}

	/* getaddrinfo() returns a list of address structures.
	 * Try each address until we succefully connect(2).
	 * If socket(2) (or connect(2)) fails, we (close the socket 
	 * and) try next address. */
	for (resptr = result; resptr != NULL; resptr = resptr->ai_next) {
		/* int socket(int domain, int type, int protocol); */
		sockfd = socket(resptr->ai_family, resptr->ai_socktype,
				resptr->ai_protocol);
		if (sockfd == -1)
			continue;
/*
 *
	   struct addrinfo {
	       int		ai_flags;
	       int		ai_family;
	       int		ai_socktype;
	       int		ai_protocol;
	       socklen_t	ai_addrlen;
	       struct sockaddr *ai_addr;
	       char	       *ai_canonname;
	       struct addrinfo *ai_next;
	   };
*/
    	/* int connect(int sockfd, const struct sockaddr *addr, socklet_t addrlen); */
		if (connect(sockfd, resptr->ai_addr, resptr->ai_addrlen) != -1)
			break;			/* Success */

		close (sockfd);
	}

	freeaddrinfo(result);			/* No longer needed */

	if (resptr == NULL) {			/* No address succedded */
		fprintf(stderr, "Could not connect\n");
		exit(EXIT_FAILURE);
	}

	/* send remaining command-line argument as separate
	 * datagrams, and read responses from server. */
	
	for (size_t j = 3; j < argc; j++) {
		len = strlen(argv[j]) + 1;	/* +1 for terminating null byte */

		if (len > BUF_SIZE) {
			fprintf(stderr, "Ignoring long message in argument %zu\n", j);
			continue;
		}
/* ssize_t write(int fd, const void buf[.count], size_t count); */
		if (write(sockfd, argv[j], len) != len) {
			fprintf(stderr, "partial/failed written\n");
			exit(EXIT_FAILURE);
		}
/* ssize_t read(int fd, void buf[.count], size_t count); */
		nread = read(sockfd, buf, BUF_SIZE);
		if (nread == -1) {
			perror("read");
			exit(EXIT_FAILURE);
		}

		printf("Received %zd bytes: %s\n", nread, buf);
	}

	exit(EXIT_SUCCESS);
}
