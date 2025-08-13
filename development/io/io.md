# io - Input/Output
**Input/Output (I/O)** is the process of copying data between main memory and external devices such as disk drives, terminals, and networks. **Input** operation means copies data from an I/O device to main memory, and an **output** operation copies data from main memory to a device.

## UNIX I/O
A Unix *file* is a sequence of *m* bytes: $B_0, B_1, ..., B_k, ..., B_{m-1}$.

All I/O devices, such as networks, disks, and terminals, are modeled as files, and all input and output is performed by **reading** and **writing** the appropriate files.
 * **Opening files:** An application announces its intention to access an I/O device by asking the kernel to ***open*** the corresponding file. The kernel returns a small nonnegative integer, called a ***descriptor***, that identifies the file in all subsequent operations on the file. The kernel keeps track of all information about the open file. The application only keeps track of the ***descriptor***.

```bash
Each process created by a Unix shell begins life with three open files:
1. standard input (descriptor 0)
2. standard output (descriptor 1), and
3. standard error (descriptor 2)

The header file <unistd.h> defines the following constants:
________________________________________________________</usr/include/unistd.h>
/* Standard file descriptors.  */
#define STDIN_FILENO	0	/* Standard input.  */
#define STDOUT_FILENO	1	/* Standard output.  */
#define STDERR_FILENO	2	/* Standard error output.  */
________________________________________________________</usr/include/unistd.h>

These can be used instead of the explicit descriptor values.
```

 * **Changining the current file position:** The kernel maintains a ***file position k***, initially 0, for each open file. The file position is a byte offset from the beginning of a file. An application can set the current file position ***k*** explicitly by performing a **`seek`** operation.

 * **Reading and writing files:** 
   * A **read** operation copies **n > 0** bytes from a file to memory, starting at the current file position **k**, and then incrementing **k** by **n**. Given a file with a size of **m** bytes, performing a read operation when $ k \geq m $ triggers a condition known as ***end-of-file (EOF)***, which can be detected by the application. There is no explicit **"EOF character"** at the end of a file.
   * A **write** operation cpies **n > 0** bytes from memory to a file, starting at the current file position ***k***, and then updating ***k***.

 * **Closing files:** When an application has ***finished*** accessing a file, it informs the kernel by asking it to ***close*** the file. The kernel responds by freeing the ***data structures*** it created when the file was opened and restoring the descriptor to a pool of available descriptors. When a process terminates for any reasons, the kernel clsess all open files and frees their memory resources.
