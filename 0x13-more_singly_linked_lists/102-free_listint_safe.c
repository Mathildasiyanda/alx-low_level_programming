#include "lists.h"

/**
 * free_listint_safe - frees a linked list safely to prevent infinite loops
 * @h: pointer to the head pointer
 *
 * Return: number of elements in the freed list
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	int content;
	listint_t *present_node;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		content = *h - (*h)->next;
		if (content > 0)
		{
			present_node = (*h)->next;
			free(*h);
			*h = present_node;
			count++;
		}
		else
		{
			free(*h);
			*h = NULL;
			count++;
			break;
		}
	}

	*h = NULL;

	return (count);
}
