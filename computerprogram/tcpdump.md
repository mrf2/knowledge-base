# tcpdump - dump traffic on a network
**tcpdump** is a powerful command-line packet analyzer. It lets us capture and inspect network traffic in real-time or form a saved `.pcap` file. It is often used for *protocol debugging, network diagnostics, or security analysis*.

## Basic Syntax
```bash
tcpdump [options] [expression]
```

## Common use cases
|Command|Descripton|
|---|---|
|`tcpdump`|Start capturing all packets on the default interface|
|`tcpdump -c 10`|Stop after 10 packets|
|`tcpdump -D` or `tcpdump --list-interfaces`|List of all interfaces|
|`tcpdump -i eth0`|Capture on a specific interface|
|`tcpdump -nn`|Don't resolve hostnames or port names ***(show raw IPs/ports)***|
|`tcpdump -r file.pcap`|Read and display packets from a capture file|
|`tcpdump -v` or `-vvv`|Increase verbosity *(more packet detail)*|
|`tcpdump -w file.pcap`|Write packets to a file for later analysis *(e.g. in Wireshark)*|
 
## Examples of Filtering
|Filter|Example|
|---|---|
|Filter by Protocol|`tcpdump icmp`<br>`tcpdump tcp`<br>`tcpdump udp`|
|Filter by Host|`tcpdump host 192.168.1.1`<br>`tcpdump src 10.0.0.5`<br>`tcpdump dst 8.8.8.8`|
|Filter by Port|`tcpdump port 53` *#Any direction*<br>`tcpdump src port 80`<br>`tcpdump dst port 443`|
|Filter by Network|`tcpdump net 192.168.0.0/16`|
|Capture DNS Traffic|`tcpdump -i eth0 port 53`|
|Capture HTTP Traffic|`tcpdump -i eth0 tcp port 80 -A`|

## Flags
|Flag|Description|
|---|---|
|`-X`|Hex + ASCII *(data payload only)*|
|`-XX`|Hex + ASCII *(includes link-layer headers like Ethernet)*|
|`-A`|ASCII only *(printable characters only, no hex)*|
|-v` or `-vvv`|Increase verbosity *(more packet detail)*|


## uses of tcpdump
sudo tcpdump ip poto <protocol_name> -i <interface_name>

example:
sudo tcpdump ip proto \\icmp -i tun0

example listening from all interface:
sudo tcpdump icmp -i any
```


