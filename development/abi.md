# ABI - Application Binary Interace 
It is a set of **rules** that define **how binary code interfaces with the system** and other binary components.
> In short: The **ABI is a contract** between our program and the **OS+CPU+other compiled code**.
## ABI Definition
An **ABI (Application Binary Interface)** defines *how binary code interacts* between different program components - e.g., between:
  * A compiled program and the **operating system**
  * A function compiled in one language and called by another
  * A shared library (`.so`, `.dll`) and its caller

The **Application Binary Interace (ABI)** is a crucial concept in systems programming, especially relevant to topics like:
 * Protocol security and hardening
 * Low-Level programming (C, Assembly, OS internals)
 * Cross-platform software
 * Compiler and linker behavior
 * Function calling conventions, syscalls, and binary compatibility

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
|**Binary Format**|How Symbols, relocations, and linkage work *(e.g. ELF, PE, Mach-O formats)*|
|**VTables and RTTI**|In C++ ABIs: How polymorphism and type info are encoded|


> ***It governs not the source code interface (that is the API) but how compiled machine code works at runtime.***

## Example: x86_64 System V ABI (Linux/Unix)
Most Linux distros on 64-bit use the **System V AMB64 ABI**. It defines:
 * First 6 integer/pointer arguments: passed in `rdi`, `rsi`, `rdx`, `rcx`, `r8`, `r9`
#### Function Arguments:
|Arg #|Register|
|---|---|
|1|`rdi`|
|2|`rsi`|
|3|`rdx`|
|4|`rcx`|
|5|`r8`|
|6|`r9`|
|>6|**On Stack**|
#### Return value
 * In `rax` *(for integers or pointers)*
 * In `rax + rdx` *(for structs with multiple values)*
#### Register Preservation Rules
|Register|Who Save it?|
|---|---|
|`rbx`, `rbp`, `r12-r15`|Callee must save/restore|
|`rax`, `rdi`, `rsi`, `rdx`, `rcx`, `r8`, `r9`, `r10`, `r11`|Caller must assume these may be clobbered|
#### Stack Rule and Alignment
 * Stack grows downward
 * Before `call`, stack **must be aligned to 16 bytes**. *Some Single Instruction, Multiple Data (SIMD) (e.g., Streaming SIMD Extension (SSE) instructions crash if misaligned*
#### Struct and Union Layout
 * Fllows strict rules for:
   * **Alignment** *(e.g, 4-byte or 8-byte)*
   * **Padding**
   * **Endianness** *(little-endian in x86_64)*
 * Ensure **interoperability** between separately compiled modules
#### Example
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

