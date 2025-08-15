/*
 * filename: iot.h
 */

#ifndef __IOT_H__
#define __IOT_H__
/* Application can transfer data directly between memory and a file by calling
 * iot_nread and iot_nwrite functions. */

ssize_t iot_nread(int fd, void *databuffer, size_t n);
#endif
