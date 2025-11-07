# MAC Address
There are three different types of MAC addresses on Ethernet network
1. `Unicast MAC Address` - **Unicast MAC Address** are those assign to individuals nodes, and first byte is always ***00***.
2. `Broadcast MAC Address`
3. `Multicast MAC Address`

## 1. MAC Address Structure
A 48-bit Ethernet MAC address looks like this:
```bash
[ 8 bits ][ 8 bits ][ 8 bits ][ 8 bits ][ 8 bits ][ 8 bits ]
 ^^^^^^^^
```
The **first octet** (the first 8 bits) has special meaning  - specifically its **two least significant bits (LSBs)** are not part of the vendor OUI logic.
|Bit|Name|Meaning|
|---|---|---|
|b0|**I/G bit** (Individual/Group)|0 = **Unicast (individual)**, 1 = Multicast (group)|
|b1|**U/L bit** (Universal/Local)|0 = Globally unique (IEEE-assigned OUI), 1 = Locally administered|
|b2-b7|Vendor's assigned bits|Part of the OUI when U/L = 0|

## 2.  Who Decides Unicast/Multicast/Broadcast?
### Unicast
 * **Set by the manufacturer**.
 * IEEE allocates the OUI, ensuring b0=0 (individual)
 * The manufacturer assigns the remaining 24 bits uniquely per device.

Example:
```bash
00:1A:2B:xx:xx:xx
^
b0 = 0 → unicast
```

### Multicast
 * **Not OEM-specific**.
 * **Defined by the protocol level (Ethernel standard)**.
 * Any MAC address with **b0=1** is considered *multicast* by the Ethernet controller.

