# JMeter - Thread Group
A **Thread Group is just a container**.
It is NOT:
 * A super-thread
 * A scheduler
 * A memory pool
 * A hidden execution engine
 * A nested loop
 * A stack frame manager

It is simply:
> A configuration block that tells JMeter how many threads to create and how they should behave.

In JMeter, 
 * A **Thread Group ≠ performance level**
 * A **Thread Group ≠ Execution Egine**
 * A **Thread Group = one user behavior profile**
 * A **Thread Group = Thread Factory + Configuration**

Each thread group answer this question:
> "What kind of users exist, and how do they behave?"

## What Happens Internally
When we press **Start**:
 1. JMeter reads Thread Group configuration
 2. It creates N Java threads
 3. Each thread executes the same child test elements independently

So:
```bash
Thread Group
   ├── HTTP Request
   ├── Controller
   ├── Timers
   └── Assertions
```
Each thread runs that tree independently.

The Thread Goup itself does NOT execute anything

It just says:
 * How many threads?
 * Ramp-up time?
 * Loop count?
 * Duration?

## The Hierarchy
```bash
Test Plan
   ├── Thread Group 1
   │       ├── Elements executed by threads
   │
   ├── Thread Group 2
   │       ├── Different behavior
```
 * Thread Groups are parallel containers
 * Each group creates its own threads
 * They do NOT nest
 * They do NOT coordinate
 * They do NOT wait for each other (unless special settins).

## Example
**If we define:**
Thread Group A → 3 Threads
Thread Group B → 2 Threads

**JMeter creates:**
5 total threads
 * All run concurrently
 * Each group manages its own threads only


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


