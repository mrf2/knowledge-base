# Watchdog Timer (WDT)

A **watchdog timer (WDT)** is a hardware timer, designed as a **safety mechanism**. Its purpose is to detect and recover from software malfunctions, deadlocks, or hardware faults.

## Core Concept
 * A watchdog timer is essentially a **countdown timer**.
 * The system must **periodically reset** the watchdog before the timer expires.
 * If the watchdog **times out** (*not reset in time*), it assumes the system is stuck $\rightarrow$ it triggers a **reset** or other corrective action.

## Why Use
 1. **Fault Recovery** - If the firware hangs due to:
    * Infinite loop
    * Stack overflow
    * Deadlock (*e.g., waiting for a peripheral that never responds*)
      * $\rightarrow$ The WDT will reset the MCU.
 2. **Reliability** - Ensures unattended systems (routers, cars, medical devices, satellites, etc.) self-recover.
 3. **Safety-critical systems** - Often mandated by standards (e.g. automotive ISO 26262, avionics DO-173C).

## Typical Operation
 1. Configure the watchdog with a time (*e.g., 1 second*).
 2. In main program loop (or timer ISR), **refresh/reset** the watchdog periodically.
 3. If code execution halts, the refresh won't happen $\rightarrow$ WDT expires $\rightarrow$ system reset.

