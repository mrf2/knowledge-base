# nm - list symbols from object files

## check if any function exist in `libc.so.6`
```bash
# checking "socket" function
nm -D /lib/x86_64-linux-gnu/libc.so.6 | grep socket

# checking "printf" function
nm -D /lib/x86_64-linux-gnu/libc.so.6 | grep printf
```
