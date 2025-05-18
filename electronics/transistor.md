# Transistors
|||
|---|---|
|$I_B$|Base Current|
|$I_C$|Collector Current|
|$I_E$|Emitter Current|
|$\beta$|Current gain also written as $h_{FE}$|
|$\beta_{dc}$, ***tells us how much collector current we get for a given base current***|$\beta_{dc} = \frac {I_C}{I_B}$|
|$h_{FE}$, ***tells us how much collector current we get for a given base current***|$h_{FE} = \frac {I_C}{I_B}$|
|Saturation region|*Saturation region* refersw to a region of operation where maximum collector current flows and the transistor acts much like a closed switch from collector to emitter.|
|Cutoff region|*Cutoff region* referes to the region of operation near the voltage axis of the collector characteristics graph, where the transistors acts like an open switch - only a very samll (typically 10nA to a few $\mu A$) leakage current flows in this mode of operation.|
|Active mode/region|*Active mode/region* describes transistor operation in the region the the right of saturation and above cutoff, where a near-linear relationship exists between terminal currents ($I_B, I_C, I_E$).|
|Bias|Bias referes to the specific dc terminal voltages and current of the transistor to set a desired point of active mode operation, called the *quiescent point* or *Q-Point*.|
|Quiescent point (Q-Point)|Transistor's a desired point of active mode operation|


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

|Situation|Base Current Rule|Why|
|---|---|---|
|Switching (saturation)|$I_B \approx \frac {I_C}{10}$| Conservative overdrive to gurantee saturation|
|Amplification (active)|$I_B = \frac {I_C}{\beta}$| Use dataseet $\beta$ for efficiency|

*This is important in **emitter-followers**, where the emitter isn't tied to ground. If you forget this, your transistor won't turn on as expected.*
