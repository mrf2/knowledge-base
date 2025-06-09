# TCP Protocol

 - **TCP** is the ancronym for Transmission Control Protocol is a connection-oriented protocol requiring a TCP three-way-handshake to establish a connection. TCP provides reliable data transfer, flow control and congestion control. Higher-level protocols such as HTTP, POP3, IMAP and SMTP use TCP

> If the connection des not exist (CLOSED), then a reset is sent in the response to any incoming segment except another reset. A *SYN* segment that does not match an existing connection is rejected by this means.
> --Source: [RFC - 9293](https://datatracker.ietf.org/doc/html/rfc9293)

 - If Namp sends a TCP request with *SYN* flag set to *closed* port, the target server will respond with a TCP packet with *RST* (Reset) flag set. By this response, Nmap can establish that the port is closed.
 - If the request is sent to an *open* port, the target will respond with a TCP packet with SYN/ACK flags set. Namp the marks the port as beging *open*, and completes the handshake by sending back a TCP packet with ACK set.
 - Nmap sends a TCP SYN request, and receives nothing back. This indicates that the port is being protected by a firewall and thus the port is considered to be *filtered*.

|Port Status|Condition|
|---|---|
|closed|TCP request with *SYN* flag set to a port and the server respond with a TCP packet with *RST* (Reset) flag set.|
|open|TCP request sent to an open port and the target will respond with a TCP packet with SYN/ACK flags set.|
|filtered|TCP request sent and receives nothing back. This indicates that the port is beging protected by a firewall.|


### [TCP Header](rfc9293.html)
