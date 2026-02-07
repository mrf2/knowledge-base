# The Token Journey

 * Layer 0 → Why **tokens** exist
 * Layer 1 → **Access** vs **Refesh**
 * Layer 2 → What an **access** token containis
 * Layer 3 → How APIs actually use tokens
 * Layer 4 → Scope, role, permissions (differences)
 * Layer 5 → Token **lifecycle** & **revocation**
 * Layer 6 → Multi-tenant & admin tokens

## Layer 0
### What a **token** really is?
A token is **proof of authorization**, not identity by itself.

A **token** is a **server-issued artifact** that says, *If you trust me, you may threat this request as having these properties*.

Those properties are waht control **API behavior**.

### What problems tokens solve
Before tokens:
```bash
username + password → every request
```
Problems:
 * Password exposure
 * No fine-grained control
 * No expiry
 * No delegation

Token solve this by sperating:
```bash
Authentication → Authorization
(login)          (API access) 
```

### Two fundamental token models

#### A) Opaque token (reference token)
```bash
Authorization: Bearer a83jfhbGciOiJIUz...
```

Characteristics:
 * Meaningless string to the client
 * Server looks it up in DB/cache
 * All logic is server-side

Server flow:
```bash
token → lookup → user → roles → permissions
```
Used by:
 * Old OAuth servers
 * Some enterprise systems

#### B) Self-contained token (JWT)
```bash
xxxxx.yyyyy.zzzzz
```
Everything needed is **inside the token**

**Server flow:***
```bash
verify signature → read claims → decide
```

No DB hit required (unless revoked)

### JWT anatomy
A JWT has **three base64 parts**:
```bash
HEADER.PAYLOAD.SIGNATURE
```

#### Header
```json
{
    "alg": "RS256",
    "typ": "JWT"
}
```
Tells server:
 * How it was signed
 * What kind of object it is

#### Payload
This is where our API behavior comes from

Example:
```json
{
    "sub": "user-123",
    "role": "ORG_USER",
    "permissions": [
        "user.read",
        "user.permission.read"
    ],
    "org_id": "org-456",
    "scope": "api",
    "iss": "auth.example.com"
    "aud": "backend-api",
    "exp": 1735689600
}

#### Signature
This is **why the server trusts the payload**.
```json
signature = sign(header + payload, private_key)
```
Without the private key:
 * Payload can be forged
 * Roles can be escalated

#### Why SAME API behaves differently with different tokens
Because the API does **not see "user".**

It seems **claims**.

Example internal logic:
```python
if token.role == SUPER_ADMIN:
    allow
elif token.role == ORG_USER and token.org_id != null:
    allow
else:
    deny
```
Same endpoint
Same HTTP method
Same Bearer header

**→ Different execution path**

#### **Token Type**

## Layer 1 - **Access** vs **Refresh** Token

|Token|Purpose|Used where|
|---|---|---|
|Access Token|Call APIs|`Authorization: Bearer ...`|
|Refresh Token|Get new access tokens|`/auth/refresh`|

### Why two token exist (non-geotiable reason)
**Access tokens:**
 * Short-lived (minutes)
 * Frequently exposed (sent on every request)
 * Can safely expire

**Refresh tokens:**
 * Long-lived (days/months)
 * Rarely sent
 * High risk if stolen

So the system **limits blast radious**

### Strict Rule
> **APIs must NEVER accept refresh tokens**

**If an API accepts a refresh token → security bug**

So if our API:
 * Works with Super Admin token
 * Fails with another user token

This already tells us:
 ✔ both are **access tokens**
 ✘ not refresh vs access issue

### How systems enforce this
Access token payload usually has
```json
"typ": "access"
```
or
```json
"scope": "api"
```
Refresh token might have:
```json
"type": "refresh"
```
or be opaque (no JWT at all)

Backend logic:
```python
if token.type != ACCCESS:
    reject
 

###token
