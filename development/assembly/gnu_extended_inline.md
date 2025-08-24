# GNU extended inline asm *(GCC/Clang feature)*, written in **GAS's AT&T dialect**

## Example
```c
int foo(int x) {
    int y;
    asm("movl %1, %%eax; addl $5, %%eax; movl %%eax, $0"
        : "=r"(y)           // outputs
        : "r"(x)            // inputs
        : "%eax"            // clobbers
    );
    return y;
};
```

### What kind of asm is this?
 * This is **extended asm:** **`asm("TEMPLATE": OUTPUTS : INPUTS : CLOBBERS);`** *(There's also* `asm goto` *which adds a labels field.)*
 * The template itself uses **AT&T syntax** (*GAS default on x86*): registers are written with `%` (e.g. `%eax`), immediates use `$` (e.g. `$5`), and the operand order is **source, destination** (opposite of **Intel**). The `l` in **`movl/addl`** is the 32-bit size suffix.

### Placeholders & escaping
 * `%0`, `%1`, ... refere to C operands by index: **all outputs are numbered first** *(left to right)*, then the inputs. Here `%0` $\rightarrow$ *(the only output)*, `%1` $\rightarrow$ *(the first input)*.
 * `%%` in the template becomes a literal `%` in the assembled code, so `%%eax` prints `%eax`.

### Constraints
 * `=r` on `y` says: *this is an output-only operand ( `=` ) that must live in a general register (`r`)*.
 * `"r"(x)` syas: *copy `x` into some general register for input*.
 * The **clobber list** tells lthe compiler which regs/flags/memory are **destroyed** by the asm but not listed as outputs. Here `%eax` is declared clobbered so the compiler won't keep anything live there across the asm. (Canonical spelling is `"eax"` without `%`). Typical clobbers also include **`"cc"`** *(condition codes)* and **`"memory"`**.

### What the instructions do (AT&T order = src, dst):
 * `movl %1, %%eax` $\rightarrow$ `eax = x`
 * `addl $5, %%eax` $\rightarrow$ `eax += 5`
 * `movl %%eax, %0` $\rightarrow$ `y = eax`

## Assign operand numbers order: Output first
When GCC/Clang parse an **extended inline asm** statement, they assign operand numbers in order:
 1. **Outputs first** *(from left to right)*.
    * The first output is `%0`.
    * The second output would be `%1`, and so on.
 2. Then comes the **inputs** (*again from left to right*). 
    * If we have one output, then the *first input* will be `%1`.
    * If we have two outputs, then the *first input* will be `%2`, etc.
So, in our example:
 * `%0` $\rightarrow$ `y` *(the first and only output)*
 * `%1` $\rightarrow$ `x` *(the first input, which comes **after** the outputs)*
### Rule of thumb:
 * Numbering starts at zero with the **first output**.
 * Inputs are numbered **after all outputs**.
 * So **`%N`** always means "the N-th operand in the combined list (outputs first, then inputs)."
---
### Example 1: One output, one input
**Goal:** `result = input_val + 5`
```c
int input_val = 7;
int result;

asm("movl %1, %0; addl $5, %0"
    : "=r"(result)          // %0 --> result (output #0)
    : "r"(input_val)        // %1 --> input_val (intput #1)
    : "cc");

// result == 12
```
 * `%0` $\rightarrow$ `result`
 * `%1` $\rightarrow$ `input_val`
---

### Example 2: Two outputs, one input
**Goal:** copy `src` into both `dst_a` and `dst_b`
```c
int src = 42;
int dst_a, dst_b;

asm("movl %2, %0; mov %2, %1"
    : "=r"(dst_a), "=r"(dst_b)          // %0 --> dst_a, %1 --> dst_b
    : "r"(src));                        // %2 --> src

// dst_a == 42, dst_b == 42
```
 * `%0` $\rightarrow$ `dst_a`
 * `%1` $\rightarrow$ `dst_b`
 * `%2` $\rightarrow$ `src`
---

### Example 3: Two outputs, two inputs
**Goal:** `sum = a + b`, `diff = a - b`
```c
int a = 10, b = 3;
int sum, diff;

asm("movl %2, %0; addl %3 %0;"      // sum = a; sum += b;
    "movl %2, %1; subl %3, %1;"     // diff = a; diff -= b;
    : "=r"(sum), "=r"(diff)         // %0 --> sum, %1 --> diff
    : "r"(a), "r"(b)                // %2 --> a, %3 --> b
    : "cc");

// sum == 13, diff == 7
```
 * `%0` $\rightarrow `sum`
 * `%1` $\rightarrow `diff`
 * `%2` $\rightarrow `a`
 * `%3` $\rightarrow `b`
---

### Example 4: Read-modify-write output (the `+` constraint)
**Goal:** increment `accumulator` by `delta` in-place
```c
int accumulator = 100;
int delta = 23;

asm("addl %1, %0"
    :"=r"(accumulator)          // %0 --> accumulator (read+write)
    :"r"(delta)                 // %1 --> delta
    :"cc");

// accumulator == 123
```
 * `"+r"` means `%0` starts with `accumulator` and is written back.
---

### Example 5: Matching constraint (tie an input to a specific output)
**Goal:** `sum = x + y` where we first load `x` into `sum`, then add `y`

```c
int x = 5, y = 8;
int sum;

asm("movl %1, %0; addl %2, %0"
    : "=r"(sum)             // %0 --> sum (output)
    : "0"(x),               // %1 --> x, but force SAME reg as %0 ("0" maches output #0)
    : "r"(y)                // %2 --> y
    : "cc");

// sum == 13
```
 * The input constraint `"0"(x)` says: "use the **same register** as output #0."
---

### Example 6: Named operands (avoid counting entirely)
Same as #3, but with **named** placeholders for clarity.
```c
int a = 10, b = 3;
int sum, diff;

asm("movl %[A], %[SUM]; addl %[B], %[SUM];"
    "movl %[A], %[DIFF]; subl %[B], %[DIFF]"
    : [SUM]"=r"(sum), [DIFF]"=r"(diff)
    : [A]"r"(a), [B]"r"(b)
    : "cc");

// sum == 13, diff = 7
```
 * In the template, `%[SUM]`, `%[DIFF]`, `%[A]`, `%[B]` refer directly to the named operands
---
### Example 7: Same idea in Intel syntax for one example
For Intel syntax, bracket the template with `.intel_syntax`/`.att_syntax`:
```c
int input_val = 7;
int result;

asm volatile(
    ".intel_syntax noprefix\n"
    "mov %0, %1\n"
    "add %0, 5\n"
    ".att_syntax prefix\n"
    : "=r"(result)
    : "r"(input_val)
    : "cc");

// result == 12
```

