# WPA - Wi-Fi Protected Access
**WPA** is a security protocol developed by the Wi-Fi Alliance in 2003, as a direct response to the serious weakness found in [WEP (Wired Equivalent Privary)](wep.md). It was designed to provide much stronger data protection and access control for Wi-Fi networks.

## Key Features of WPA
|Feature|Description|
|---|---|
|Encryption Method|Uses [TKIP (Temporal Key Integrity Protocol)](tkip.md), with dynamically changes keys as the system is used. making it more secure than WEP.|
|Authentication|Supports 802.1x authentication for enterprise networks (WPA-Enterprise) and Pre-Shared Key (PSK) for home use (WPA-Personal).|
|Key Management|Implements per-packet key mixing to prevent key reuse.|
|Message Integrity Check (MIC)|Helps prevent packet forgery and replay attacks (unlike WEP).|
|Backward Compatibility|Designed to work with some older WEP hardware via firmware upgrades.|


## WPA Variants
|Name|Features|
|---|---|
|WPA-Personal (WPA-PSK)|Uses a **pre-shared key** (a password) for authentication. Common in home networks.|
|WPA-Enterprise (WPA-802.1x)|Uses a **RADIUS Server** and **EAP (Extensible Authenticaion Protocol)** for authentication. Used in organizations and enterprises.|

