#include "main.h"
/**
 * reverse_array - reverse contents of an array
 * @a: string 1
 * @n: number of elements of the array
 * Return:0
 */
void reverse_array(int *a, int n)
{
	int x, rev;

	for (x = 0; (x < (n - 1) / 2); x++)
	{
		rev = a[x];
		a[x] = a[n - 1 - x];
		a[n - 1 - x] = rev;
	}
}
