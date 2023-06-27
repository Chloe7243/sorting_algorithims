#include "sort.h"

/**
 * swap_nodes - swaps nodes
 *
 * @ptr: node to be swapped
 * @ptr2: second node to be swapped
 * Return: void
 */

void swap_nodes(listint_t **list, listint_t *ptr, listint_t *ptr2)
{
	if (ptr2->next)
		ptr2->next->prev = ptr;

	if (ptr->prev)
		ptr->prev->next = ptr2;
	else
		*list = ptr;

	ptr2->prev = ptr->prev;
	ptr->next = ptr2->next;
	ptr2->next = ptr;
	ptr->prev = ptr2;
}

/**
 * cocktail_sort_list - sorts an array using the cocktail shaker sort algorithm
 *
 * @list: list to sort
 * Return: void
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *ptr, *ptr2, *current;
	int swapped = 0;

	if (!(*list) || !(*list)->next)
		return;

	current = (*list)->next;
	do {
		swapped = 0;
		ptr = current->prev;
		ptr2 = current;

		while (ptr2)
		{
			if (ptr2->n < ptr->n)
			{
				swap_nodes(list, ptr, ptr);
				print_list(*list);
				swapped = 1;
				ptr = ptr->next;
				ptr2 = ptr2->next;
			}
			else
			{
				ptr = ptr->next;
				ptr2 = ptr2->next;
			}
		}

		if (swapped)
		{
			ptr2 = ptr;
			ptr = ptr->prev;

			swapped = 0;
			while (ptr2 != current)
			{
				if (ptr2->n < ptr->n)
				{
					swap_nodes(list, ptr, ptr2);
					print_list(*list);
					swapped = 1;
				}
				ptr = ptr->prev;
				ptr2 = ptr2->prev;
			}
		}
		current = current->next;
	} while (current && swapped);
}
