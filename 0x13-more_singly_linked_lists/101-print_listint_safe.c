#include "lists.h"

size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * looped_listint_len - function to check for unique nodes in a list.
 * @head: head pointer to the list
 * Return: 0 if != looped, else, No. unique nodes in the list.
 */
size_t looped_listint_len(const listint_t *head)
{
	const listint_t *start_point, *end_point;
	size_t node_check = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	start_point = head->next;
	end_point = (head->next)->next;

	while (end_point)
	{
		if (start_point == end_point)
		{
			start_point = head;
			while (start_point != end_point)
			{
				node_check++;
			start_point = start_point->next;
				end_point = end_point->next;
			}

			start_point = start_point->next;
			while (start_point != end_point)
			{
				node_check++;
				start_point = start_point->next;
			}

			return (node_check);
		}

		start_point = start_point->next;
		end_point = (end_point->next)->next;
	}

	return (0);
}

/**
 * print_listint_safe - function to output num of a list's nodes.
 * @head:  pointer to  head of the list
 * Return: The number of nodes in  list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t node, index = 0;

	node = looped_listint_len(head);

	if (node == 0)
	{
		for (; head != NULL; node++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}

	else
	{
		for (index = 0; index < node; index++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
	}

	return (node);
}
