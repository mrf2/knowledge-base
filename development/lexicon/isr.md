# ISR - Interrupt Service Routines

 * Software driven interrupts are triggered by the **`INT OPCODE`**; e.g. the services provided by **MS-DOS** are called by the software triggering **`INT 21H`** and passing the applicable parameters in CPU registers.
 * An **Interrupt Service Routine (ISR)** is called directly by the CPU, and the protocol for calling an **ISR** differes from calling e.g. a *C function*. An **ISR** has to end with **`iret`** ***opcode*** (or **`iretq`** in long mode - even when using intel syntax), whereas usual C functions end with **`ret`** or **`retf`**. The obvious but nevertheless wrong solution leads to one of the most "popular" triple-fault error.


