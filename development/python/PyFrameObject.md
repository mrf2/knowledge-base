# `PyFrameObject`

## What is a `PyFrameObject`?
A `PyFrameObject` is **CPython's internal C struct** that represents a **stack frame** - i.e. one invocation of Python code.

We can think of it as:
> **The execution record for a running piece of Python code: its local variables, instruction pointer, block stack ,and reference to the code being executed**.

This is CPython's equivalent of:
 * stack frame in C,
 * call stack entries in assembly,
 * activation records in compiler theory.

When a function is called, CPython creates a new `PyFrameObject`.

When the function returns, that frame is destroyed (**garbage-collected or kept for debugging**).


## When does CPython create a `PyFrameObject`?
Whenever Python **calls a function**, the interpreter does:
 1. Create a new `PyFrameObject`
 2. Set:
    * `f_back = previous frame`
    * `f_code = function->code object`
 3. Allocate the value stack
 4. Push the frame onto the *interpreter call stack*.
 5. Begin executing bytecode.

## Where is the frame stored?
Unlike C, Python does **not** use the CPU stack to store local variables.

Python stack:
 * Is on the **heap**
 * Uses reference counting
 * Can be introspected at runtime
 * Is accessible to debuggers, trace functions, exeptions, etc.
