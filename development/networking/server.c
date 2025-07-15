#include <stdio.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUF_SIZE 500

int
main (int argc, char **argv)
{
	int			sockfd, s;
	char			buf[BUF_SIZE];
	ssize_t			nread;
	socklen_t		peer_addrlen;
	struct addrinfo		hints;
	struct addrinfo		*result, *resptr;
	struct sockaddr_storage	peer_addr;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s port\n", argv[0]);
		exit (EXIT_FAILURE);
	}

	memset(&hints, 0, sizeof (hints));
	hints.ai_family = AF_UNSPEC;		/* Allow IPv4 or IPv6 */
	hints.ai_socktype = SOCK_DGRAM;		/* Datagram socket */
	hints.ai_flags = AI_PASSIVE;		/* For wildcard IP address */
	hints.ai_protocol = 0;			/* Any protocol */
	hints.ai_canonname = NULL;
	hints.ai_addr = NULL;
	hints.ai_next = NULL;

	s = getaddrinfo (NULL, argv[1], &hints, &result);
	if (s != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
		exit (EXIT_FAILURE);
	}

	/* getaddrinfo() returns a list of address structures.
	 * Try each address until we succefully bind (2).
	 * If socket (2) (or bind(2)) fails, we (close the socket 
	 * and) try the next address. */

	for (resptr = result; resptr != NULL; resptr = resptr->ai_next) {
// int socket (int domain, int type, int protocol)
		sockfd = socket (resptr->ai_family, resptr->ai_socktype, 
				resptr->ai_protocol);
		if (sockfd == -1)
			continue;
// int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
		if (bind(sockfd, resptr->ai_addr, resptr->ai_addrlen) == 0)
			break;			/* Success */

		close (sockfd);
	}

	freeaddrinfo(result);			/* No longer needed */

	if (resptr == NULL) {			/* No address succedded */
		fprintf(stderr, "Could not bind\n");
		exit (EXIT_FAILURE);
	}

	/* Read datagrams and echo them back to sender. */
	for (;;) {
		char host[NI_MAXHOST], service[NI_MAXSERV];

		peer_addrlen = sizeof (peer_addr);
// ssize_t recv(int sockfd, void buf[.len], size_t len, int flags);
// ssize_t recvfrom(int sockfd, void buf[restrict .len], size_t len, int flags,
// 		struct sockaddr *_Nullable restrict src_addr,
// 		socklen_t *_Nullable restrict addrlen);
// ssize_t recvmsg(int sockfd, struct msghdr *msg, int flags);
		nread = recvfrom(sockfd, buf, BUF_SIZE, 0,
				(struct sockaddr *) &peer_addr, &peer_addrlen);

		if (nread == -1)
			continue;		/* Ignore failed request */
/* int getnameinfo(const struct sockaddr *restrict addr, socklen_t addrlen,
		char host[_Nullable restrict .hostlen],
		socklen_t hostlen
		s = getnameinfo((struct sockaddr *) &peer_addr,
				peer_addrlen, host, NI_MAXHOST,
				service, NI_MAXSERV, NI_NUMERICSERV);
*/
		s = getnameinfo((struct sockaddr *) &peer_addr,
				peer_addrlen, host, NI_MAXHOST,
				service, NI_MAXSERV, NI_NUMERICSERV);
		if (s == 0)
			printf("Received %zd bytes from %s:%s\n", nread, host, service);
		else
			fprintf(stderr, "getnameinfo: %s\n", gai_strerror(s));

		if (sendto (sockfd, buf, nread, 0, (struct sockaddr *) &peer_addr,
					peer_addrlen) != nread)
		{
			fprintf(stderr, "Error sending response\n");
		}
	}
}


