#include "main.h"
#include <stdlib.h>

/**
 * _calloc - assign memory to @nmemb
 * @size: amount bytes allocated to the memory.
 * @nmemb: to be assigned memory
 * Return: pointer to the allocated memory.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *pointer;
	unsigned int length = 0;

	if (nmemb == 0) /* If nmemb or size is 0, then _calloc returns NULL */
		return (NULL);
	if (size == 0)
		return (NULL);
	pointer = malloc(nmemb * size);/* allocate mem*/
	if (pointer == NULL) /* If malloc fails, then _calloc returns NULL*/
		return (NULL);
	for (length = 0; length < (nmemb * size); length++)
		pointer[length] = 0;
	return (pointer);
}
