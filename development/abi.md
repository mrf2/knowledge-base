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

