# HTTP header

**There is No fixed number of HTTP header fields.**

## Why?
HTTP headers are:
 * Extensible
 * Case-insensitive
 * Open-ended
Anyone can invent:
```bash
X-My-Header: foo
```
And HTTP will still be valid.

So, instead of **How many header fields exist?** should be **How many standardized, commonly recognized HTTP header fields exit**.

## The COMPLETE standardized HTTP header field list
 * RFC 9110/9111/9112
 * Plus widely adopted de-facto standards

### General Headers (apply to request and response)
These control **message-level behavior**, not content.

|Header|Meaning|
|---|---|
|`Cache-Control`|Caching directives|
|`Connection`|Hop-by-hop control|
|`Date`|Message timestamp|
|`Pragma`|Legacy cache control|
|`Trailer`|Declares trailing headers|
|`Transfer-Ecoding`|Message body encoding|
|`Upgrade`|Protocl switch (eg. HTTP $\rightarrow$ WebSocket)|
|`Via`|Proxy chain tracking|
|`Warning`|Cache-related warnings|

### Request Headers (client $\rightarrow$ server)
These are **claims made by the client:**

#### Client and Context
|Header|Meaning|
|---|---|
|`Host`|Target host (mandatory in HTTP/1.1)|
|`User-Agent`|Client identity string|
|`Content-Type||
|`Accept||
|`Authorization`|Client credentials|
|`Origin`|Request origin (security-relevant)|
|`Referer`|Previous page|
|`Cookie`||
Thes **decide wheter server like nginx lets us in**.

#### Capability and Preference
|Header|Meaning|
|---|---|
|`Accept`|Accepted media types|
|`Accept-Encoding`|Compression support|
|`Accept-Language`|Language preference|
|`Accept-Charset`|Charset preference (legacy)|

#### Conditions
|Header|Meaning|
|---|---|
|`If-Match`|Conditional request (ETag)|
|`If-None-Match`|Cache validation|
|`If-Modified-Since`|Time-based cache|
|`If-Unmodified-Since`|Inverse condition|
|`If-Range`|Partial content control|

#### Authentication
|Header|Meaning|
|---|---|
|`Authorization`|Client credentials|
|`Proxy-Authorization`|Proxy credentials|

#### Content-related (for request body)
|---|---|
|Header|Meaning|
|`Content-Type`|Body format|
|`Content-Length`|Body size|
|`Content-Encoding`|Body encoding|
|`Content-Language`|Body language|

#### Control

### Response Headers (server $\rightarrow$ client)
Sent **by server** back to client

|Header|Meaning|
|---|---|
|`Server||
|`Set-Cookie`||
|`Content-Type`||
|`Cache-Control`||
|`X-Frame-Options`||

These tell:
 * what server replied
 * what security policies exist
 * what cookie where issued

**Response headers do NOT influence request acceptance**

They'are informational *after access* is granted or denied.
