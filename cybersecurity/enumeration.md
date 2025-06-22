# Enumeration
**A process which establishes an activity connection to the target hosts to discover potential attack vectors in the system, and the same can be used for further exploitation of the system.** - *Infosec Institute*

**Enumeration** is the process of **activity** connecting to a target system and systematically **extracting detailed information**, such as:
 - Usernames
 - Group memberships
 - Machine names
 - Shares and services
 - Network resources
 - Applications and banners

It typically follows after scanning and involves tools like:
 - SMB: Getting user list, shares (`rpcclient`, `enum4linux`)
 - `nmap` with certain scripts
 - SNMP enumeration tools: Device info, software version
 - LDAP queries: Extracting directoy entries
 - NetBIOS enumeration: Machine and domain names
It's an **active phase** of information gathering but more focused thatn simple scanning.

### Enumeration is an Active Process
 - Enumeration **actively engages** with the target system to extract detailed data.
 - It typcally uses **authenticated or unauthenticated connections** to services.
 - It **sends crafted request** and analyzes responses - this is **not silent** like passive reconnaissance.
 - Enumeration comes after **Reconnaissance**

|Framework|Phase/Tactic|Description|
|---|---|---|
|MITRE ATT&CK|Discovery|Internal enumeration of system and network.|
|Cyber Kill Chain|Reconnaissance|External info gathering before exploitation. If the enumeration is **external** (e.g., passive DNS, Shodan, WHOIS, banner grabbing), it's considered part of reconnaissance.|
|Cyber Kill Chain|Weaponization or Delivery|If the enumeration is **internal** (e.g., after initial access), such as enumerating domain controllers or SMB shares, it supports later statges but is not explicitly defined as its own phase in the original Kill Chain.|

## Enumeration Tools
|Name|Purpose|
|---|---|
|`nfs-common`|It is important to have this package installed on any machine that uses NFS, either as client or server. It includes programs such as: **lockd, statd, showmount, nfsstat, gssd, idmapd**, and **mount.nfs**.|
|`nmap`|Port Scanning|
|`mount`|Mounting NFS shares. Commonly used command `sudo mount -t nfs IP:<share_name> /tmp/mount -nolock`|
|smtp-user-enum|Enumeration is performed by inspecting the responses to VRFY, EXPN, and RCPT TO: commands.|
 
### Explanation of: sudo mount -t nfs IP:<share_name> /tmp/mount -nolock
|command/switch/options|Meaning|
|---|---|
|sudo|Run as root|
|mount|Execute mount command|
|-t nfs|Type of device to mount, then specifying that it's NFS|
|IP:\<share_name\>|The IP Address of the NFS server, and the name of the share we wish to mount|
|-nolock|Specfies not to use Network Lock Manager (NLM) Protocol locking|


> Resource: https://wiki.wireshark.org/Network_Lock_Manager
