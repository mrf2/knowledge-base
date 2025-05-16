# Transistors

- Lower base resistor $\rightarrow$ **more base current** $\rightarrow$ deeper saturation (***but wasteful***)
- Higher base resistor (>20k) $\rightarrow$ not enough $I_B \rightarrow$ transistor may not fully turn on
- Lower collector resistor $\rightarrow$ **higher collector current** $\rightarrow$ ***can overload transistor on power supply***.

### Rule of thumb:
To **saturate** the transistor (fully turn it ON), we supply enough current into the **base**, which is: 
$I_B \approx \frac {I_C}{10}$

- $V_{BE} = V_{Base} - V_{Emitter} \approx 0.6 \sim 0.7v$
- This must be **maintained,** no matter what absolute voltage the emitter is at.

So:
- If emitter is at **0V,** base needs to be at **~0.6-0.7V**
- If emitter is at **3V,** base bees to be at **~3.6-3.7V**

*This is important in **emitter-followers**, where the emitter isn't tied to ground. If you forget this, your transistor won't turn on as expected.*
