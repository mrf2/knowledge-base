#include <stdio.h>

int main(void)
{
	unsigned int num = 0x1;
	char *c = (char *)&num;
	
	if (*c)
		printf("Little-Endian\n");
	else
		printf("Big-Endian\n");
	
	return 0;
}

