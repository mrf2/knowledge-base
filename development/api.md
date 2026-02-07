# API - Application Programming Interface

## There are Two kinds of endpoints
### A) Resource APIs (business APIs)
There are things like:
```bash
GET /get-user-permission
GET /users
POST /orders
```
They:
 * return data
 * change data
 * enforce roles/permissions

**→ These APIs accept ONLY access tokens**

### B) Auth APIs (token machinery)
These are things like:
```bash
POST /login
POST /refresh-token
POST /logout
```
They:
 * issue tokens
 * rotate tokens
 * invalidate tokens
**→ These APIs accept refresh tokens (and sometimes credentials)

