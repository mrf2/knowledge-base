# socket

### Scoket Address Structures
 * From the perspective of the UNIX kernel, a socket is an end point for communication.
 * From the perspective of a UNIX program, a socket is an open file with a corresponding descriptor.

---
### Origin of the sockets interface
The sockets interface was developed by researchers at University of California, Berkeley, in the early 1980s. For this reason, it is often reffered to as *Berkeley sockets*. The Berkeley researchers developed the sockets interface to work with any underlaying protocol. The first implementtion was for TCP/IP, which they inclued in the Unix 4.2BSD kernel and distributed to numerous universities and labs. This was an Important event in Internet history. Almost overnight, thousands of people had access to TCP/IP and its source codes. It generated thremendous excitement and sparked a flurry of new research in networking and internetworking.
> Source: Computer Systems: A Programmer's Perspective by Randal E. Bryant and David R. O'Hallaron
