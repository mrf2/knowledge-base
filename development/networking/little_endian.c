#include <stdio.h>
#include <arpa/inet.h>

int main()
{
	struct in_addr ip;
	inet_aton("192.168.10.91", &ip);

	unsigned char *bytes = (unsigned char *) &ip.s_addr;
	printf("Stored bytes: %u.%u.%u.%u\n", bytes[0], bytes[1], bytes[2], bytes[3]);

	printf("Stored bytes: %x.%x.%x.%x\n", bytes[0], bytes[1], bytes[2], bytes[3]);
	return 0;
}

