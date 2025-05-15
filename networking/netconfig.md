# Linux
### Ethernet Interface On/Off
```bash
# ifconfig <interface_name> down
# ifconfig <interface_name> up
```

### DHCP Getting new IP
```bash
dhclient <interface_name>
```

### MAC Address Change
```bash
# ifconfig <interface_name> down
# ifconfig eth0 hw ether <address>
# ifconfig <nterface_name> up
```
