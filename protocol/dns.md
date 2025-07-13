# DNS - Domain Name System
Domain Name System (DNS) is the protoocol responsible for resolving hostnames to their respective IP addresses.

## TLD
A TLD is the most righthand part of a domain name. There are two types of TLD
 * gTLD - Generic Top Level. Historically a gTLD was meant to tell the user the domain name's purpose; for example, a .com would be for commercial purposes, .org for an organization, .edu for education and .gov for government.
 * ccTLD - Country Code Top Level Domain. A ccTLD was used for geographical purposes. 

For a [full ist of over 2000 TLDs](tlds-alpha-by-domain.txt): https://data.iana.org/TLD/tlds-alpha-by-domain.txt

## Second-Level Domain
Taking tryhackme.com as an example, the .com part is the TLD, and tryhackme is the Second Level Domain. When registering a domain name, the second-level domain is limited to 63 characters + the TLD and can only use *a-z 0-9* and hypens (can not start or end with hypens or have secutive hypens)

## Subdomain
A subdomin sits on the left-hand side of the Second-Level Domain using a period to seperate it. A subdomain name has the same creation restrictions as a Second-Level Domain, being limited to 63 characters and can only used *a-z 0-9* and hyphens. Multiple subdomains split with periods to create longer names, but the length must be kept to 253 characters or less. There is no limit to the number of subdomains.

## DNS Record Types
|Record Type|Meaning|
|---|---|
|**A** Record|These records resolve to IPv4 addresses.|
|**AAAA** Record|These records resolve to IPv6 addresses.|
|**CNAME** Record|These records resolve to another domain name, for example, TryHackMe's online shop has the subdomain name store.tryhackme.com which returns a CNAME record shop.shopify.com. Another DNS request would then be made to shops.shopify.com to work out the IP address.|
|**MX** Record|These records resolve to the address of the servers that handle the email for the domain we are querying, for example an MX record response for tryhackme.com would look something like alt1.aspmx.google.com. These records also come with a priority flag. This tells the client in which order to try the servers, this is perfect for if the main server goes down and email needs to be sent to backup server.|
|**TXT** Record|TXT records are free text fields where any text-based data can be stored. TXT records have multiple uses, but some common ones can be to list servers that have the authority to send an email on behalf of the domain (this can help in the battle against spam and spoofed email.) They can also be used to verify ownership of the domain name when signing up for third pary services.|
  

## What happens when making a DNS rquest
 1. When request a domain name, the computer first checks its local cache to see if it has previously looked up the address recently; if not a request to Recursive DNS Server will be made. 
 2. A Recursive DNS Server is usually provided by the ISP, but it can also be set manually. This server also has a local cache of recently looked up domain names. If a result if found locally, this is sent back to the computer, and the rquest ends here (this is common for popular and heavily requested services such as Google, Facebook, Youtube etc.). If the request cannot be found locally, a journey begins to find the correct answer, starting with the internet's root DNS servers. 
 3. The root servers act as the DNS backbone of the internet; their job is to redirect to the correct Top Level Domain Server, depending on the request. If, for example a request www.tryhackme.com, the root server will recognise the Top Level Domain of .com and refer to the correct TLD server that deals with .com addresses.
 4. The TLD server holds records for where to find the authoritative server to answer the DNS request. The authoriative server is often also known as the nameserver for the domain. For example, the name server for tryhackme.com is kip.ms.cloudflare.com and uma.ns.cloudflare.com. There can be multiple nameservers for a domain name to act as a backup in case one goes down.
 5. An authoritative DNS server is the server that is responsible for storing the DNS records for a particular domain name and where any updates to the domain name DNS records would be made. Depending on the record type, the DNS record is then sent back to the Recursive DNS Server, where a local copy will be cached for future requests and then relayed back to the original client that made the request. DNS records all come with a TTL (Time To Live) value. This value is a number represented in seconds that the response should be saved for locally until it look it up again. Caching saves on having to make a DNS request every time communicate with a server.

## DNS Resolver
A **DNS Resolver** is any component (software or system) that performs **name resolution**, which includes:
 * **Stub resolvers** *(on the client machine)*
 * **Recursive resolvers** *(usually external DNS servers)*


> Source: https://tryhackme.com/room/dnsindetail
