# UUID - Universally Unique Identifier

 A Universally Unique Identifier (UUID) is a 128-bit label used to uniquely identify resources in computer systems without requireing to central registration authority.

## UUID quick anatomy
Example:
```bash
550e8400-e29b-41d4-a716-446655440000
```

Fields:
```
time_low - time_mid - time_hi_and_version - clock_seq - node
```
The **version** is the key:
 * 1 → time based (timestamp + MAC)
 * 3 → name-based (MD5)
 * 4 → random
 * 5 → name-based (SHA-1)

In the example:
```
41d4 → version 4 (random)
```
→ Version 4 UUIDs contain nothing to decode

### In linux inspect UUID
```
echo 550e8400-e29b-41d4-a716-446655440000 | cut -d - -f3
```
First hex digit:
 * 1 → v1
 * 4 → v4
 * etc.

