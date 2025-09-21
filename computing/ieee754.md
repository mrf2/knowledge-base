# IEEE 754 - Floating-Point Standard

**IEEE 754** is the ***standard for representing floating-point numbers in binary***.  It defines how computers store and calucate numbers (like `3.14`, `-0.5`, `1.0e20`, etc.) in a way that balances **range, precision, and efficiency**.

## Number Format
IEEE 754 represents numbers in the form: $value = (-1)^{sign} \times 1.fraction \times 2^{exponent-bias}$, where:
 * **Sign bit (S):** 1 bit
   * `0` $\rightarrow$ positive
   * `1` $\rightarrow$ negative
 * **Exponent (E)**: Stored with a ***bias*** to allow negative exponents
   * ***bias*** = `127` (for single precision, 8-bit exponent)
   * ***bias*** = `1023` (for double precision, 11-bit exponent)
 * **Fraction/Mantissa (M)**: the precision bits (binary digits after the decimal point).
   * IEEE assumes a hidden leading `1.` (except for special cases).

