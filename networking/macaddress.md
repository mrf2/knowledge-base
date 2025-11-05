# MAC Address
There are three different types of MAC addresses on Ethernet network
1. `Unicast MAC Address` - **Unicast MAC Address** are those assign to individuals nodes, and first byte is always ***00***.
2. `Broadcast MAC Address`
3. `Multicast MAC Address`

## MAC Address Structure
A 48-bit Ethernet MAC address looks like this:
```bash
[ 8 bits ][ 8 bits ][ 8 bits ][ 8 bits ][ 8 bits ][ 8 bits ]
 ^^^^^^^^
```
The **first octet** (the first 8 bits) has special meaning  - specifically its **two least significant bits (LSBs)** are not part of the vendor OUI logic.
|Bit|Name|Meaning|
|---|---|---|
|b0|**I/G bit** (Individual/Group)|0 = **Unicast (individual)**, 1 = Multicast (group)|
