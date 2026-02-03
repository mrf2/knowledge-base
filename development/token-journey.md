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

### Two fundamental token models

#### A) Opaque token (reference token)

#### B) Self-contained token (JWT)

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

#### Signature
This is **why the server trusts the payload**.
```json
signature = sign(header + payload, private_key)
```

#### Why SAME API behaves differently with different tokens

#### **Token Type**

## Layer 1 - **Access** vs **Refresh** Token

|Token|Purpose|Used where|
|---|---|---|
|Access Token|Call APIs|`Authorization: Bearer ...`|
|Refresh Token|Get new access tokens|`/auth/refresh`|


