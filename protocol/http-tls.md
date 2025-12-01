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
