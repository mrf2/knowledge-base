# Overview of Logic IC Families.
Logic IC families are mostly organized by:
  - **Underlaying technology:** BJT or CMOS
  - **Voltage levels and speed tiers**
  - **Prefix/suffix codes** like 74LS, 74HC, etc.

### TTL Families (BJT-based)
|Family|Stands for|Features|
|---|---|---|
|74|Standard TTL|Original, slow, power-hungry|
|74L|Low power|Power power, slower|
|74H|High Speed|Faster, more power|
|74S|Schottky TTL|Much faster using Schottky clamping|
|74LS|Low-power Schottky|Blanced: lower power, decent speed|
|74AS|Advanced Schottky|Faster than LS, slightly more power|
|74ALS|Advanced Low-power Schottky|Like AS, but lower power|
|74F|Fast TTL|One of the fastest TTL series|

### CMOS Families (MOSFET-based)
|Family|Stands for|Features|
|---|---|---|
|40xx|Original CMOS|Very wide voltage range (3-15V), slow|
|74CXX|CMOS versions of 74xx|Pin-Compatible CMOS drop-in|
|74HCxx|High-Speed CMOS|Much faster than 40xx, TTL voltage levels|
|74HCTxx|High-Speed CMOS, TTL-compatible|Compatible with old TTL input levels|
|74ACxx|Advanced CMOS|Very fast, low delay|
|74ACTxx|Advanced CMOS TTL-compatible|Same speed, compatible with TTL levels|
|CD4000|RCA's CMOS family (same as 40xx)|Includes extras like timers, ADCs|
