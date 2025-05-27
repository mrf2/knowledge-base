# Sequential Logic
A circut whose **output depends on current inputs *AND* past history** - it has **memory.**

### Core Characteristics:
 - Stateful
 - Uses flip-flops or latches
 - Usaually clocked
 - Used to store, count, delay, or synchronize data

### Examples:
|Circuit Type|Description|
|---|---|
|Flip-Flops (SR, D, JK, T)|1-bit memory cells|
|Registers (PIPO, SISO, etc.)|Store multi-bit values|
|Counters|Count clock pulses (binary, BCD, etc.)|
|Shift Registers|Shift data left/right|
|Memory Cells (RAM, etc.)|Data storage|
|FSMs (Finite State Machinens)|Controlled sequence of operations|
|Latches|Level-sensitive storage|


### Flip-Flop Comparison Table
|Type|Inputs|Characteristic Behavior|Use Cases|
|---|---|---|---|
|SR|Set (S), Reset (R)|Set = 1 $\rightarrow$ Q = 1, Reset = 1 $\rightarrow$ Q = 0; both 1 $\rightarrow$ invalid (in basic form)| Basic memory, control systems|
|D|Data (D)| Q follows D on clock edge| Registers, pipelining|
|JK|J, K|Like SR, but J=K=1 $\rightarrow$ toggles output|Counter, universal FF|
|T|Toggle (T)| T = 1 $\rightarrow$ Q, T = 0 $\rightarrow$ hold| Frequency division, toggling|

We can think JK and T as general-pupose:
 - D is best for storage
 - JK is best for logic control
 - T is best for toggling/counting
