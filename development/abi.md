# ABI - Application Binary Interace 
The **Application Binary Interace (ABI)** is a crucial concept in systems programming, especially relevant to topics like:
 * Protocol security and hardening
 * Low-Level programming (C, Assembly, OS internals)
 * Cross-platform software
 * Compiler and linker behavior
 * Function calling conventions, syscalls, and binary compatibility

## ABI Definition
An **ABI (Application Binary Interface)** defines *how binary code interacts* between different program components - e.g., between:
  * A compiled program and the **operating system**
  * A function compiled in one language and called by another
  * A shared library (`.so`, `.dll`) and its caller

## ABI Covers
Here is what an ABI typically includes:

|Category|What Specifies|
|---|---|
|**Data types**|Sizes, alignments, and layouts of `int`, `struct`, `float`, etc.|
|**Calling conventions**|How functions are called - how parameters are passed *(stack/registers)*, who cleans the stack, how return values are returned|
|**Register usage**|Which registers must be preserved by the **callee** vs **caller**|
|**Stack layout**|**Frame pointers, return addresses, padding, alignment**|
|**System call interface**|How to invoke the OS kernel *(e.g. syscall numbers and arguments)*|
|**Dynamic linking**|How shared **libraries** are ***loaded*** and ***symbols*** resolved|
|**Exception handling**|How language runtimes unwind the stack on *error* or *exit*|
|**Name mangling**|For languages like C++ - *how function names are transformed*|


> ***It governs not the source code interface (that is the API) but how compiled machine code works at runtime.***

## Example: x86_64 System V ABI (Linux/Unix)
Most Linux distros on 64-bit use the **System V AMB64 ABI**. It defines:
 * First 6 integer/pointer arguments: passed in `rdi`, `rsi`, `rdx`, `rcx`, `r8`, `r9`
 * Return value in `rax`
 * Stack grows downward, 16-byte aligned
 * Callee-saved registers: `rbx`, `rbp`, `r12-r15`

```assembly
; Example: void foo(int a, int b)
foo:
    mov edi, a      ; first arg in rdi
    mov esi, b      ; second arg in rsi
    call foo
```
```assembly
; Example: void foo(int a, int b)
foo:
    mov edi, a      ; first arg in rdi
    mov esi, b      ; second arg in rsi
    call foo
```

## ABI vs API
|Aspect|ABI|API|
|---|---|---|
|Level|Binary (compiled code)|Source code|
|Use|Link/load-time, runtime compatibility|Compile-time interface|
|Changes|Breaks binary compatibility|Break source compatibility|
|Tools|Linker, loader, debugger|Compiler, headers, IDE|

## Why ABI Matters (especially in Security/Hardening)
 * **Binary exploitation**: ABI knowledge is critical for buffer overflows, Return-oriented Programming (ROP), shellcode
 * **Syscalls and kernel**: ABI defines syscall entry points and register conventions
 * **Library compatibility**: Mismatched ABIs between modules $\rightarrow$ crashes or corruption
 * **Firmware/emulators**: Must match ABI to real hardware
 * **Hardening tools**: `ASLR`, `stack canaries` etc. rely on ABI-preserving behavior

## Common ABIs by Platform
|Platform|ABI|Notes|
|---|---|---|
|Linux x86_64|System V AMD64| Most Unix-like OSes|
|Windows x86_64|Microsoft x64 ABI|Different calling convention|
|ARM (32-bit)|AAPCS|ARM Architecture Procedure Call Std|
|ARM64 (AArch64)|AAPCS64|Used in Linux, Android|
|RISC-V|RISC-V ABI|Newer, designed with simplicity|

