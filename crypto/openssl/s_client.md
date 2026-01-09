# `openssl s_client` does not do HTTP encryption for us
It only:
 * negotiates TLS
 * shows parameters
 * lets us type raw bytes (which the server rejects)
This is **by design of TLS.**

