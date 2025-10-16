# JWT - JSON Web Token
A **JWT (JSON Web Token)** has ***three parts***, each **Base64URL-encoded:** `<HEADER>.<PAYLOAD>.<SIGNATURE>`

**Example:** `eyJhbGciOiJSUzI1NiIsInR5cCI6IkpXVCJ9.eyJ1c2VyIjoiYWxtYXJ1ZiJ9.<signature>`

## JWT Header Example (JSON)
Here's how different algorithms are declared in the JWT header:
```json
{
  "alg": "HS256",
  "typ": "JWT"
}

```
Other Examples:

```json
{"alg": "RSA256", "typ": "JWT"}
{"alg": "ES384", "typ": "JWT"}
{"alg": "EdDSA", "typ": "JWT"}
```
 * "alg" $\rightarrow$ which signing algorithm is used
 * "typ": "JWT" $\rightarrow$ optional, identifies it as a JWT token

## Signing Concept
The signature is calculated as:
```python
signature = SIGN(algorithm, key, base64url(header) + "." + base64url(payload))
```
Then Base64URL-encoded and concatenated to form the final token.

## Example Implementations (in Python)
Let's use the `jwt` library (PyJWT):
### HS256 (HMAC + SHA-256)
```python
import jwt

secret = "secret key"
payload = {"user": "Tom"}

token = jwt.encode(payload, secret, algorithm="HS256")
print(token)

decoded = jwt.decode(token, secret, algorithms=["HS256"])
print(decoded)
```
***Uses same `secret` key for signing and verification***.

## In Raw/Manual Terms
If we ever want to **replicate this manually (in C or low-level):**
 1. JSON $\rightarrow$ serialize header & payload.
 2. Base64URL encode both.
 3. Concatenate with **.**.
 4. Apply the signing algorithm (e.g. `HMAC_SHA256` or `RSA_sign`).
 5. Base64URL encode the signature.
 6. Combine all three sections.
