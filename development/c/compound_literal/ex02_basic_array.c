#include <stdio.h>

int main()
{
	int *arr = (int []){1, 2, 3, 4};	// Compound literal of anonymous int[4]

	for (int i = 0; i < 4; i++)
		printf("%d ", arr[i]);

	return 0;
}

