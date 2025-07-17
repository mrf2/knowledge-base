# Memory Layout
 * String literals,like `char *str = "hello world!";` stored in **text/code segment**
 * A `static` local variable in a function (or a global variable) lives in:
   * `.bss` **if uninitialized**
   * `.data` **if initialized**
   * It is **not on the stack**. Its address is determined at **link/load time**, and it stays fixed during the entire.


### Stack vs Static
|Type|Lifetime|Storage Area|Addressing Style (x86_64)|
|---|---|---|---|
|Stack Variable|Function lifetime|Stack|`rbp-relative` (e.g., `-0x4c`)|
|`static` Variable|Program lifetime|`.bss` or `.data` segment|**Absolute address** via *lebel* (e.g., `buf(%rip)`)|


### Static Memory vs Stack vs Heap
|Memory Type|Keyword|Lifetime|Thread Safety|Reentrancy-Safe?|
|---|---|---|---|---|
|Static|`static` or global|Whole program|No (shared)|No (usually)|
|Stack|Local variables|Per function call|If each thread has its own|Yes|
|Heap|`malloc()`/`new`|Until `free()`/`delete`|If isolated|Yes|
