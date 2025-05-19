# Schottky Diode - TTL
A **Schotty** is a type of **diode** - and also a technique used in **faster TTL logic.**

### Schottky Diode
- A **metal-semiconductor junction** (instead of p-n junction)
- **Very low forward voltage drop** (about 0.2-0.3V vs 0.7V for silicon)
- **Switches faster** than normal diodes.

### Schottky in TTL
- Schottky diodes are used **between base and collector** of BJTs. Schottky clamp limits the collector-base voltage to *~0.4V*.
- Prevent the BJT from **going into deep saturation** (which is slow to exit). BJTs, when saturated, take time to *"turn off"* - because stored charge must be removed.
- **Speeds up switching** dramatically
