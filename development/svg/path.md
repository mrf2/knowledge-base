# `path`

## 1. What `path` really is (core idea)
A `path` is **one pen** that moves on a 2D plane.

It can:
 * move without drawing
 * draw straight lines
 * draw curves
 * close shapes

All controlled by **commands + numbers** in the `d` attribute.

```xml
<path d="COMMAND numbers COMMAND numbers ..."   
```

## 2. Coordinate system (critical)
SVG uses **screen coordinates:**
```bash
(0, 0)  ─────────► X

  │
  │
  ▼
  Y
```
 * Origin `(0, 0)` is **top-left**
 * X increases $\rightarrow$ right
 * Y increases $\rightarrow$ down

## 3. The absolute minimum: `M` and `L`

### Example 1: Draw one straight line
```xml
<path d="M 50 50 L 200 50"
    stroke="black"
    stroke-width="2"
    fill="none" />
```
**Meaning:**
 * `M 50 50` $\rightarrow$ Move pen to (50, 50) **without drawing**
 * `L 200 50` $\rightarrow$ Draw line to (200, 50)

ASCII idea:
```bash
(50, 50) -------------------- (200, 50)
```
