# nc (or netcat) - arbitrary TCP and UDP connections and listens

The **nc** or **netcat** utility is used for just about anything under the sun involving TCP, UDP, or Unix-domain sockets. It can open TCP connections, send UDP packets, listen or arbitrary TCP and UDP ports, do port sccanning, and deal with both IPv4 and IPv6. Unline telnet, **nc** scripts nicely, and separates error messages onto standard error instead of sending them to standard output, as telnet does with some. *Source: nc manpage*

## nc (or netcat) as reverse shell
```bash
nc -lvnp <listening port>

example:
nc -lvnp 4444
```
