# Runtime
## What can ***actually*** execute code?
Only **hardware** executes instructions.
```bash
CPU executes machine instructions
```
Everything else exists to **prepare, translate, schedule, or restrict** those instructions.

So the cain is:
```bash
My Code
   ↓
something translates/manages it
   ↓
machine instructions
   ↓
CPU
```
That **something** is where **runtime** and **virtual machine** appear.


## What is **runtime**?
A **runtime** is:
The **execution environment** that exists **while a program is running**, responsible for:
 * loading the program
 * managing memory
 * providing system services
 * controlling execution rules
Key point: **Runtime exists only when the program is running**

Not before. Not after. 
---
### Minimal example (C):
```c
int main() {
    return 0;
}
```
Where is the runtime here?
 * OS loader
 * C runtime startup (`_start`)
 * stack setup
 * system calls
Even **C has a runtime**, just a *very thin one*.
So:
❌ "C has no runtime" $\rightarrow$ false
✅ "C has a minimal runtime" $\rightarrow$ correct.

### Runtime ≠ Language
This is where confusion usually begins.
|Thing|Is it a runtime?|
|---|---|
|C|❌|
|Java|❌|
|JavaScript|❌|
|Python|❌|

Language **do not run**
They are **executed by a runtime**

## What a runtime actually does (mechanically)
A runtime typically provides:
 1. Code loading
 2. Memory Management
 3. Execution rules
 4. System interface
 5. Error handling
 6. Lifecycle control
Different runtimes provide **different levels** of these.
