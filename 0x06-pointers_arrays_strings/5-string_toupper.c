#include "main.h"
/**
 * string_toupper - change small to caps
 * @s: string to work on
 * Return: s
 */
char *string_toupper(char *s)
{
	int x = 0;


	while (*(s + x))

	{
		if (*(s + x) >= 'a' && *(s + x) <= 'z')
		*(s + x) -= 'a' - 'A';
	x++;
}
return (s);
}
