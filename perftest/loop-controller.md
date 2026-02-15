# Loop Controller

**Definition:**
> It repeats its child elements X times

 * User don't call API once and leave.
 * They perform actions repeatedly.
 * Loop Controller simulates that behavior


## How to Add it in JMeter
Right-Click Thread Group → Add → Logi Controller → Loop Controller

Inside that, put:
```bash
Add business APIs
```

## Example
Assume:
 * User logs in once
 * Then browses 20 pages

Structure:
```bash
Thread Group
 ├── Once Only Controller
 │      └── Login
 ├── Loop Controller (Loop Count = 20)
 │      ├── API Call 1
 │      ├── API Call 2
 │      └── API Call 3
```
**Each user:**
 1. Logs in once
 2. Repeats business APIs 20 times

## Loop Controller vs Loop Count
 * Thread Group also has Loop Count
 * Loop Controller also has Loop Count

**Difference:**
|Name|Purpose|
|---|---|
|Thread Group Loop Count|Repeats entire test plan under it|
|Loop Controller|Repeats only part inside it|


**Example:**
```bash
Thread Group (Loop = 1)
 ├── Once Only Controller (Login)
 ├── Loop Controller (Loop = 10)
 │       ├── API 1
 │       └── API 2
```

