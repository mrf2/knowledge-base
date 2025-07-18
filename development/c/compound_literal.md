# Compound Literal
A **Compound Literal** allows us to create **unnamed, temporary values** of **any type** - including `struct`, `array`, `union`, or even scalar types - using a literal initializer **in an expression context**. *It's like creating an object on the fly without declaring a named variable*.

 * **Syntax:**
```c
(DataTypeName) {initializer-list}
```

## Basic Example (Primitive types)
```c
#include <stdio.h>

int main()
{
    int x = (int) {42};         // compound literal of type int

    printf("%d\n", x);          // Output: 42

    return 0;
}
```
***It looks like a cast, but it' snot just a cast - it's creating an*** `anonymous temporary object` ***with value*** `42`.

## Compund Literal with Arrays
```c
#include <stdio.h>

int main()
{
	int *arr = (int []){1, 2, 3, 4};	// Compound literal of anonymous int[4]

	for (int i = 0; i < 4; i++)
		printf("%d ", arr[i]);

	return 0;
}
```
***We can pass a temporary array into a function without declaring it seperately.***

## Compound Literals with Structs
```c

/* ex03_literal_with_structs.c */
#include <stdio.h>

struct Point {
	int x;
	int y;
};

int main()
{
	struct Point p = (struct Point) {.x = 5, .y = 7}; // zero-cost temporay struct
	
	printf("x = %d, y=%d\n", p.x, p.y);

	printf("\nInline use:\n");
	printf("Sum: %d\n", ((struct Point){ .x = 3, .y = 5 }).x + 7);

	return 0;
}
```

## Temporary use in Function Arguments
```c

/* ex04_compound_literal_function_argument.c */
#include <stdio.h>

struct Point {
	int x;
	int y;
};

void print_point(struct Point p)
{
	printf("(%d, %d)\n", p.x, p.y);
}

int main()
{
	print_point((struct Point){1, 2});	// direct inline struct
	
	return 0;
}
```
## Zero Initialization with `{}`
We can use `{}` to initialize all members to **zero** *(C99 behavior)*:
```c
struct Point origin = (struct Point){};     // x = 0, y = 0
```
Even:
```c
size_t len = sizeof(((struct Point){}).x);  // safe size access
```
Should avoids:
```c
sizeof(((struct Point *)0)->x);             // older and risky
```
