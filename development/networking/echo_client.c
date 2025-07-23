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

