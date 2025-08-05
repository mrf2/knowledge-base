#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd = open("test.txt", O_RDWR);
	char buf[128];
	read(fd, buf, 128);

	printf("%s\n", buf);

	return 0;
}
