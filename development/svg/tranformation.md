# `transform`

## Examples
 * `transform="translate(100,50)" 

## Why is this a linear algebra thing?
SVG uses **2D affine transformation matrics**

Tanslation matrix:
```c
| 1 0 tx |
| 0 1 ty |
| 0 0 1  |
```
When we write:
```c
translate(100, 50)
```
This is the matrix:
```c
| 1 0 100|
| 0 1  50|
| 0 0   1|
```

Effect: adds `(100, 50)` to every point

## How `translate()` interacts with x/y

Inside the group:
```php
<g transform="translate(100,50)">
    <rect x="10" y="5">
</g>
```
Effective position is:
```bash
x = 100 + 10 = 110
y = 50 + 5 = 55
```
We can think of it as:
```bash
LOCAL position (10,5)
+
GLOBAL shift (100,50)
=
GLOBAL position (110,55)
```

## Quck ASCII Visualization
Here is a rectanle without translate:
```bash
┌────────────────────┐
│                    │
└────────────────────┘
```
With translate (100, 50):

```bash



                                ┌────────────────────┐
                                │                    │
                                └────────────────────┘
```
