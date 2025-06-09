 - **UDP** is the acronym for the User Datagram Protocol (UDP) is a connectionless protocol; UDP does not require a connection to be established. UDP is suitable for protocols that rely on fast queries, such as DNS, and for protocols that prioritise real-time communications, such as audio/video conferencing and broadcast.

|Port Status|Condition|
|---|---|
|`open` or `filter`|Packet is sent to an open UDP port and no response|
|`closed`|Packet is sent to a *closed* UDP port and the target should respond with an ICMP (ping) packet containing a message that the port is unreachable.|
