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
