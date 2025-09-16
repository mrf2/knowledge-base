# Base Address Register (BAR) 
# Bus Device Function (BDF)


## What is a BAR (Base Address Register)
 * Every PCI/PCIe device has a **PCI configuration space** (at least 256 bytes, extended to 4KB in PCIe).
 * Inside this config space bar **BARs** (Base Address Registers)
 * A BAR tells the system:
   * Where the devices's **MMIO** (Memomry-Mapped Registers) or I/O ports are mapped in the system address space
   * Whether the mapping is **I/O space** or **Memory space** (most modern devices use memory mapped).
 * Each **BAR** is 32-bit (or 64-bit) wide, and there can be up to **6 BARs** per device.

## Find BARs in Linux
```bash
lspci -v -s <PCI address>

# example
lspci -v -s 03:00.0

# PCI Address format: [bus]:[device].[function]
# Bus (03) --> Which PCI bus the device is on
# Device (00) --> Which slot/device number on that buts (0-31)
# Function (0) --> Which function inside the device (0-7).
```

### Bus
 * PCI supports up to 256 buses (`00h` - `FFh`).
 * Each bus can have up to 32 devices
 * Bus 0 is the **`root bus`** (connected directly to CPU/chipset)
 * Bus 3 means the device is downstream of a bridge (for example, a PCIe root port $\rightarrow$ switch $\rightarrow$ endpoint).

### Device
 * Each bus has up to 32 device slots, numbered 0-31
 * `device 00` means the first slot on bus number for example here, 3.
 * If have have `03:05.0`, that would mean device number 5 on bus 3

### Function
 * A single PCI device can implement up to **8 functions (`0-7`)**
 * Function **`0`** is the primary one.
 * Multi-function device (like some NICs, GPUs, RAID controllers) use multiple function numbers:
   * `03:00.0` $\rightarrow$ NIC's network controller
   * `03:00.1` $\rightarrow$ same chip's management engine or iSCSI offload
