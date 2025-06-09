# Nmap

Nmap (Network Mapper) is a open-source tool used for network discovery and security auditing. It aslo assistsw int he exploration of network hosts and services, providing information about open ports, operating systems, and other details.

### switches
 - `-sT` for *TCP Connect scans*
 - `-sS` for *Syn Scan*
 - `-sU` for *UDP Scan*
 - `-O` for *Operating System (OS) detection*
 - `-sV` for *detect the version of services running on the target*
 - `-oA` for *save the nmap results in three major formats at once*

### scripts
 - To activate all of the scripts in a category
```bash
nmap --script=vuln
```

## SYN scans (`-sS`)
SYN scans (`-sS`) are used to scan the TCP port-range of a target or targets; however the scan types work slightly differently. SYN scans are sometimes reffered to as ***"Half-Open"*** scans, or ***"Stealth"*** scans.
- TCP scans perform a full three-way handshake with the target, SYN scans sends back a RST TCP packet after receiving a SYN/ACK from the server (this prevents the server from repeatedly trying to make the request).

### Features
 * It can be used to bypass older Intrusion Detection Systems (IDS) as they are looking out for a full three-way handshake. This is often no longer the case with modern IDS solutions; it is for this reason that SYN scans are still frequently referred to as "stelth" scans.
 * SYN scans are often not logged by applications listening on open ports, as standard practice is to log a connection once it's been fully established. Again, *this plays into the ieda of **SYN** scans being stealthy.*
 * Without having to bother about completing (and disconnecting from) an three-way handshake for every port, SYN scans are significantly faster than a standard TCP Connect scan.

### Disadvantages
 * They require sudo permissions in order to work correctly in Linux. This is because SYN scans require the ability to create raw packets (as opposed to the full TCP handshake), which is a previlege only the root user has be default.
 * Unstable services are sometimes brought down by SYN scans, which could prove problematic if a client has provided a production environment for the test.

> SYN scans are the default scans used by ***Nmap*** *if run with sudo permissions*. If run **without** sudo permissions, ***Nmap*** defaults to the TCP Connect scan.


## UDP Scan (`-sU`)
Due to the difficulty in identifying wheather a **UDP** port is actually open, **UDP** scans tend to be incredibly slow in comparison to the various TCP scans (in the region of 20 minutes to scan the first 1000 ports with a good connection). For this reason it's usually good practice to run an **Nmap** scan with `--top-ports <number>` enabled. For example, scanning with `nmap -sU --top-ports 20 <target` Will scan the top 20 most commonly used **UDP** ports.

> Source: [TryHackMe.com](https://tryhackme.com/room/furthernmap)

