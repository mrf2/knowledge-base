# ALPN = Application-Layer Protocol Negotiation

ALPN = Application-Layer Protocol Negotiation
 * Happens **inside TLS**, before HTTP starts.
 * Client sayes;
   > "Once TLS is done, I can speak **HTTP/2(`h2`) or HTTP/1.1.**

## Why this exists
 * Avoids second negotiation round-trip
 * Server picks **one** protocol

## Important
 * This is **not HTTP yet**
 * It's TLS metadata

