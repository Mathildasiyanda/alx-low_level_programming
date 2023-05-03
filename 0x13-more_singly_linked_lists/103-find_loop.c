#include "lists.h"

/**
 * find_listint_loop - function to identify a loop
 * @head: pointer to the head
 * Return: address of the node where the loop starts, or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *start_point = head;
	listint_t *end_point = head;

	if (!head)
		return (NULL);

	while (start_point && end_point && end_point->next)
	{
		end_point = end_point->next->next;
		start_point = start_point->next;
		if (start_point == end_point)
		{
			start_point = head;
			while (start_point != end_point)
			{
				start_point = start_point->next;
				end_point = end_point->next;
			}
			return (end_point);
		}
	}

	return (NULL);
}
