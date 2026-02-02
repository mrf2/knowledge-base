# `Content-Type` Header element

## Content-Type and Expected values
|Content-Type|Expected value|
|---|---|
|`Content-Type: application/json`| Contents **must be valid JSON**|
|`Content-Type: application/x-www-form-urlencoded`|Contents should be **key value pair**, `key=value&key2=value2`|
|`Content-Type: text/plain`| Contents **literally any text**|

### Example
JSON file contents:
```json
{
    "username": "admin",
    "password": "password123"
}

Command:
```bash
curl -v -X POST https://restful-booker.herokuapp.com/auth \
  -H "Content-Type: application/json" \
  -d @restfulbooker.json
```

## Special consideration
When we use `-d`:

 * `curl` automatically sets:
   ```bash
   Content-Type: application/x-www-form-urlencoded
   ```
   **unless we override it**
 * `curl` also switches the method to **POST automatically**
   So, `-X POST` is optional for a POST request

So, correct use of `-d` for JSON content type will be like below:
```bash
curl -v https://restful-booker.herokuapp.com/auth \
  -H "Content-Type: application/json" \
  -d @restfulbooker.json
```

