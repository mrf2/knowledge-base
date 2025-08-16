/*
 * filename: iot.h
 */

#ifndef __IOT_H__
#define __IOT_H__
#define size_t unsigned long
#define ssize_t long
/* Application can transfer data directly between memory and a file by calling
 * iot_nread and iot_nwrite functions.
 * Returns: number of bytes transferred if OK, 0 on EOF (iot_nread only),
 * -1 on error
 * */

ssize_t iot_nread(int fd, void *databuffer, size_t n);
ssize_t iot_nwrite(int fd, void *databuffer, size_t n);
#endif
