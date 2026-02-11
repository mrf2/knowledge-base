# JMeter - Thread Group

In JMeter, a **Thread Group ≠ performance level**

A **Thread Group = one user behavior profile**

Each thread group answer this question:
> "What kind of users exist, and how do they behave?"


## How Thread Group constructed
**Example system:**
 * Login
 * Browse
 * Search
 * Place order
 * Logout

## Questions for thread grouping
 * Do *all* users do all of these?
 * Do they do them at the same rate?
 * Do they start at the same time?
 * Do they loop differently?

If **yes →** one thread group is enough
If **no →** separate thread groups are need

## Common Professional Patterns
### 1. Single Thread Group
**Used when:**
 * One main user flow
 * We care about **overall system capacity**
 * We're doing **baseline/load/stress tests**

**Example:**
```bash
Thread Group
├─ Login
├─ Browse
├─ Search
└─ Order
```

### 2. Multiple Thread Group (role-based)
Used when **user behavior differes significantly**

**Example:**
 * 70% Browsers
 * 20% Buyers
 * 10% Admins

```bash
Thread Group: Browsers (700 users)
├─ Browse
└─ Search

Thread Group: Buyers (200 users)
├─ Login
├─ Browse
└─ Order

Thread Group: Admins (100 users)
├─ Dashboard
└─ Reports
```

### 3. System-boundary Thread Groups (advance/pro)
User when testing **limits or isolation**

**Example:**
 * Login service bottleneck
 * Payment gateway saturation
 * Token refresh storms
```bash
Thread Group: Login Storm
Thread Group: Token Refresh
Thread Group: API Read Traffic
Thread Group: API Write Traffic
```

### What Professionals never do
 * ✘ One Thread grop per endpoint
 * ✘ One thread group per API
 * ✘ More thread groups = more realistic
 * ✘ Calculate thread groups from user count

Thread groups are **behavior containers,** not math units

### The real calculation professionals do
Calculate **users, not thread groups:**
 * Concurrent users
 * Arrival rate (users/sec)
 * Think time
 * Ramp-up
 * Test duration

