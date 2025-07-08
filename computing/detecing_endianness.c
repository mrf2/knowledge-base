#include <stdio.h>
#include <stdint.h>

int main(void)
{
	unsigned int num = 0x1;
	char *c = (char *)&num;
	
	if (*c)
		printf("Little-Endian\n");
	else
		printf("Big-Endian\n");

	uint32_t x = 0x12345678;		// 32-bit integer
	printf("Value: 0x%x\n", x);
	
	return 0;
}

