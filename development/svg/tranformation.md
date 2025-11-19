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

