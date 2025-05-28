# Session Hijacking
 - Stealing an active session ID (via sniffing, XSS, MitM, etc.)
 - Using it to **take over** the session.
 - Once hijacked, the attacker can act as if they are the original user
 - They don't need to crack passwords - just resue the sessions

### Example:
> An attacker captures a session ID from a user's web session and uses it to impoersonate the user **without their knowledge.**
