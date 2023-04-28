#include "lists.h"

/**
 * free_list - frees a linked list
 *
 * @head: pointer to the first node of the list
 *
 * Return: void
 */

void free_list(list_t *head)
{
	list_t *current, *next;

	if (head == NULL)
		return;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current->str);
		free(current);
		current = next;
	}
}
