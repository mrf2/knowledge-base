# TLS handshake message type IDs

## TLS Handshake Message Type Numbers
Define originally in RFC 5246 (TLS 1.2) and updated in RFC 8446 (TLS 1.3).

Here is the **full canonical list**

### Core handshake messages
|Number|Name|Direction|TLS 1.3|
|---|---|---|---|
|0|hello_request|S → C | ❌ removed|
|1|client_hello|C → S|✅|
|2|server_hello|S → C|✅|
|4|new_session_ticket|S → C| ✅ (post-handshake)|
|8|encrypted_extensions| S → C| ✅ (new in 1.3)|
|11|certificate|both|✅|
|12|server_key_exchange|S → C| ❌ removed|
|13| certificate_request| S → C|✅|
|14|server_hello_done|S → C| ❌ removed|
|15|certificate_verify|both|✅|
|16|client_key_exchange| C → S| ❌ removed|
|20|finished|both|✅|


## Summary
 * The numbers `(1), (2), (11),...,(x)` are **TLS handshake message type IDs**
 * They are **defined by the TLS specification**
 * They are **1-byte numeric constants**
 * TLS 1.3 uses **fewer messages**, but keeps the same numbering
 
