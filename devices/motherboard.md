# Motherboard

## **`dmidecode`**
**`dmidecode`** is a tool for dumping a computer's DMI(Desktop Management Interface) (some say SMBIOS) table contents in a human-readable format. This table contains a description of the system's hardware components, as well as other useful pieces of information such as serial numbers and bios revision.

### Example Use:
 * **Base Board Information**: `#dmidecode --type baseboard`
 * **BIOS Version**: `# dmidecode --type 0`

### DMI TYPES
The SMBIOS specification defines the following DMI types:
|Type|Information|
|---|---|
|0|BIOS|
|1|System|
|2|Baseboard|
|3|Chassis|
|4|Processor|
|5|Memory Controller|
|6|Memory Module|
|7|Cache|
|8|Port Controller|
|9|System Slots|
|10|On Board Devices|
|11|OEM String|
|12|System Configuration Options|
...
