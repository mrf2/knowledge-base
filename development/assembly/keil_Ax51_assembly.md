# Keil Ax51 Assembly

## Directives
 * **DS** (Define Storage) - The **`DS`** directive is used to reserve uninitialized space for variables, buffers, or other data structures. The size of reserve space is determined by the numeric expression that follows it. For example **`DS 1`**, the expression is **`1`**, meaning a single byte is reserved.

Example:
```assembly
; Select the internal data memory segment
DSEG

; Reserve a single byte of internal RAM at the current location counter
counter: DS 1

; Later in cod, we can use the label 'counter'
; For instance, to increment the reserved byte
INC counter
```

 * **Key Aspects of `DS 1`**
   * **Memory segment:** The memory segment where the byte is reserved depends on the active segment directive (`DESG`, `BSEG`, `XSEG`, `ISEG`, `CSEG`) in effect at that point in the code.
     * **`DESG`** (Data Segment) reserves space in the 8051's internal data RAM.
     * **`XSEG`** (External Data Segment) reserves space in external RAM.
   * **Uninitialized:** The **`DS`** directive does not write any data to the reserved memory location, so the initial value of the reserved byte is undefined. If we need to initialize memory with a specific value, we would use a directive like **`DB`** (Define Byte).
   * **Location Counter:** The assembler's location counter is incremented by 1 after processing **`DS 1`**, ensuring that the next instruction or directive starts at the subsequent memory address.
   * **Symbolic name:** Using a label like **`counter:`** with the directive is a common practice. This allows us to refer to the memory location by name instead of a hard-coded address, making the code easier to read and maintain.

## Special Assembler Symbols
The Ax51 assembler defines and reserves names of the x51 register set. These predefined names are used in x51 programs to access the processor registers. Following, is a list of each of the 8051, 80C51MX, and 251 registers along with a brief description:
|Register|Description|
|---|---|
|A|Represents the 8051 Accumulator. It is used with many operations including multiplication and division, moving data to and from external memory, Boolean operations, etc.|
|DPTR|The **`DPTR`** register is 1 16-bit data pointer used to address data in **XDATA** or **CODE** memory.|
|PC|The **`PC`** register is the 16-bit program counter. It contains the address of the next instruction to be executed.|
|C|The Carry flag; indicates the status of operations that generate a carry bit. It is used by operations that require a borrow bit.|
|AB|The **`A`** and **`B`** register pair used in **`MUL`** and **`DIV`** instructions.|
|R0-R7|The eight 8-bit general purpose 8051 registers in the currently active register bank. A Maximum of four register banks are available.|
|AR0-AR7|Represent the absolute data addresses of **`R0`** through **`R7`** in the current register bank. The absolute address for these registers changes depending on the register bank that is currently selected. These symbols are only available when **`USING`*** assembler statement is given.|
|PR0, PR1|The Universal Pointer Registers of the 8051MX architecture. Universal Pointer can access the complete **16MB** address space of the 80C51MX. **`PR0`** is composed of registers **`R1`**, **`R2`**, **`R3`**. **`PR1`** is composed of registers **`R5`**, **`R6`**, **`R7`**.|
|EPTR|Additional extended data pointer register of the 80C51MX architecture. **`EPTR`** may be used to access the complete memory space.|

### **`USING`** Assembler Statement
The **`USING`** statement specifies which register bank (0-3) is used to encode the **`AR0-AR7`** registers. The selected register bank is noted in the object file, and the memory area is reserved by the linker.

Some 8051 instruction (like **`PUSH`** and **`POP`**) allow only absolute addresses to be used. The assembler replaces absolute register (**`AR0-AR7`**) with the physical address of the register in the current register bank. While the instruction. While the instruction **`PUSH R0`** is not valid, **`PUSH AR0`** is valid. However, the assembler must know which register bank is used to calculate the correct physical address. This is the purposes for the **`USING`** statement.

The **`USING`** statement does not generate any code to switch the current register bank. The assembler program must select the correct register bank. For example, the following code selects register bank 2:

```asm
PUSH    PSW                 ; save the current register bank
MOV     PSW, #(2 SHL 3)     ; set register bank 2
.
.
.
POP     PSW                 ; restores saved register bank
```
***The physical address is calculated as follows:***
**`(register bank x 8) + register`**

> Note: **Carefully** use the **EQU** statement to define a symbol for an absolute register (**`AR0-AR7`**). The symbol value is calculated at the time it is defined (*not when it is used*). If the register bank is changed subsequently with the **`USING`** statement, then the defined symbol will have the incorrect address and the code generated is like to fail.

 * **Arguments: `USING expression`** where expression is numeric expression. Example: `USING 3` is used to select register bank 3 
 * **Example:**
```asm
USING 3     ; select register bank 3
PUSH AR2    ; push R2 in bank 3 (address 1Ah)

USING 1     ; select register bank 1
PUSH AR7    ; push R7 in bank 1 (address 0Fh)
```

> [User's Guides for Keil C51 Development Tools](https://developer.arm.com/documentation/101655/0961/Ax51-User-s-Guide/Writing-Assembly-Programs/Special-Assembler-Symbols)
