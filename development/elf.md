# elf - Executable and Linkable Format

## High-Level Summary of a Function Call in x86_64 (Linux, ELF, GCC)
When a function is called:
 1. Some arguments are passed via **registers**, *(rdi, rsi, etc.)*.
 2. Some are passed via the **stack**.
 3. A **stack frame** is created *(optionally using* ***rbp*** *as a frame pointer)*. 
 4. Return address is pushed automatically by `call`.
 5. Return value is passed back via **registers**.
---

## Registers Involved (According to SysV AMD64 ABI)
|Purpose|Register|
|---|---|
|1st Argument|`rdi`|
|2nd Argument|`rsi`|
|3rd Argument|`rdx`|
|4th Argument|`rcx`|
|5th Argument|`r8`|
|6th Argument|`r9`|
|Return value|`rax`|
|Callee-saved ***(must be preserved)***|`rbp`, `rbx`, `r12`-`r15`|
|Caller-saved ***(can be clobbered)***|`rax`, `rdi`, `rsi`, `rdx`, `rcx`, `r8`, `r9`, `r10`, `r11`|
|Stack pointer|`rsp`|
|Base/frame pointer| `rbp` (optional in `x86_64`)|
----


## Why is `rbp` optional in x86_64?
### Short Answer:
In x86_64 (unlike x86), using `rbp` as a frame pointer is optional because:
 * The **stack pointer (** `rsp` **)is reliably aligned** *(to 16 bytes).*
 * `rbp` can be **freed for general use**.
 * Modern compilers often use **frame pointer omission (FPO)** to **optimize performance** and **save space**.
### Details:
 * In traditional x86 (32-bit), `ebp` was essential for
   * Creating a stable **base for local variables** and arguments (since `esp` changes during `push`/`pop`).
   * Providing a fixed reference point for *debuggers*, *stack tracing*, etc.
 * **In x86_64:**
   * The ABI requires **stack alignment** and stricter calling conventions.
   * `rsp` becomes **stable enough** to index locals/agrs directly with offsets like `[rsp + 8]`.
   * Compilers now **track stack offsets** for locals without needing a dedicated `rbp`.
i 
 * **Befefits of ommiting `rbp`:**
   * **Frees up** `rbp` as a *15th general-purpose register*.
   * **Reduces instruction count** (no `push rbp`/`mov rbp, rsp`/`pop rbp`).
   * Makes code **smaller and faster**.
 * **Trade-off:**
   * Harder to **trace call stack** in debugging or crash analysis.
   * So debug builds **retain** `rbp` as frame pointer (via `-fno-omit-frame-pointer`).

### GCC Example:
#### Compiled with *no frame pointer*
```bash
gcc -g -fomit-frame-pointer test. -o test
objdump -d test
```
An there, `rbp` **is not used**, and everything references `rsp`.

#### Compiled with *frame pointer*
```bash
gcc -g -fno-omit-frame-pointer test.c -o test
objdump -d test
```
Now, there will be **use of** `rbp` 


---
## Typical Stack Frame Layout
Assuming the function uses a frame pointer (`rbp`), the stack frame during execution of function looks like this (top is higher memory):
```bash
+--------------------+      <-- previous %rbp (saved)
|   Saved RBP        |
+--------------------+
|   Return Address   |      <-- pushed by "call"
+--------------------+
|   Local variables  |
|   ...              |
+--------------------+      <-- current %rsp
```
If no frame pointer is used *(frame pointer omission optimization)*, `%rbp` may be used as a **general-purpose register**.

## Step-by-Step Function Call Example
Suppose we have:
```c
int add(int a, int b)
{
    int sum = a + b;
    return sum;
}

int main()
{
    int result = add(10, 20);
    return result;
}
```

### How `main()` calls `add()` (simplified):
#### 1. Arguments `10` and `20` $\rightarrow$ passed via:
 * `rdi` = 10
 * `rsi` = 20
#### 2. Call instruction:
```asm
call add
```
 * Pushes return address onto the stack (`[rsp]`)
#### 3. Insdie `add`:
 * Save `rbp` *(if used)*:
```asm
push rbp
mov rbp, rsp
```
 * Do computation:
```asm
mov eax, edi        ; a into eax
add eax, esi        ; eax = a + b
```
 * Result in `eax` *(same as * `rax` *)*
 * Epilogue: 
```asm
pop rbp
ret
```

## With Local Variables
Local variables go on the stack *(if not optimized out or kept in registers)*. Space for them is reserved by ***subtracting*** from `rsp`.
```asm
sub rsp, N          ; Allocate N bytes for locals variables
```
E.g., `int arr[10];` would need 40 bytes on 64-bit (`10 * 4` or aligned to 16-byte boundary) machine.

## Stack Alignment
The System V ABI requires the stack to be **16-byte aligned** before a call instruction. GCC ensures this by ***adjusting*** ***`rsp`*** as needed.

## Disassembly Example (GCC)
```asm
<memory_address> <add>:
    <address>: 55           push rbp
    <address>: 48 49 e5     mov rbp, rsp
    <address>: 89 f8        mov eax, edi
    <address>: 01 f0        add eax, esi
    <address>: 5d           pop rbp
    <address>: c3           ret
``` 

## Summary: Key Stack Frame Concepts
|Component|Purpose|
|---|---|
|`call` instruction| Pushes return address onto the stack|
|`push rbp` + `mov rbp, rsp`| Save old frame pointer and set new one|
|Function arguments|First *6* in *registers* (`rdi` - `r9`), *reset on the stack*|
|Local variables|*Allocated on stack* via `sub rsp, N`|
|`ret` instruction|Pops return address from stack|
|Stack alignment|*16-byte alignment* before function call|

