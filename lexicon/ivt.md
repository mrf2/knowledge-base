# IVT - Interrupt Vector Table
On the x86 architecture, the **Interrupt Vector Table (IVT)** is a table that specifies the addresses of all the 256 interrupt handlers used in **read mode**.

The **IVT** is typically located at `0000:0000H`, and is `400H` bytes in size (*4 bytes for each interrupt*). Although the default address can be changed using the **Load Interrupt Descriptor Register (LIDT)** instruction on newer CPUs, this is usually not done because it is both inconvenient and incompatible with other implementations and/or older software (e.g. *MS-DOS programs*). However, the code must remain in the **first MiB of RAM**.

##Structure
The entries are consecutive, meaning the first entry pointed by the **Interrupt Descriptor Table Register (IDTR)** is interrupt handler 0, and the others follow in succession. The format of an entry is:
```c
+------------+------------+
|  Segment   |  Offset    |
+------------+------------+
4            2            0
```
We can therefore see that it's really easy to get the address of the interrupt handler we are looking for: $IDRT \times 4$. In order to change an **interrupt handler**, all that needs to be done is to change its address in the table.

## CPU Interrupt Layout
|IVT Offset | INT #|Description|
|---|---|---|
|0x0000|0x00|Divide by 0|
|0x0004|0x01|Reserved|
|0x0008|0x02|Non-Maskable Interrupt (NMI)|
|0x000C|0x03|Breakpoint (INT3)|
|0x0010|0x04|Overflow (INT0)|
|0x0014|0x05|Bounds range exceeded (BOUND)|
|0x0018|0x06|Invalid opcode (UD2)|
|0x001C|0x07|Device not available (WAIT/FWAIT)|
|0x0020|0x08|Double fault|
|0x0024|0x09|Coprocessor segment overrun|
|0x0028|0x0A|Invalid Task State Segment(TSS)|
|0x002C|0x0B|Segment not present|
|0x0030|0x0C|Stack-segment fault|
|0x0034|0x0D|General protection fault|
|0x0038|0x0E|Page fault|
|0x003C|0x0F|Reserved|
|0x0040|0x10|0x87 Floating Point Uinit (FPU) error|
|0x0044|0x11|Alignment check|
|0x0048|0x12|Machine check|
|0x004C|0x13|Single Instruction Multiple Data (SIMD) Floating-Point Exception|
|0x00XX|0x14-0x1F|Reserved|
|0x0XXX|0x20-0xFF|User definable|

## Default Hardware Interrupt Layout
**Master 8259:**

Some interrupts mapped by the 8259 by default overlap with some of the processor's exception handlers. These can be remapped via the 8259's IO ports.

|IVT Offset|INT #|IRQ #|Description|
|---|---|---|---|
|0x0020|0x08|0|PIT|
|0x0024|0x09|1|Keyboard|
|0x0028|0x0A|2|8259A slave controller|
|0x002C|0x0B|3|COM2/COM4|
|0x0030|0x0C|4|COM1/COM3|
|0x0034|0x0D|5|LPT2|
|0x0038|0x0E|6|Floppy controller|
|0x003C|0x0F|7|LPT1|

**Slave 8259:**
|IVT Offset|INT #|IRQ #|Description|
|---|---|---|---|
|0x01C0|0x70|8|RTC|
|0x01C4|0x71|9|Unassigned|
|0x01C8|0x72|10|Unassigned|
|0x01CC|0x73|11|Unassigned|
|0x01D0|0x74|12|Mouse controller|
|0x01D4|0x75|13|Math copprocessor|
|0x01D8|0x76|14|Hard disk controller 1|
|0x01DC|0x77|15|Hard disk controller 2|


## Resources:
 * [OSDev.org/Interrupt_Vector_Table](https://wiki.osdev.org/Interrupt_Vector_Table)
