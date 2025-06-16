# Gobuster
**Gobuster** is a free and open-source directory and file enumeration tool. Penetration testers and security professionals use it to find hidden directories and file on web servers. It is use for brute-forcing URIs (directories and files), DNS subdomains, and virtual host names.

To get started, it will need a wordlist for **Gobuster** (which will be used to quickly go through the wordlist to identify if a public directory is available).

Run Gobuster: `gobuster dir -u http://IP_ADDRESS:3333 -w`

|Gobuster flag|Description|
|---|---|
|-e|Print the full URLs in the console|
|-u|The target URL|
|-w|Pathe to the wordlist|
|-U and -P|Username and Password for Basic Auth|
|-p\<x\>|Proxy to use for requests|
|-c \<http cookies\>|Specify a cookie for simulating auth|
