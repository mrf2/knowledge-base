# Nmap

Nmap (Network Mapper) is a open-source tool used for network discovery and security auditing. It aslo assistsw int he exploration of network hosts and services, providing information about open ports, operating systems, and other details.

### switches
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


