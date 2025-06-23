# mysql

 * Connecting to server
```bash
mysql -h <machine_IP> -u root -p
```
 * If ***mysql*** client returns a ***TLS/SSL error***, we need to add ***-ssl-mode=DISABLED***; therefore the command becomes:
```bash
mysql -h <machine_IP> --ssl-mode=disabled -u root -p
```
 * If it shows `error: mysql: unknown variable 'ssl-mode=disabled'` then trye this:
```bash
mysql -h <machine_IP> --tls-version='' -u root -p
```


