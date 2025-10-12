# `tty` - Teletypewriter

The name `tty` comes from **Teletypewriter**, literally a machine from the 1960s-70s that allowed users to send text commands to a computer and received printed responses.
 * These were **physical devices**: keyboards + printers connected via serial lines.
 * Early Unix systems were designed around **text-based communication**, so the concept of a terminal (a human interface) was central.
 * Unix abstracted these physical devices into **device files**, which is why `tty` is still everywhere in Linux today.

In modern Linux:
 * **`tty` is not a physical teletype anymore**, but the abstraction of a **text input/output interface.**
 * Every terminal session we open (*shell, console, SSH*) has a `tty` associated with it.
 * Conceptually: **a `tty` represents a bidirectional character device for textual I/O.**


## How Linux implements `tty`
Linux has **two main layers** for terminals:
 1. **Physical/virtual consoles (VCs)**
    * `/dev/tty1`, `/dev/tty2`, etc.
    * Represent real or virtual hardware consoles.
    * Example: When we press `Ctrl+Alt+F3` to go to a different virtual console.
 2. **Pseudo-terminals (PTYs)**
    * `/dev/pts/0`, `/dev/pts/1`, etc.
    * Created dynamically for things like terminal emulators (`gnome-terminal, `xterm`) or SSH sessions.
    * PTYs are **virtual serial devices** - they simulate a terminal over software.

## Device Hierarchy
```md
/dev/
├─ tty             -> controlling terminal for the process
├─ tty0            -> current virtual console
├─ tty1...tty63    -> virtual consoles
├─ ttyS0...ttyS31  -> real serial ports
├─ pts/
   ├─ 0
   ├─ 1
   ├─ ...          -> pseudo-terminals
```
 * **`ttyS*`**     -> real hardware serial ports
 * **`pts/*`**     -> pseudo-terminals (emulated serial device for program, Docker, terminal multiplexers, etc.)
 * **`tty`** (no number)  -> shortcut for **the current terminal of the process** (what **`tty`** command prints).
