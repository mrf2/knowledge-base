/*
 * big_endian_hex2_dot_decimal
 * This program will Converts is hex argument to a dotted-decimal string and print the result
 * Example use: ./ebig_endian_hex2_dot_decimal 128.2.194.242
 * 0x8002c2f2
 */

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
	int a, b, c, d;
	unsigned int ipaddr;
	unsigned int ipaddr2;
	if (argc != 2) {
 		printf("use: ./ebig_endian_hex2_dot_decimal 128.2.194.242\n");
	       // printf("argv[0] = %s\n", argv[0]);
	       // printf("argv[1] = %s\n", argv[1]);
	       exit(1);
	}

	sscanf(argv[1], "%d.%d.%d.%d", &a, &b, &c, &d);
	printf("a = %d\nb = %d\nc = %d\nd = %d\n", a, b, c, d);	

	unsigned char *ptr = (unsigned char *) &ipaddr;
	/*
	 * little-endian
	*ptr = a;
	*(ptr+1) = b;
	*(ptr+2) = c;
	*(ptr+3) = d;
	*/
	

	/* big-endian */
	*ptr = d;
	*(ptr+1) = c;
	*(ptr+2) = b;
	*(ptr+3) = a;

	ipaddr2 = (a << 24) | (b << 16) | (c << 8) | d;

	printf("0x%x\n", ipaddr);
	// printf("0x%02x%02x%02x%02x\n", *ptr, *(ptr+1), *(ptr+2), *(ptr+3));
	printf("Byte hex format for ipaddr: 0x%x\n", ipaddr);
	printf("Byte hex format for ipaddr2: 0x%x\n", ipaddr2);


	return 0;
}

