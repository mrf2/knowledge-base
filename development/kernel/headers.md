# Header file contents

## UAPI - User-space API
If referes to kernel headers and definitions that are **exported to user space.**

### Context
 * In the Linux kernel source tree, there is:
```bash
include/uapi
```
This directory contains **headers shared with user-space**, for program like `glibc`, `musl`, etc.
 * During kernel builds or when installing kernel headers (`make headers_install`), the contents of `include/uapi/` (along with architecture-specific `arch/*/include/uapi/`) get installed into:
```bash
/usr/include/linux/
```

### Purpose
The goal of UAPI is to **cleanly separate:**
|Part|Meaning|
|---|---|
|`include/linux/`|Kernel-only internal headers|
|`include/uapi/linux/`|Headers safe for user-space inclusion (used by `libc`, `gcc`, etc.)|

```c 
#if __UAPI_DEF_IN_IPPROTO
#if __UAPI_DEF_IN_ADDR
#if __UAPI_DEF_IP_MREQ
#if __UAPI_DEF_IN_PKTINFO
#if  __UAPI_DEF_SOCKADDR_IN
#if __UAPI_DEF_IN_CLASS
```
 * `#if  __UAPI_DEF_SOCKADDR_IN` - Can be interpreted as: *In UAPI headers, is the definition of `struct sockaddr_in` enabled?*
