# Once Only Controller

**Definition:**
> It ensures its children execute only once per thread

Even if loop runs 100 times

## Why need it
**Without it:**
If we put Login inside Loop Controller:

Every iteration will login again.

That is wrong

Users do not login before every API call

## How to Add it in JMeter
Right-Click Thread Group → Add → Login Controller → Once Only Controller

Inside that, put:
```bash
HTTP Request: Login
JSON Extractors
```
**Each virtual user:**
 * Logs in once
 * Gets tokens
 * Never logs in again

