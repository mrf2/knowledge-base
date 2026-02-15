# Thread


## What JMeter Actually Does (Concpetually)
**Internally it is closer to:**

```c
create_thread(user1);
sleep(1);
create_thread(user2);
sleep(1);
create_thread(user3);
```

**Each thread runs independently:**
```c
thread_function() {
    login();
    loop {
        call_api();
    }
}
```
All threads run at same time

Real OS-level scheduling

 * Each thread is independent
 * Each thread has its own variables
 * They execute concurrently
 * Order is unpredictable
 * JMeter internally does implement Java threads
 * Each virtual user = one Java thread
 * Each thread runs same test plan independently




## User Context
Each thread has:
 * Its own variable map
 * Its own cookies
 * Its own headers
 * Its own token values
 * Its own loop counter
 * Its own execution pointer

They do NOT share variables unless we explicitly use special shared mechanisms.

So:
User A's `access_token` ≠ User B's `access_token`. 

Even if variable name is same.

They are stored in thread-local storage.


