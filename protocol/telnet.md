# Telnet

## What `telnet` CAN do
 * Open a **raw TCP connection**
 * Let us manually type HTTP text

So this works:
```bash
telnet example.com 80
```
Then type:
```bash
GET / HTTP/1.1
Host: example.com
```
We will see:
 * serever response
 * status line (`HTTP/1.1 200 OK`)
 * headers
## Benefits of telnet (HTTP knowledge)
 * request line syntax
 * header behavior
 * server HTTP/1.x support

## What `telnet` CANNOT do
 * TLS
 * HTTPS
 * ALPN
 * HTTP/2 or HTTP/3
So:
> `telnet` **is enough ONLY for plain HTTP/1.x**

## Connecting to Telnet
```bash
Syntax
telnet <ip_address> <port_number>
```
**Getting 200-OK reponse from localhost**
1. **Open Telnet:**
```bash
telnet localhost 80
```
2. **Then type (and press Enter after each line):**
```bash
GET / HTTP/1.1
Host: localhost
```

