# IDT - Interrupt Descriptor Table
The **Interrupt Descriptor Table (IDT)** is a binary data structure specific to the **IA-32** and **x86-64** architectures. It is the **Protected Mode** and **Long Mode** counterpart to the **Real Mode** **Interrupt Vector Table (IVT)** telling the CPU where the **Interrupt Service Routine (ISR)** are located ***(one per interrupt vector)***. It is similar to the **Global Descriptor Table** in structure.

The IDT entries are called **gates**. It can contain:
 * **Interrupt Gates**
 * **Task Gates**
 * **Trap Gates**

*Before we implement the IDT, we should have a working Global Descriptor Table (GDT)*
