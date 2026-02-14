# Ramp-Up

**Ramp-up controls:**
> **How fast users enter the system**

**If we set:**
 * Threads = 500
 * Ramp-up = 300 seconds

JMeter starts:
```bash
500/300 ≈ 1 users per second
```
**Why professionals avoid ramp-up = 1 seconds:**

Because:
 * We create artificial login storm
 * We spike CPU instantly
 * We test spike, not normal load
 * We hide real bottlenecks

Ramp-up should match real arrival rate.

If production sees 2 users/sec arrival → 300 seconds is reasonable.

If we want spike test → we have to use 5-10 seconds.

Ramp-up is about realism, not math purity.
