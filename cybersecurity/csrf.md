# Cross-Site Request Forgery (CSRF)
 - **CSRF** tricks a **logged-in user's browser** into sending **unauthorized requests** to a trusted website.
 - The attack **exploits the trust a website has in the user's browser session** (e.g., cookies or session tokens)

Example: A user logged into a banking site in one tab, and an attacker sends a hidden request from another site to transfer funds - and the bank trusts the browser because the user is authenticated.
