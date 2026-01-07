# HTTP versioning
 1. **Who is responsible for HTTP versioning?
 2. **Does the client request a version, or does the server decide?
 3. **From the command line, is `telnet` enough, or do I need `openssl s_client`?

## 1. Who is responsible for HTTP versioning?
**HTTP versioning is a shared responsibility between the client and the server, but the mechanism differes by transport (plain TCP vs TLS)

 * There is **no central authority at runtime.**
 * No negotiation daemon.
 * No "HTTP controller".

Only **protocol rules + implementation capabilites**

## 2. How version selection actually works
We must split this into **two cases**, because mixing them causes confusion

### Case A - Plain HTTP (no TLS)
#### Who decides?
 * **Client declares**
 * **Server accepts or rejects**

#### How?
The client literally writes this line:
```sql
GET / HTTP/1.1
```

That string:
 * is authored by the client
 * is parsed by the server
 * is either understood or no

There is **no negotiation**.

#### What happens if:
 * client sends `HTTP/1.1` but server only supports `1.0` $\rightarrow$ error or downgrade behavior
 * client sends nonsense \$rightarrow$ server rejects

#### Keey rule
**In plain HTTP, the client proposes the version unilaterally.**

The server:
 * does not "upgrade"
 * does not netotiate
 * only reacts

