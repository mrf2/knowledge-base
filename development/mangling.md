# mangling

**Name mangling**: making variable/function names unique and machine-safe.

**Packet mangling** *(iptables, routers)*: modifying network packets - `header`, `flags`, `routng marks` - for control, shaping, or security.

## Name Mangling
**Mangling** means *changing a name* (or something similar) into a different, usually weired-looking format - **not for humans**, but to satisfy some technical need like compatibility, uniqueness, or safety.

### 1. Name Mangling in C++
This is the **most common** place where "mangling" is mentioned.

#### Problem: C++ supports **function overloading:**
```cpp
int sum(int a, int b);
float sum(float a, floab b);
```
But the underlying **linker** works with ***unique names***.
#### Solution: C++ compilers use **name mangling** to turn the functions into unique name like:
```cpp
_Z3sumii        // sum (int, int)
_Z3sumff        // sum (float, float)
```
These wired names are **mangled names**. They encode function name+parameter types+namespaces.

We can see them using:
```bash
nm file.o
```
Or demangle with:
```bash
c++filt _Z3sumii
```
will output: `sum(int, int)`

### 2. Name Mangling in Python (Internal)
Python also does **mangling**, but it is simpler and used for **privat variables** in classes.

#### Example:
```python
class MyClass:
    def __init__(self):
        self.__secret = 42
```
Python mangles `__secret` into: 
```python
_MyClass__secret
```
This will **prevent accidental access** or **name collision** when subclassing.

### 3. Mangling in File Names, URLs, etc.
When systems don't support certain characters (like spaces, slashes, Unicode), they get **mangled** to safe versions.

#### Examples:
 * `My Document.txt` $\rightarrow$ `My%20Document.txt` (URL mangling/encoding)
 * In Dindows: `longfilename.txt` might become `LONGFI~.TXT` (old DOS mangling)

### 4. Mangling in Binary Formats/Low-Level Code
When things like **symbol names, variable names**, or **identifiers** need to be:
 * unique
 * compact
 * distinguishable
 * or safely stored in formats that don't support spaces or special chars
They are **mangled** by encoding them in some deterministic, machine-friendly way.


## Packet Mangling
In the context of **Linux firewalls**, *mangling* means **modifying packets** as they pass through the system - *not variable names*.


### What can be mangled
 * IP headers
 * TCP flags
 * Differentiated Services Code Point (DSCP)/Type of Service (TOS) fields
 * TTL values
 * Marks *(used for advanced routing)*
 * Etc.

### Use Cases
|Use Case|Example|
|---|---|
|Force TTL|Reduce TTL to prevent routing beyond X hops|
|QoS tuning|Change TOS/DSCP for traffic shaping|
|Mark packets|Tag for special routing or filtering rules|
|Drop flags|Strip TCP options like ECN, SACK|

### Example Rule:
```bash
iptables -t mangle -A PREROUTING -p tcp --dport 80 -j TTL --ttl-set 50
```
This sets TTL=50 for all incoming TCP packets on port 80 (HTTP) **before routing**.
Another:
```
iptables -t mangle -A OUTPUT -p tcp --dport 22 -j MARK --set-mark 1
```
Tags outgoing SSH traffic with a mark for routing decisions.

### Mangle Table Chain Overview:
+---------------+----------+----------+----------+---------------+<br>
|  PREROUTING   |  INPUT   |  FORWARD |  OUTPUT  |  POSTROUTING  |<br>
+---------------+----------+----------+----------+---------------+<br>

Used in `iptables -t mangle`.

### Why is **Packet Mangling** is important in Protocol Security?
Because:
 * Attackers often **exploit packet manipulation**
 * We will need to **enforce or harden protocols** by altering or blocking malicious behaviours
 * **Routing+mangling+NAT** can change what a packet looks like: ***breaking or bypassing protocols***

### Real Example in Protocol Hardening:
 * DNS Security: Strip or rewrite `EDNS0` options in DNS packets using `tiptables mangle`.
 * Drop fragmented TCP packets with suspicious flags
 * Use mangle marks to route suspicious traffic to **sandbox** or **IDS**

