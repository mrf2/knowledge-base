# elf - Executable and Linkable Format

## High-Level Summary of a Function Call in x86_64 (Linux, ELF, GCC)
When a function is called:
 1. Some arguments are passed via **registers**, *(rdi, rsi, etc.)*.
 2. Some are passed via the **stack**.
 3. A **stack frame** is created *(optionally using* ***rbp*** *as a frame pointer)*. 
 4. Return address is pushed automatically by `call`.
 5. Return value is passed back via **registers**.

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
