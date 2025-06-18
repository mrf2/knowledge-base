# SMB - Server Message Block Protocol

**SMB** is the acronym for Server Message Block (SMB) is a communication protocol originally developed in 1983 by Barry A. Feigenbaum at IBM and intended to provide share access to files and printers across nodes on a network of systems running IBM's OS/2. It also provieds an authenticated inter-process communication (IPC) mechanism. *SMB can be found on port 445.*

 * **SMB** - Server Message Block is a client-server communication protocol used for sharing access to files, printers, serial ports and other resources on a network.
 * Server make file systems and other resources (printers, named pipes, APIs) available to clients on the networks. Client computer may have their own hard disks, but they may also want access to the shared file systems and printers on the servers.
 * The SMB protocl is known as response-request protocol, meaning that it transmits multiple messages between the client and server to establish a connection. Clients connect to servers using TCP/IP (actually NetBIOS over TCP/IP as specified in RFC1001 and RFC1002), NetBEUI or IPX/SPX.
* Microsoft Windows operating system since Windows 95 have included client and server **SMB** protol support. Samba, an open source server that supports the SMB protol was released for Unix systems.
* Typically, there are SMB share drives on a server that can be connected to and used to view or transfer files. SMB can often be a great starting point for an attacker looking to discover sensitive information.

## SMB Client
We can remotely access the SMB share using the following syntax:
```bash
Syntax:
smbclient //[IP]/[SHARE] -U [USERNAME] -p [PORT]

Example:
smbclient //10.10.10.15/sharename -U Anonymous -p 445
```

### SMB Client Command
|command|meaning|
|---|---|
|ls|List files and directories|
|dir|List files and directories|
|cd \<directory_name\>|Change directory|
|get \<file_name\>|Download file|




> Source: https://tryhackme.com/room/networkservices
