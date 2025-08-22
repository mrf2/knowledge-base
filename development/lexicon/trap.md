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

## Trap vs. Interrupt vs. Fault
|Term|When it happens|Example|Who causes it|
|---|---|---|---|
|**Interrupt**|Asynchronous, happens between instructions|Timer tick, keyboard input|External hardware|
|**Trap**|Synchronous, *at* an instruction, and usually **intentional**|System call (**`syscall`**, **`int 0x80`**)|Software/program|
|**Fault**|Synchrouns, *at* an instruction, usually **unintentional**|Page fault, divide-by-zero|CPU detecting error|

**Excepton:** ***General umbrella term covering `trap`, `fault`, `abort`, `interrupt`***. So **trap is a kind of exception** that's usually used for *system calls or special instructions*.

## Why do we need traps?
Without traps, user programs would not be able to safely rquest **kernel** services. For example:
 * We want to read from disk $\rightarrow$ but user mode can't directly talk to the disk controller.
 * Instead, we issue a system call (which is implemented as a **trap instruction**).
 * CPU switches to kernel mode, jumps to the system call handler.
 * Kernel does the work, then returns to user mode.

## Example (Linux x86_64 system call flow)
```asm
; User program:
    mov eax, 1          ; syscall number (write)
    mov edi, 1          ; fd = 1 (stdout)
    mov rsi, msg        ; pointer to buffer
    mov edx, len        ; buffer length
    syscall             ; <------ TRAP into kernel

CPU:
    - Switches to kernel mode
    - Saves state
    - Jumps to syscall handler entry in kernel
```
***Here, the `syscall` instruction is literally the `trap into kernel.`***
