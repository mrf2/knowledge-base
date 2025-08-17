# AT&T vs Intel Assembly Syntax

## Rules of Thumb
 1. **Operands order filps:**
    * Intel: `dest, src`
    * AT&T: `src, dest`
 2. **Pefixes:**
    * Intel: *no prefixes*
    * AT&T: registers `%`, immediates `$`
 3. **Memory addressing: `Displacement + base + index\*scale`**
    * Intel: `[base + index*scale + disp]`
    * AT&T: `dspl(base, index, scale)`
 4. **Sizes:**
    * Intel: implicit (`mov eax, ...`)
    * AT&T: explicit suffix (`movl`)

