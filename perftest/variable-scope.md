# JMeter Variable Scope

JMeter variables:
 * Are thread-local
 * Not global across thread groups
 * Each virtual user has its own copy
 * If we assign same variable name again → it overrides previous value

So:

If we use:
```bash
ACCESS_TOKEN
```

After refresh:
```bash
ACCESS_TOKEN = new_token
```
The old value is replaced automatically

 * We need JSON Extractor again after refresh
 * Same variable name for access token name


