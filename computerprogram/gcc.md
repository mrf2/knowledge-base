# `gcc` - The GNU Compiler Collection

## Examples
 * Compling without standard C library `libc`
```bash
gcc -nostdlib -static -o raw_send raw_send.c
```
 * `-nostdlib` - Do not use the standard libraries when linking
 * `-static` - Link statically - include all libraries in the final binary. 

## Deep Study
|Concept|Description|
|---|---|
|`-nostartfiles`|Use this if skip only startup file (e.g., `crt.o`) but still link libc|
|`ld` and linker script|Used to control memory layout in raw binaries|
|`_start`|Default entry point when no runtime is used|
|System calls|Must be used in place of standard C library calls|
|Static vs dynamic linking|Understand ELF headers and how *glibc* is loaded|
|`strace`|Useful to observe **syscalls** used by the binary|
