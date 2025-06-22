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


### Commands
|Command|Meaning|How to use|
|---|---|---|
|HELO|Identify the sending client's domain name or IP|`HELO mail.domain.com`|
|EHLO|Extended version of **HELO** that also list server-supported features.|`EHLO mail.domain.com`|
|MAIL FROM:|Begins the mail transaction; specifies sender email address|`MAIL FROM:<alice@example.com>`|
|RCPT TO:|Specifies the receipient's email address. Can be used multiple times|`RCPT TO:<bob@example.net>`|
|DATA|Signals that the message body follows. Ends with a single `.` on a line.|`DATA ... .`|
|QUIT|Terminates the SMTP session gracefully|`QUIT`|
|VRFY|Confirming the names of valid users|`VRFY user@domain.com`|
|EXPN|Expands a mailing list (also usually disabled for privacy)|`EXPN staff`|


## SMTP Client
### Telnet - Talk to an SMTP server manually using telnet
```bash
telnet smtp.example.com 25
```

We can then type command like below:
```bash
EHLO outdomain.com
MAIL FROM:<we@ourdomain.com>
MAIL TO:<you@yourdoman.com>
DATA
Subject: Test Email

This is a test email sent from telnet terminal

QUIT
```

### openssl s_client
```bash
openssl s_client -starttls smtp -connect smtp.gmail.com:587

# example for gmail
openssl s_client -connect smtp.gmail.com:465 -crlf
```



> Resource: https://www.afternerd.com/blog/smtp/

