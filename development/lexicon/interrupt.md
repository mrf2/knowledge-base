# Interrupts
**Interrupts** are a mechanism that allow the CPU temporarily to halt what it is doing and run some other, higher-priority instructions before returning to the original task. An **interrupt** could be raised either by a software instruction (e.g. **`int 0x10`**) or by some hardware devices that requires high-priority action (e.g. *to read some incoming data from a network device*).
 * Each interrupt is represented by a unique number that is an index to the interrupt vector, a table initially set up by **BIOS** at the start of memory (i.e. *at physical address 0x0*) that contains address pointers to ***Interrupt Service Vector (ISRs)***. 
   * An **ISRs** is simply a sequence of machine instructions, much like boot sector code, that deals with a specific interrupt (e.g. *read new data from a disk drive or from a network card*).
   * **BIOS** adds some of its own ISRs to the interrupt vector that specialize in certain aspects of the computer, for example: interrupt **`0x10`** causes the screen-related ISR to be invoked; and interrupt **`0x13`**, the disk-related I/O ISR.
   * However, it would be wasteful to allocate an interrupt per **BIOS** routine, so **BIOS** multiplexes the ISRs by what we could imagine as a big **`switch`** statement, based usually on the value set in one of the CPUs general purpose registers, **`ax`**, prior to raising the interrupt.


**Interrupts** are signals from a device, such as a keyboard or a hard drive, to the CPU, telling it to immediately stop whatever it is currently doing and do something else. For example, a keyboard controller can send an interrupt when a character key was pressed. Then the OS can display the character on screen immediately, even if the CPU was doing something completely unrelated before, and return to what it was doing afterwards.
 * When a specific ***interrupt*** arises, the CPU looks up an entry for that specific ***interrupt*** from a table provided by the OS.
 * In **x86 protected mode** the table is called the **Interrupt Descriptor Table (IDT)** and can have up to 256 entries, but the name of this table and the maximum number of entries it can have differ based on the CPU architecture.
 * After the CPU finds the entry for the interrupt, it jumps to the code the entry points to. This code that is run in response to the interrupt is known as a **Interrupt Service Route (ISR)** or an **Interrupt Handler**.
 * For the system to know which interrupt service routine to call when a certain interrupt occurs, offsets to the **ISR**s are stored in the **Interrupt Descriptor Table** when we'are in **Protected Mode**, or in the **Interrupt Vector Table** when we are in **Real Mode**.

## Examples
 * Every time we press a key, the  keyboard triggers Interrupt Request 1 (IRQ1), and the corresponding interrupt handler is called.
 * **Timers** and **disk request** completion are other possible sources of **hardware interrupts**.

## Abbreviation
 * **IRQ1:** Interrupt Request 1



# Resources
 * [OSDev.org/Interrupts](https://wiki.osdev.org/Interrupts)

