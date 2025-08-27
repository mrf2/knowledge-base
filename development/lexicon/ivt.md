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

## Resources:
 * [OSDev.org/Interrupt_Vector_Table](https://wiki.osdev.org/Interrupt_Vector_Table)
