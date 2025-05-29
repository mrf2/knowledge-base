# Enumeration
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
