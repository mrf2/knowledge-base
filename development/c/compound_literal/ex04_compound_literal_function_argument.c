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


