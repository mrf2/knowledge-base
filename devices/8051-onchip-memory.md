# 8051 On-Chip Memory

## 8051 Registers Banks
 * The **8051 has 32 bytes on-chip RAM (0x00 - 0x1F)** reserved for working registers.
 * These ***32 bytes are divided into 4 banks*** (Bank 0 to Bank 3), each with **8 registers (R0-R7)**:
   1. Bank 0 $\rightarrow$ 0x00 - 0x07
   2. Bank 1 $\rightarrow$ 0x8 - 0x0F
   3. Bank 3 $\rightarrow$ 0x10 - 0x17
   4. Bank 4 $\rightarrow$ 0x18 - 1F
 * At any time, the CPU only sees **one bank as `R0-R7`**
 * The currently active bank is chosen by **PSW (Program Status World) bits RS1 and RS0:**
   
### Register Bank Select
|PSW.4 (RS2)|PSW.3 (RS1)|Bank|Address Range|
|---|---|---|---|
|0|0|Bank 0|0x00 - 0x07|
|0|1|Bank 1|0x08 - 0x0F|
|1|0|Bank 2|0x10 - 0x17|
|1|1|Bank 3|0x18 - 0x1F|

## Why did Intel design ***four*** banks?
 1. **Fast Context Switching (Interrupts):**
    * In embedded systems, interrupts are frequent (timers, UART, external events)
    * Normally, when an interrupt fires, we'd need to save registers (push R0-R7 onto stack) and restore them later.
    * With multiplef, banks, the CPU can just **switch to another register bank** inside the ISR - no need to save/restore the working registers.
    * This makes interrupt latency much shorter and predictable
    * **Example:**
      * Main program $\rightarrow$ uses *Bank 0*
      * Timer interrutp $\rightarrow$ switches to *Bank 1* automatically ***(by setting PSW bits at ISR entry)***.
     * UART interrupt $\rightarrow$ uses *Bank 2*
     * Each routine has its own **private R0-R7**, no stack pushes needed.
 2. **Small Code Footprint**
    * In the late 70s RAM and ROM were both tiny and expensive
    * Pushing/popping registers to the stack consumes instructions (PUSH, POP), which take program memomy and cycles
    * Seperate banks lets small real-time systems run with minimal code overhead.
 3. **Flexibility for Multi-Tasking**
    * The designer could dedicate each bank to a specific "task" or "mode".
    * **Example:**
      * Bank 0 $\rightarrow$ foreground task
      * Bank 1 $\rightarrow$ background task
      * Bank 2 $\rightarrow$ serial communication
      * Bank 3 $\rightarrow$ emergency/critical routines
    * *This made cooperative or interrupt-driven multitasking much simpler on the 8051*.
