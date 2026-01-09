# HTTPS vs HTTP/TLS

This is just branding and convenience

**Internally the protocol stack is still referred to as:**
 * HTTP over TLS
 * HTTP/TLS (RFC naming)
 * TLS 1.2/1.3 handshake
 * TLS record protocol

***But to users, "HTTPS" is easier.

## Are HTTP and TLS similar?
***NO. They are not similar in purpose, design, or layer.***

### HTTP:
 * Application layer
 * Stateless request-response
 * Define methods: **`GET, POST, PUT, DELETE**, etcv.
 * Data format: headers + body

### TLS:
 * Cyrptographic layer
 * Sits **between** application and TCP
 * Provides:
   * Encryption
   * Authentication (server certificate)
   * Integrity (MAC)
   * Key exchange
 * Does **not** define URLs, methods, content-type, routing, etc.

## We cannot "see raw HTTPS messages"
**There is no such thing as "raw HTTPS messages" we can type by hand.**

### Why?
Because:
 * HTTPS = HTTP **inside** TLS
 * TLS encrypts everything **after handshake**
 * HTTP headers and body are:
   * encrypted
   * integrity-protected
   * opaque on the wire

So after TLS completes:
```bash
[encrypted bytes]
```
We cannot type:
```bash
GET / HTTP/1.1
```
and expect the server to understand it - unless the TLS layer encrypts it correctly.

We can think of TLS as a **secure wrapper**.
We can run **any protocol** over TLS, not only HTTP:
```
SMTP/TLS
IMAP/TLS
FTP/TLS
LDAP/TLS
MQTT/TLS
DNS-over-TLS
```
