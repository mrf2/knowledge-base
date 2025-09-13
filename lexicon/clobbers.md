# Clobbered
 * **Definition:** In compiler/assembly contexts, **clobbered** means that a register, memory location, or variable is **overwritten (destroyed)** by an instruction or inline assembly block, so its previous contents cannot be relied upon afterward.
 * **Context:**
   * **Compilers:** GCC/Clang inline assembly, register allocation
   * **Calling conventions:** Which registers a function may overwrite
   * **System programming:** Low-level debuggin, writing syscalls, libc internals
 * **Why It Matters:**
   * If we don't tell the compiler which registers our inline assembly clobbers, the compiler might assume they'are preserved and use them, leading to subtle, catastrophic bugs.
   * At the ABI level, certain registers are designated **caller-saved** (a.k.a clobbered across function call).
 * **Examples:**
   1. **Inline Assembly in GCC**
```c
int value;
asm volatile("movl $42, %0"
            : "=r"(value)           // output
            :                       // input
            : "eax");               // clobbered register
)
```
Here, `"eax"` is declared clobbered because the assembly overwrites it.
   2. **Callling Convention (x86-64 System V ABI)**
      * Caller-saved (clobbered) registers: **`rax`, `rcx`, `rdx`, `rsi`, `rdi`, `r8-r11`**.
      * Callee-saved (preserved) registers: **`rbx`, `rbp`, `rsp`, `r12-r15`**
 * **Related Terms:**
   * **Caller-saved register** *(the caller must save it if needed)*
   * **Callee-saved register** *(function must restore it)*
   * **Volatile** *(keyword often tied to side effectss in inline assembly)*
