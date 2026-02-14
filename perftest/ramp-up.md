# Ramp-Up

## Ramp-up (JMeter Definition)
Ramp-up = 
> How long JMeter takes to start all threads

**Ramp-up controls:**
> **How fast users enter the system**

**If we set:**
 * Threads = 500
 * Ramp-up = 300 seconds

JMeter starts:
```bash
500 users start gradually over 300 seconds
500/300 ≈ 1.67 users per second
```

**If:**
 * Threads = 500
 * Ramp-up = 10 seconds

**Then:**
```bash
500 users start within 10 seconds
=50 users per second
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

## Why 5-10 seconds = Spike Test?
Because it's injecting 500 users almost instantly

That simulates:
 * Traffic surge
 * Marketing blast
 * Serve restart reconnection storm
 * Login storm after outage

It is not normal load

It is sudden pressure

That is why:
> Small ramp-up = spike test
> Large ramp-up = gradual load test

**Ramp-up controls *arrival pattern*, not total users**

