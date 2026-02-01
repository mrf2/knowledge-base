# TLS handshake message type IDs

## TLS Handshake Message Type Numbers
Define originally in RFC 5246 (TLS 1.2) and updated in RFC 8446 (TLS 1.3).

Here is the **full canonical list**

### Core handshake messages
|Number|Name|Direction|TLS 1.3|
|---|---|---|---|
|0|hello_request|S $\rightarrow$ C | ❌ removed|


## Summary
 * The numbers `(1), (2), (11),...,(x)` are **TLS handshake message type IDs**
 * They are **defined by the TLS specification**
 * They are **1-byte numeric constants**
 * TLS 1.3 uses **fewer messages**, but keeps the same numbering
 
