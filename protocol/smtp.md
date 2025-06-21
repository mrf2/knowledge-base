# SMTP - Simple Mail Transfer Protocol (Used for sending email)
### Purpose
SMTP is responsible for **sending** messages from a client (e.g. mail app) to a mail server or between *mail servers*, more specifically to a Mail Submission Agent (MSA) or a Mail Transfer Agent (MTA).

### SMTP server performs three basic functions: 
 * It verifies who is sending email through the SMTP server.
 * It sends the outgoing mail
 * If the outgoing mail can't be delivered it sends the message back to the sender

### Default port numbers
|Purpose|Port|Encryption|Use|
|---|---|---|---|
|Default SMTP (plain)|25|None or STARTTLS|25 is often used for *server-to-server* relay (not recommended for client submission anymore)|
|SMTP with STARTTLS (modern)|587|STARTTLS (explicit TLS)|587 is the *standard for client-to-server submission* (recommended).|
|SMTP over SSL/TLS|465|SSL/TLS(implicit)|465 was deprecated, then revived for **implicit TLS**.|

### STARTTLS
**STARTTLS** is a *command* (not a protocol) that tells an existing, unencrypted connection to **upgrade to a secure, encrypted connection using TLS (Transport Layer Security)**.

It's used in protocol like:
 * SMTP (mail sending)
 * IMAP and POP3 (mail receiving)
 * XMPP, LDAP, etc.

### How does STARTTLS work?
Step-by-step
 1. The client connects to the server on the normal **plain-text port** (e.g, SMTP on port 25 or 587)A
 2. The server says, *I support STARTTLS*.
 3. The client says, *Okay, let's switch to encrypted mode* (sends `STARTTLS` command).
 4. They both switch to **TLS/SSL encryption** without changing ports.
 5. All communication from them on is **encrypted**.

### Limitations: SMTP is *not designed to retrieve or store* email. It **only pushes** message out.


> Resource: https://www.afternerd.com/blog/smtp/
