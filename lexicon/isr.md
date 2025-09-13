# ISR - Interrupt Service Routines

 * Software driven interrupts are triggered by the **`INT OPCODE`**; e.g. the services provided by **MS-DOS** are called by the software triggering **`INT 21H`** and passing the applicable parameters in CPU registers.
 * An **Interrupt Service Routine (ISR)** is called directly by the CPU, and the protocol for calling an **ISR** differes from calling e.g. a *C function*. An **ISR** has to end with **`iret`** ***opcode*** (or **`iretq`** in long mode - even when using intel syntax), whereas usual C functions end with **`ret`** or **`retf`**. The obvious but nevertheless wrong solution leads to one of the most "popular" triple-fault error.


## When the Handlers are Called
### x86
When the CPU calls the interrupt handlers, the CPU pushes these values onto the stack in this order:
```asm
EFLAGS -> CS -> EIP
```
 * The CS value is padded with two bytes to form a doubleword.
 * If the gate type is not a trap gate, the CPU will clear the interrupt flag. If the interrupt is an **exception**, the CPU will push an error code onto the stack, as a doubleword.
 * The CPU will load the ***segment-selector*** vlue from the associated **Interrupt Descriptor Table (IDT)*** descriptor into **Code Segment (CS)** register. 

### x86-64
When the CPU calls the interrupt handlers, it changes the value in the RSP register to the value specified in the **Interrupt Service Table (IST)**, and if there is none, the stack stays the same. Onto the new stack. The CPU pushes values in this order:
```
SS:RSP (original RSP) --> RFLAGS --> CS --> RIP
```
 * The CS value is padded to form a quadword.
 * Tf the interrupt is called from a different ring, SS is set to 0, indicating a null selector. The CPU will modify the RFLAGS register, setting the **Trap Flag (TF), Nested Task (NT), and Resume Flag (RF)** bits to 0. If the gate type is an interrupt gate, the CPU will clear the interrupt flag.
 * If the interrupt is an exception, the CPU will push an error code onto the stack, padded with bytes to form a quadword.
 * The CPU will load the **segment-selector** value from the associated **IDT** descriptor into CS, and check to ensure that **CS** is a valid code segment selector.





## Resources
 * [OSDev.org/Interrupt_Service_Routines](https://wiki.osdev.org/Interrupt_Service_Routines)
