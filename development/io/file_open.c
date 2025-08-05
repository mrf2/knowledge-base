#include <fcntl.h>

int main()
{
	int fd = open("dev/ttyS0", O_RDWR);
	char buf[128];
	read(fd, buf, 128);

	printf("%s\n", buf);

	return 0;
}
