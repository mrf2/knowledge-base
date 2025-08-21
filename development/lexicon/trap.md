# `trap`

## What is a *trap*?
 * A **trap** is a kind of **control transfer from user mode to kernel mode** triggered by the CPU when a specific condition occcurs.
 * It is eseentially a **synchronous exception** - meaning it happens at the *instruction being executed* (*not randomly later, like interrupts can*).
### Example:
***CPU instruction to trap into kernel***, it means: An instruction causes the CPU to stop executing in user mode and start execution in the kerne at a predefined handler address.

## How does a *trap* happen?
There are three major ways:
 1. **Intentional (software instruction):** User programs explicitly request kernel service with a *trap instruction*.
    * Example on x86: `int 0x80` (old Linux **syscall** mechanism)
    * Example on x86_64: `syscall` instruction. <br> These are not "errors" - they are *deliberate transitions into the kernel*.
 2. **Unintentional (faults/errors):** The CPU detects something invalid while executing an instruction, and *traps* into the kernel to handle it.
    * Example: divide-by-zero $\rightarrow$ triggers a trap into the kernel's divide error handler
    * Examplek: page fault (accessing unmapeed memory)
 3. **Debug/monitor traps:** Some CPUs support traps for debugging, like single-step execution.
