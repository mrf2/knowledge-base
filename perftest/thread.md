# Thread

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


