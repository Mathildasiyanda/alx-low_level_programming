#include <stdlib.h>
#include "main.h"

/**
 *array_range - newarray of integers
 * @min: least amt of values to be stored
 * @max: highest amt of values to be stored
 * Return: pointer to the new array
 */
int *array_range(int min, int max)
{
	int *pointer_new_array;
	int content, length;

	if (min > max)
		return (NULL);

	length = max - min + 1;

	pointer_new_array = malloc(sizeof(int) * length);

	if (pointer_new_array == NULL)
		return (NULL);

	for (content = 0; min <= max; content++)
		pointer_new_array[content] = min++;

	return (pointer_new_array);
}
