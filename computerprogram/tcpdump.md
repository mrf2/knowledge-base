# tcpdump - dump traffic on a network

 * List of all interfaces: `tcpdump -D` or `tcpdump --list-interfaces`

## uses of tcpdump

Start a `tcpdump` listener
```bash
syntax

sudo tcpdump ip poto <protocol_name> -i <interface_name>

example:
sudo tcpdump ip proto \\icmp -i tun0

example listening from all interface:
sudo tcpdump icmp -i any
```


