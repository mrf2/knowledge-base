# Test Duration
Example, Token expiry = **5 minutes** for example

If test duration is **10 minutes**:
 * Each user refreshes once
 * Not enough cycles

If duration is 30 minutes:
 * Each user refreshes ~5 times
 * System stabilizes
 * Garbage Collection (GC) stablizes
 * Connection pools stabilize
 * Caches warm

**Professional rule:**
> Run at least 4-6 token expiry cycles

That's why 30-60 minutes is common

