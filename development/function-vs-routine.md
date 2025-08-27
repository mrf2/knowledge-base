# Function vs Routine
# function-vs-routine.md
In **Low-level programming**, especially OS kernels, firmware, assembly, and early systems literature, the word **routine** comes up more often that "function".

## 1. General Meaning
 * **Function**
   * A ***function*** is usually defined as a named block of code that takes inputs (parameters), performs computation, and may return a value.
   * $\rightarrow$ Concept comes from **mathematics:** a function maps input(s) $\rightarrow$ output.
 * **Routine**
   * A ***routine*** is a more general term for any sequence of instructions grouped together to accomplish a task.
   * $\rightarrow$ Historically comes from **early programming** (1950s-1970s), where prorammers spoke of "subroutines" or "service routines" instead of "function"

## 2. Hierarchy of Terms
 * **Routine (generic)**
   * **Subroutine** *(called from elsewhere, may return control)*
   * **Procedure** *(a subroutine **without** a return value, just does work)*
   * **Function** *(a subroutine **with** a return value, consistent with math)*
   * **ISR (Interrupt Service Routine)** *(special subroutine invoked by hardware interrupt)*

So:
 * Every **function** is a routine.
 * Not every **routine** is a **function** (some don't return values, like ISRs).

## 3. In High-Level Languages (C, Pascal, etc.)
 * **C language:** Everythin is called a ***function***, even if it doesn't return a value (e.g., `void foo(void)` is still a **"function"**).
 * **Pascal/Ada:** Distinguish between:
   * `procedure` (*no return value*)
   * `function` (*returns a value*)
 * **Assembly/Low-level docs:** Use the word ***routine*** instead, because these languages don't inherently encode the *"return value"* concept - they just jump somewhere, run code, then return.

## 4. In Low-level/OS Context
This is where we see ***routine*** most often:
 * **ISR (Interrupt Service Routine):** Handles hardware interrupt, doesn't return a valuein the high-level sense, just acknowledges hardware.
 * **Startup Routine:** Code executed at reset (sets up stack, copies segments, jumps to main).
 * **Memory Management Routine:** Performs a service (like allocate/free) but not necessarily "functional" in math terms.

The term ***routine*** emphasizes **control flow** and **behavior**, not "input $\rightarrow$ output" mapping.

## 5. Historical Reason
 * In early assembly and FORTRAN manuals (1950s-1970s), programmers wrote "subroutines".
 * "Function" only became dominant with **structured programming** and C-like languages.
 * Kernel developers, BIOS writers, and microcontroller programmers still say **routine** becase:
   * Much of the code does not return a meaningful value.
   * It reflects older terminology in documentation and hardware manuals.

## 6. Summary
|Term|Returns Value?|Context/Example|
|---|---|---|
|Routine|Maybe/maybe not|Generic term for any block of reusable code.|
|Subroutine|Usually returns control, but not necessarily a value|Assembly **`CALL`/`RET`** sequences.|
|Procedure|No return value|Pascal `procedure InitScreen;`|
|Function|Yes, return value|C `int add(int a, int b);`|
|Service Routine|Often system/hardware task|BIOS disk routine, ISR, kernel routine|

---
## Code Example
### 1. C "Function" Example
#### C Code
```
int add(int a, int b)
{
    return a + b;
}
```
#### x86-64 Assembly (AT&T syntax, simplified)
```asm
add:                        # Label (compiler calls this a "function")
    push    %rbp                # push the caller stack base address (pointer)
    mov     %rsp, %rbp          # set new stack pointer
    mov     %edi, -4(%rbp)      # a
    mov     %esi, -8(%rbp)      # b
    mov     -4(%rbp), %edx      # move a to EDX register
    add     -8(%rbp), %edx      # add b to the content with EDX, which is EDX = a + b
    mov     %edx, %eax          # return value in %eax
    pop     %rbp                # geeting ready for return: restore caller stack
    ret
```
#### Key Point
 * Caller expects a **return value** in **`%eax`**.
 * This matches the ***mathematical idea of a function:*** inputs $\rightarrow$ output.

So, C calls this a function
---
### 2. C "Void Procedure" Example
#### C Code
```c
void print_hello(void)
{
    puts("Hello");
}
```
#### x86-64 Assembly (simplified)
```asm
print_hello:                    # Label
    push    %rbp                # push the caller stack base address (pointer)
    mov     %rsp, %rbp          # set new stack pointer
    lea     msg(%rip), %rdi     # argument to puts
    call    puts
    pop     %rbp                # geeting ready for return: restore caller stack
    ret
```
#### Key Point
 * There's **no return value** (except the implicit `ret` of control flow).
 * In Pascal/Ada this would be called a **procedure**.
 * In assembly manuals we often see this called a **routine**.
---
### 3. Interrupt Service Routine (ISR)
This is where the term ***routine*** dominates in low-level programming.

#### Pseudocode **`INTEL SYNTAX`** (x86 Real Mode ISR for timer tick)
```asm
; INTEL SYNTAX
timer_routine:                  ; hardware calls this on IRQ0
    push ax
    push bx
    ; do timer tick handling
    inc WORD [tick_count]
    mov al, 0x20
    out 0x20, al                ; send EOI (End Of Interrupt) to PIC
    pop bx
    pop ax
    iret                        ; special return-from-interrupt
```
#### Step-by-Step Explanation
Let's *dissect line-by-line* the above assembly snippet (`timer_routine` **ISR**). This is typical **x86 real-mode** assembly code that would be used in a bootloader, DOS TSR, or OS kernel to handle the hardware timer interrupt (IRQ0).

 * **`timer_routine:`**
   * This is a **label** that marks the start of the **Interrupt Service Routine (ISR)**.
   * The **Programmable Interrupt Controller (PIC)** (Intel 8259) has an **Interrupt Vector Table (IVT)** entry pointing here.

#### Key Point
 * This is **never a function** in the C sense:
   * It doesn't take arguments normally
   * It doesn't return a value.
   * It's entered by **hardware** (via interrupt vector table), not by `call`
 * That's why it's always called an **Interrupt Service Routine (ISR)**.
---
### 4. Startup Routine
Before **`main()`** even runs in C, our program executes a **startup routine** (provided by `libc` or `crt0`).

#### Simplified (x86-64)
```asm
_start:                         # Entry point, a routine
    xor     %rbp, %rbp
    mov     %rsp, %rdi          # pass argv to main
    call    main
    call    exit                # never returns
```
 * `_start` is never called by we.
 * It never returns normally (it calls `_exit`).
 * It is not a **function**. It is a **startup routine**.

#### 4. Summary: Why Assembly Programmers Say "Routine"
|Example|Assembly Behavior|Name used|
|---|---|---|
|`int addr(int, int)`|Returns value in register|Function|
|`void print_hello(void)`|No return value, just side effect|Procedure/Routine|
|Interrupt handler (`ISR`)|Hardware entry, `iret` return|Routine|
|`_start` boot entrypoint|No caller, no return|Routine| 

So, in **low-level programming** we say ***routine*** because:
 * Not everything fits the ***"function returns a value"*** model.
 * Hardware (*interrupt, reset, syscalls*) invokes code without the high-level function calling convention.
 * **"Routine"** is the **most generic** word: ***any code block, callable or not, value or not***.

