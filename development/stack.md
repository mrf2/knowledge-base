# stack

## Why stacks grow downword?
 * Historically, to **maximize memory layout flexibility**:
   * **Code** *(.text)* at low memory
   * Heap grows **upward**
   * Stack grows **downward**

$\rightarrow$ This way they move toward each other, allowing dynamic use of space in between.


