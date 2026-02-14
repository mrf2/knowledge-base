# Structure
Thread Group (500 threads)

Inside:
```bash
CSV Data Set Config
HTTP Header Manager
Once Only Controller
Loop Controller
```

## Step 1 - Login Once

**Once Only Controller:**
Inside it:
```
HTTP Request: Login
    → JSON Extractor:
        ACCESS_TOKEN
        REFRESH_TOKEN
```
Why Once Only?
***Because login must happen once per thread.***

## Step 2 - Header Manager
Add at Thread Group Level:
```
Authorization: Bearer ${ACCESS_TOKEN}
```

**Important:** ***This dynamically updates automatically when variable changes.***
**No need to reconfigure header.**

## Step 3 - Business API Call
Inside Loop Controller:
```bash
HTTP Request: GetProfile
```
Now we detect 401

## Step 4 - Detect 401
Instead of Response Assertion we should add a **JSR223 PostProcessor** under the API request

Groovy code:
```groovy
if (prev.getResponseCode() == "401") {
    vars.put("token_expired", "true")
} else {
    vars.put("token_expired", "false")
}
```

## Step 5 - If Controller
Add:
```bash
If Controller
Condition:
${token_expired} == true
```

### Step 5.1 - Refresh Request
```bash
HTTP Request: Refresh Token
```

Body contains:
```bash
refresh_token=${refresh_token}
```

**Under this refresh request:**
Variable name:
```bash
access_token
```
Is the same name as before. (Initial access token variable name)

It overrides automatically.

We do NOT need a new variable.

## Step 5.2 - Retry Original API
Inside same If Controller:
```bash
HTTP Request: GetProfile (Retry)
```

This request will now use:
```bash
Authorization: Bearer ${access_token}
```

Because header manager references variable dynamically.

No manual update needed


## Execution Flow
For each user:
 1. Login once
 2. Loop business APIs
 3. When API returns 401:
    * Set token_expired = true
    * Enter If Controller
    * Call refresh
    * JSON Extractor updates access_token
    * Retry original request
 4. Continue loop


## Quick QA
> Do I need another JSON extractor?
YES. After refresh.

> Do I need another variable?
NO. Use same variable name: `access_token`

> Are variables global?
NO. Thread-loal only

> Does reassignment override previous value?
YES. Automatically


## Important Edge CASE
Some systems invalidate refresh token after use.

If so:
We must also extract new `refresh_token` from refresh response.

Then override:
```bash
refresh_token
```

Same mechanism.

## Tree Structure
```bash
Thread Group
├── CSV Data Set Config
├── HTTP Header Manager (Authorization: Bearer ${access_token})
├── Once Only Controller
│   └── HTTP Request: Login
│       ├── JSON Extractor (access_token)
│       └── JSON Extractor (refresh_token)
│── Loop Controller
│   ├── HTTP Request: Business API
│   │   └── JSR223 PostProcessor (detect 401)
│   ├── If Controller (${token_expired} == true)
│   │       ├── HTTP Request: Refresh Token
│   │       │       └── JSON Extractor (access_token)
│   │       └── HTTP Request: Business API (Retry)
```
### Why This is Professional
Because:
 * We do NOT refresh blindly
 * We only refresh when server says token expired
 * We simulate real browser behavior
 * We avoid artificial refresh storms
 * We keep token lifecycle realistic

## Important Difference
|Component|Purpose|
|---|---|
|Thread Group|Creates users|
|Ramp-up|Controls how fast users start|
|Once Only Controller|Runs something once per user|
|Loop Controller|Repeats business actions|

