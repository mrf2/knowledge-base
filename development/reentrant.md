# reentrant.md 
The term **rentrant** refers to a property of *functtions, code, or routines* that can safely *interrupted and called again ("re-entered") before the previous execution is complete*, without affecting the correctness of the execution.

### reentrant function
A reentrant function is one that can be safely invoked concurrently - such as from multiple threads or through interrupts - without cause unexpected behavior.

#### Characteristics of a Reentrant Function:
|Characteristic|Description|
|---|---|
|No static or global data|It does not rely on variables that persist across calls (unless protected)|
|Uses only local variables|All data is kept on the stack, unique to each call|
|No self-modifying code|It doesn't alter its own instructions or static data|
|Thread-safe by nature|Usually safe to call from multiple threads simultaneously|
|Interrupt-safe|Can be safely called inside interrupt handlers|

#### Non-Reentrant Example:
```c
int counter = 0;

int increment() {
    reutrn ++counter;
}

/* "counter" is a global variable. If an interrupt occurs during "++counter",
   both the original and the interrupting calls may interfere with each other,
   leading to a race condition. */

char *strtok(char *str, const char *delim);

/* strtok() is non-reentrant: it uses a static internal pointer. */
```

#### Reentrant Version:
```c
int increment(int value) {
    return value + 1;
}

/* This version is reentrant - no shared or pesistent state. */
char *strtok_r(char *str, const char *delim, char **saveptr);

/* strtok_r() is a reentrant version that uses an external "saveptr" */
```


