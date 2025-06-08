# dig
Dig allows us to manually query recursive DNS servers of our choice for information about domain:
```bash
dig <domain> @<dns-server-ip>
```

 - The TTL can be found in the second column of the answer section. It's important to remember that TTL (in the context of DNS caching) is measure in second.

