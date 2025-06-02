# snort
Snort is an open source network intrusion prevention system (IPS) by Cisco. It is cabpble of performing real-time traffic analysis and packet logging on IP networks. It can perform protocol analysis, content searching and maching, and detect a variety of attacks and probes. Snort can be used as a straight packet sniffer like tcpdump, a pakcet logger (user for network traffic debugging), or as a full-blown network intrusion preverion system.

Snort can be configured to run in three modes:
 - ***Sniffer mode***, which simply reads the packets off of the network and display them for you in a continous stream on the console (screen)
 - ***Packet Logger mode***, which logs the packets to disk.
 - ***Network Intrustion Detection System (NIDS) mode***, which performs dectection and analysis on network traffic. This is the most complex and configurable mode.

## Basic Outline of a Snort rule:
```bash
[action][protocol][sourceIP][sourceport] -> [destIP][destport] ( [Rule options])
```
