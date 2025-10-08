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

## General Rule
 * **User-space program (like `socket()` or `open()`) only need user-space headers**, which live in `/usr/include` and come from:
   * `glic` (e.g., `stdio.h`, `unistd.h`, `netinet/in.h`)
   * POSIX or other libraries (e.g., `pthread`, `zlib`, etc.)
 * **Kernel headers** *(not full kernel source)* are needed only when:
   * Writing **kernel modules** or **device drivers**
   * Interfacing directly with **kernel ABI-level structures**
   * Using **low-level system programming**, e.g., `ioctl`, `netlink`

## Kernel Header vs Library Header
|Feature|Kernel Header|glibc/Library Header|
|---|---|---|
|Location|`/usr/src/linux/`, `/lib/modules/*/build/include/`, or `/usr/include/linux/` from (`linux-libc-dev`)|`/usr/include/`, `/usr/include/bits/`, `/usr/include/glibc/`|
|Purpose|Defines kernel structs and constants (e.g., `task_struct`, `sockaddr_in`, `ioctl` codes|Provides user-facing interfaces *(standard headers, POSIX types, library functions)*|
|Installed via|Kernel source or `linux-headers-*` packages|glibc or other library packages|
|File characteristics|Often begins with `#ifdef __KERNEL__` or uses `__u32`, `__user` types|Uses standard types like `int`, `size_t`, `sockaddr`|


## Identify Source
To see where a header is from:
```bash
dpkg -S /usr/include/netinet/in.h
```
Which will give us:
```bash
libc6-dev:amd64: /usr/include/netinet/in.h
```
Or for kernel headers:
```bash
dpkg -S /usr/include/linux/in.h
```
Gives us:
```bash
linux-libc-dev:amd64: /usr/include/linux/in.h
```


```c 
#if __UAPI_DEF_IN_IPPROTO
#if __UAPI_DEF_IN_ADDR
#if __UAPI_DEF_IP_MREQ
#if __UAPI_DEF_IN_PKTINFO
#if  __UAPI_DEF_SOCKADDR_IN
#if __UAPI_DEF_IN_CLASS
```
#### `#if  __UAPI_DEF_SOCKADDR_IN`
The macro can be interpreted as: *In UAPI headers, is the definition of `struct sockaddr_in` enabled?*
 * Uses Cases: In kernel headers like:
```c
#ifdef _UAPI_DEF_SOCKADDR_IN

struct sockaddr_in {
    ...
};
#endif
```

**This means:**
 * If `_UAPI_DEF_SOCKADDR_IN` is define to `1`, the kernel **lets userspace see** the struct definition.
 * If defined to 0, then **glibc must defined it instead** *(to maintain backword compatibility)*.
