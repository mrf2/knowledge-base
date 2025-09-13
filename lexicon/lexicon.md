# Systems Programmer's Lexicon
A **map** of the CPU $\leftrightarrow$ OS $\leftrightarrow$ networking $\leftrightarrow$ libraries.

### Each entry could have:
 * **Term:** e.g., Clobbered
 * **Precise Definition:** *formal meaning in systems context
 * **Context:** *CPU, OS, memory, networking etc.*
 * **Why It Matters:** *practical role in execution/security/hardening*
 * **Examples:** *in assembly, C, or kernel docs*k
 * **Related Terms:** *e.g., Trap* $\rightarrow$ *Fault, Execption, Interrupt*
 * **Historical Note:** where the world originated - often from early OS papers

## CPU & Execution Context
 * [**Interrupt** - An asynchronous event from hardware (e.g., *keyboard input, timer ticks*)](interrupt.md)
 * [**Trap** - A synchronous exception caused intentionally be the program (*e.g., system call*)](trap.md)
## Memory & Linking

## OS & Kernel Mechanisms

## Networking & Protocol Stack

## Software Layer
 * [**Firmware**](firmware.md)

## System
 * [**Embedded System**](embedded-system.md)

## Toolchain, ABI, Low-Level Libraries & Compiler-Assembly Interface
 * [**Clobbers:** *register/memory/cc*](clobbers.md)

## Philosophical Engineering

