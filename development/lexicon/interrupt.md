# Interrupts
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

