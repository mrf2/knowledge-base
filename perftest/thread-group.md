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
### Single Thread Group
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

