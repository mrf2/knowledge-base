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

