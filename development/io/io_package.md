# I/O Package
We will develop an I/O package IOT (I/O Type Package), that handles
short counts automatically. Is is intended to use for Network application
program. The IOTP provides two different kinds of functions:

 * **Unbuffered input and output functions:** These functions transfer data
directly between memory and a file, with no application-level buffering. And, 
they are useful for reading and writing binary data to and from networks.

 * **Buffered input function:** These functions are for reading text lines and
binary data from a file whose contents are cached in an application-level buffer.

## `IOT` Unbuffered Input and Output Functions
```c
/* Application can transfer data directly between memory and a file by calling
 * iot_nread and iot_nwrite functions.
 * Returns: number of bytes transferred if OK, 0 on EOF (iot_nread only),
 * -1 on error
 * */

ssize_t iot_nread(int fd, void *databuffer, size_t n);
ssize_t iot_nwrite(int fd, void *databuffer, size_t n);
```
