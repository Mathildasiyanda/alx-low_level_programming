#include "main.h"
#include <stdlib.h>

/**
* string_nconcat - joins two strings
* @s1: main string to receive s2
* @s2: string to be joined to s1
* @n: amount of bytes for s2 to be joined to s1
* Return: pointer to concatenated string in memory
*/

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int content1;
	unsigned int content2;
	unsigned int length_s1 = 0;
	unsigned int new_length;
	char *pointer;

	if (s1 == NULL)
		s1 = "";/*if NULL is passed, treat it as an empty string*/

	if (s2 == NULL)
		s2 = "";/*if NULL is passed, treat it as an empty     string*/

	for (content1 = 0; s1[content1]; content1++)
		length_s1++;

	new_length = length_s1 + n;/* new space in memory */

	pointer = malloc(sizeof(char) * (new_length + 1));/* +1 for null terminator */
	if (pointer == NULL) /*If the function fails, it should return NULL */
		return (NULL);

	for (content1 = 0; content1 < length_s1; content1++)
/* check for every value of s1 and increament it from 0 */
	{
		pointer[content1] = s1[content1];
	}

	for (content2 = 0; content2 < n; content2++, content1++)
/* If n >= to the length of s2 then use the entire string s2 */
	{
		pointer[content1] = s2[content2];
	}

	pointer[content1] = '\0';
/* End the process when we get to the null terminator */

	return (pointer);
}
