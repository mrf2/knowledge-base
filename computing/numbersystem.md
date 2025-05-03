# Number Systems
- **Base or Radix**: The *base* or *radix* of a number system equals the number of digits it has. **Decimal** numbers have a base of 10 becasue digits *0* through *9* are used. **Binary** nunmbers have a base of 2 because only the digits *0* and *1* are used. A subscript attached to a number indicates the base of the number. *100<sub>2<sub>* means binary *100*. On the other hand, *100<sub>10</sub>* stands for decimal *100*. Subscript help clarify equations where binary and decimal numbers are mixed. For example, *100001<sub>2</sub>* = *33<sub>10</sub>*.

### Hexadecimal to Binary to Decimal
Step 1. Convert *0x97* to *binary*

$$\begin{array}{cc}
9 & 7 \\
\downarrow & \downarrow \\
1001 & 0111
\end{array}
$$

Step 2. Convert *1001 0111<sub>2<sub>* to *decimal*
 
|1|0|0|1|0|1|1|1|
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|128|~~64~~|~~32~~|16|~~8~~|4|2|1|

**`128`+`16`+`4`+`2`+`1` = `151`**

### Positional-Notation Method
Converting a hexadecimal number to Decimal number. Example $A12E_{16}$ to $41262_{10}$
|A|1|2|E|
|:---:|:---:|:---:|:---:|
|$16^3$|$16^2$|$16^1$|$16^0$|
|4096|256|16|1|
|$10\times4096 = 40960$|$1\times256 = 256$|$2 \times 16 = 32$|$1 \times 14 = 14$|

**`40960`+`256`+`32`+`14` = `41262`**


## BCD Numbers
***Binary Coded Decimal (BCD)*** numbers are express each decimal digits a a *nibble*, which is a string of *4 bits*. BCD numbers are useful when information is transffered into or out of a digital devices (system). Pocket calulators, electronics counters, digital voltemeters etc. uses **BCD** number system.

### Example of BCD number
$973_{10}$ to BCD number
$$\begin{array}{ccc}
9 & 7 & 3 \\
\downarrow & \downarrow & \downarrow \\
1001 & 0111 & 0011
\end{array}
$$

