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

## What doe4s the **`tty`** command do?
If we type:
```bash
$ tty
/dev/pts/0
```
It tells us:
> "This process is connected to `/dev/pts/0`
 * If we run multiple **`terminal`** then **`tty`**'s **`pts`** number will increase incrementally
 * Key Idea: **Every process can have a controlling terminal**, and **`tty`** shows it.

## Why **`tty`** is ubiquitous
 1. **Terminal awareness:** Many commands behave differently if they detect they are attached to a terminal.
    * Example: `ls --color=auto` only prints colors if output is a terminal.
    * Docker uses `-t`/`--tty` to allocate a pseudo-terminal inside a container so commands think they are in a real terminal.
 2. **Redirection & scripting:**
    * `/dev/tty` can be used to **read/write directly from the terminal**, even if stdin/stdout is redirected:
```bash
echo "Enter password: " > /dev/tty
read password < /dev/tty
```
 3. **Legacy & compatibility:** Many low-level Linux programs still assume **everything is text-based I/O over a `tty`**, even modern GUIs emulate this internally for terminals.

## Is `tty` a simulator/emulator/technology?
 * It is not exactly a **technology** in itself, but more of a **kernel abstraction/API:**
   * **Pseudo-terminal (pty)** is the "emulator" part.
   * **`tty` device files** expose them to user-space.
 * We can think of **PTYs as software serial ports:** they behave like a serial terminal, but in software.
```
  User process
        |
+--------------------+
|    /dev/pts/0      | <- PTY (pseudo-tty)
+--------------------+
        |
Terminal emulator (xterm, sshd, Docker -t)
        |
User keyboard & screen
```
 * PTY makes programs **think they are talking to a real terminal**.

## `tty` in Docker
 * Docker's `-t`/`--tty` flag allocates a **pseudo-terminal** inside the container
 * Why? So that interactive programs like `bash`, `top`, or `vim` behave correctly:
```
docker run -it ubuntu bash
```
 * `-i` $\rightarrow$ interactive
 * `-t` $\rightarrow$ allocates a pseudo-tty

Without `-t`, programs might think they're running in a script instead of a terminal $\rightarrow$ colors disappear, no input echo, etc.
