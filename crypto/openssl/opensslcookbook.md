# OpenSSL CookBook learnings

1. Determine OpenSSL Version and Configuration
   ```bash
   openssl version
   ```
   - To get complete version info, use the `-a` switch:
     ```bash
     openssl version -a
     ```
2. Examine Available Commands
   ```bash
   openssl help
   ```
3. Generate an RSA key using `genpkey` command:
   ```
   openssl genpkey -out fd.key -algorithm RSA -pkeyopt rsa_keygen_bits:2024 -aes-128-cbc
   ```
   - When we use the `genpkey` command, the generated private keys are stored in PKCS #8 format
   - use `cat pd.key` to view the key as a blob or random data 
