# Memory Layout
 * String literals,like `char *str = "hello world!";` stored in **text/code segment**
 * A `static` local variable in a function (or a global variable) lives in:
   * `.bss` **if uninitialized**
   * `.data` **if initialized**
   * It is **not on the stack**. Its address is determined at **link/load time**, and it stays fixed during the entire.

## Virtual Memory Layout - Full View (Top = High Address)
```bash
0x7fffffffffff (High Address)
+----------------------------------------+
|               Stack                    |  <- grows "down"
|  - Local Variables                     |  e.g., int x;
|  - Function call frames                |
|  - Return addresses, saved regs        |
|  Example: &x = 0x7ffffffff132          |
+----------------------------------------+
|        Guard Page (non-accessible)     |  <- stack overflow protection
+----------------------------------------+
|      mmap() Anonymous Mappings         |
|  - Allocated via mmap() (no file)      |
|  - Used by: malloc, stack expansion    |
|  Example: mmap(NULL, 2048, ...)        |
+----------------------------------------+
|          Shared Libraries (.so)        |  <- loaded with mmap()
|  - Loaded dynamically                  |
|  - Example: libc.so, libm.so           |
|  Example: 0x7ffff2ac0000 (libc)        |
+----------------------------------------+
|               Heap                     |  <- grows "up"
|  - Managed via brk() or sbrk()         |
|  - Used by malloc()                    |
|  Example: int *p = malloc(4);          |
|           p = 0x555555a0aa20           |
+----------------------------------------+
|        .bss (Unitialized globals)      |
|  - Zero-initialized by loader          |
|  - Example: static int x;              |
|  Address: ~0x5555559a8aaa              |
+----------------------------------------+
|        .data (Initalized globals)      |
|  - Example: int y = 32;                |
|  Address: ~0x5555558a8200              |
+----------------------------------------+
|        .rodata (Read-only data)        |
|  - Example: const char *s = "hello";   |
|  Address: ~0x5555557ad900              |
+----------------------------------------+
|        .text (Code segment)            |
|  - Function code, instructions         |
|  - Example: main(), printf()           |
|  Address: ~0x55555550f900              |
+----------------------------------------+
|        NULL Page (0x0)                 |  <- always unmapped
|  - Dereferencing causes segfault       |
+----------------------------------------+
0x000000000000 (Low Address)
```

## Physical Memory Layout (Simplified 32-bit System)
Simplified physical layout of RAM, top-down:
```bash
+------------------------------+  <- Top of RAM (e.g., 0xFFFFFFFF)
|   Reserved for BIOS/ROM      |  <- Legacy BIOS, ACPI, tables, etc.
+------------------------------+
|   Kernel Reserved Memory     |  <- Kernel image, kernel heap/stack
|   Kernel Modules             |
+------------------------------+
|   DMA Buffers                |  <- For peripherals (e.g., network, disk)
+------------------------------+
|   Page Cache / Slab Cache    |  <- OS uses this for caching disk pages
+------------------------------+
|   Free Memory                |  <- Available RAM not yet allocated
+------------------------------+
|   Physical Pages Allocated   |  <- Used for user processes
+------------------------------+
|   Memory-mapped Devices      |  <- e.g., Framebuffer (GPU), UART
+------------------------------+
|   Low Memory (0x00000000)    |
+------------------------------|
```

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
