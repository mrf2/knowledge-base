# LEA (Load Effective Address)

**LEA** (Load Effective Address) is often used as a *trick* to do certain computations, but that's not its primary purpose. The **x86 instruction set** was designed to support high-level languages like **Pascal and C**, where **`arrays`** - especially arrays of ints or small structs - are common. Consider, for example, a struct representing **`(x, y)`** coordinates:
```c
struct Point {
    int x;
    int y;
};
```

Now, imagine a statement like:
```c
int y = points[i].y;
```
where `points[i]` is an array of `Point`. Assuming the base of the array is already in `EBX`, and variable `i` is in `EAX`, and `x` and `y` are each 32 bits (so `y` is at ***offset 4 bytes*** in the struct), this statement can be compiled to:

```asm
MOV EDX, [EBX + 8*EAX + 4]      ; right side is "effective address"
```
which will land `y` in `EDX`. The scale factor of **8** is because each `Point` is *8* bytes in size. Now, consider the same expression usedd with the **`address of`** operator **`&`**:
```c
int *ptr = &points[i].y;
```
In this case, we don't want the value of **`y`**, but its ***address***. That's where **LEA** *(Load Effective Address)* comes in. Instead of a **`MOV`**, the compiler can generate:
```asm
LEA ESI, [EBX + 8*EAX + 4]
```
which will load the address in **`ESI`**.
Source: 
 * [Stackoverflow: What's the purpose of the LEA instruction?](https://stackoverflow.com/questions/1658294/whats-the-purpose-of-the-lea-instruction)
