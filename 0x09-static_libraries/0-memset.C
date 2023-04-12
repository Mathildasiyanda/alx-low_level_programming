#include "main.h"

/**
 * _memset - function that fill memory
 * @s: character
 * @b: replace
 * @n: number
 * Return: return a pointer to a memory
*/

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
	s[i] = b;
	}

	return (s);
}
