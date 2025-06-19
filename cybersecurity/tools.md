# Tools
## Aircrack-ng
**Aircrack-ng** is a suit of tools for **auditing wireless networks**
 - **Aircrack-ng** can **capture packets, crack WEP/WPA keys,** and **analyze Wi-Fi traffic**
 - It is especially effective for **penetration testing** of **802.11** networks
## Burp Suite
**Burp Suite** - A proxy tool mainly used for **web app security testing** (XSS, SQLi, etc.). **Burp suite** is a powerful toolset used primarily for **web application security testing**. Its **intercepting proxy** allows penetration testers to:
 - View and **modify HTTP/HTTPS requests and responses** in real time.
 - Performing **manual testing** for vulnerabilities like **XSS, SQLi,** and **CSRF.**
 - Use built-in tools like **Repeater, Intruder**, and **Scanner** for deeper analysis.

## Cain & Abel
**Cain & Abel** is Password recovery tools for Windows. It is also used for sniffing and cracking hashes.

## Hydra
**Hydra** is a **brute-force password cracking** tool for services like SSH, FTP, HTTP, etc.
**Hydra** is a very fast online password cracking tool, which can perform rapid dictionary attacks against more than 50 Protocols, including *Telnet, RDP, SSH, FTP, HTTP, HTTPS, SMB, several databases* and much more.

### Syntax of Hydra uses
```bash
syntax
hydra -t <conn_num> -l <user_name> -P <path of password directory> -vV <ip_address> <protocol>

example:
hydra -t 4 -l mike -p /usr/share/wordlists/rockyou.txt -vV 10.10.10.10 ftp
```

|Command Option|Meaning|
|---|---|
|hydra|Hydra program name|
|-t 4|Number of parallel connections per target|
|-l \<user\>|Points to the user|
|-P|Point to the file containg the file of possible passwords|
|-vV|Sert verbose mode|
|\<ip_address\>|Target IP address|
|protocol|Sets the protocol|

## John the Ripper
**John the Ripper** is a Password **cracking tool**.
**Jhon the Ripper:** A well-known password-craking tool, commonly used in penetration testing to identify weak or easily guessable passwords. It can work with password hashes and try dictionary, brute-force, or hybrid attacks.

## Kismet
**Kismet** is a **wireless network detection and sniffer tool**. It's used to audit wireless networks by:
 - Detecting SSIDs (even hidden ones)
 - Sniffing wireless packets
 - Identifying network types (802.11a/b/g/n/ac)
 - Monitoring signal strength and encryption
 - Logging wireless activity
It operates **passively**, so it doesn't send packets - making it great for stealthy wireless reconnaissance.

## Metasploit
Metasploit is an open-source penetration testing framework that helps security professionals find and exploit vulnerabilities in computer systems. It includes a database of know vulnerabilities and tools and scripts for exploiting them.

## Nikto
**Nikto** is a web server vulnerability scanner. It checks for:
 - Outdated software versions
 - Dangerous files/CGIs
 - Common misconfigurations
 - Known vulnerabilities etc.
 - **Does not perform passwords strength testing.**

## netstat

## Nmap
**Nmap** is a **network scanning tool** used to find open ports, services and OS fingerprinting.

## ssh
**ssh** (SSH client) is a program for logging into a remote machine and for executing commands on a remote machine. It is intended to provide secure encrypted communications between two untrusted hosts over an insecure network. X11 connections, arbitrary TCP ports and Unix-domain sockets can also be forwarded over the secure channel.

**ssh** connects and logs into the specified destination, which may be sepecified as either [user@]hostname or URI of the form ssh://[user@]hostname[:port]. The user must prove their identity to the remote machine using one of several methods.

If a command is specified, it will be executed on the remote host instead of a login shell. A complete command line may be specified as command, or it may have additional arguments. If supplied, the arguments will be appended to the command, separated by spaces, before it is sent to the server to be executed. *Source: ssh manpage*

## netcat | nc
The **nc** or **netcat** utility is used for just about anything under the sun involving TCP, UDP, or Unix-domain sockets. It can open TCP connections, send UDP packets, listen or arbitrary TCP and UDP ports, do port sccanning, and deal with both IPv4 and IPv6. Unline telnet, **nc** scripts nicely, and separates error messages onto standard error instead of sending them to standard output, as telnet does with some. *Source: nc manpage*

## Wireshark
**Wireshark** - A powerful **packet analyzer** used to capture, inspect, and analyze network traffic in real time. Vital for troubleshooting and investigating network security.
