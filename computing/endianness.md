# Endianness
**Endianess** defines the **byte order** used to represent multi-byte data *(like integers)* in ***memory*** or ***data streams***. Endianess **applies only to multi-byte scalar data types,** not directly to entire data structures (e.g. in **C Programming**) - **but it affects structures because they are composed of those scalars.**
 * **Big-Endian:** Most Significant Byte **(MSB)** stored first *(lowest memory address)*.
 * **Little-Endian:** Least Significant Byte **(LSB)** stored first.

### Example: 32-bit Integer `0x12345678`
|Byte Position|Big-Endian|Little-Endian|
|---|---|---|
|Byte 0|`0x12` **(MSB)**|`0x78` **(LSB)**|
|Byte 1|`0x34`|`0x56`|
|Byte 2|`0x56`|`0x34`|
|Byte 3|`0x78`|`0x12`|

## Why It Matters?
### 1. Cross-Platform Data Sharing
 * Data written on ***little-endian*** system may be misinterpreted by ***big-endian*** system.
 * Network protocols (e.g., TCP/IP) use **network byte order = Big-Endian**.
### 2. Low-Level Debugging
 * `hexdump`, `gdb`, or *raw* memory inspection shows raw bytes.
 * We must interpret data in the ***system's endianness***.
### 3. File and Protocol Formats
 * Some file format (e.g., *PNG*, *BMP*, *ELF*) define specific endianness.
 * Protocols may define message fields in ***network byte order***.

## System Architectures and Endianness
|Architecture|Default Endianness|
|x86/x86_64|Little-Endian|
|ARM (older)|Bi-Endian|
|ARM (modern)|Little-Endian (default, but switchable)|
|PowerPC|Big-Endian|
|MIPS|Bi-Endian|
|SPARC|Big-Endian|
