# mysql

 * **Schema:** In MySQL, physically, a schema is *synonymous* with a *database*. We can substitute the keyword **"SCHEMA"** instead of DATABASE in MySQL ***SQL*** syntax, for example using `CREATE SCHEMA` instead of `CREATE DATABASE`. It is important to understand this releationship for MySQL because some other database products draw a distinction. For example, in the Oracle Database product, a *schema* represents only a part of database: the tables and other objects owned by a single user.
 * **Hashes:** Hashes are, very simple, the product of a cryptograpic algorithm to turn a variable length into a fixed lenth output. Hash functions are indeed mathematical functions. ***In MySQL hashes can be used in different ways, for instance to index data into a hash table. Each hash has a unique ID that servers as a pointer to the original data. This creates an index that is significantly smaller than that original data, allowing the values to be searched and accessed more efficienty***.

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
```bash
mysql --skip-ssl -h 10.10.45.118 -u root -p
```


