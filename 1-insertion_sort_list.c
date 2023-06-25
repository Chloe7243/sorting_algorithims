#include "sort.h"

/**
 * insertion_sort_list - sorts a list  using the insertion sort algorithm
 *
 * @list: list to sort
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *ptr = *list, *ptr2;

	if (!list || !*list || !(*list)->next)
		return;

	do {
		ptr2 = ptr->next;
		while (ptr2->prev)
		{
			if (ptr2->n < ptr->n)
			{
				if (ptr2->next)
					ptr2->next->prev = ptr;
				ptr->next = ptr2->next;
				ptr2->next = ptr;
				ptr2->prev = ptr->prev;
				if (ptr->prev)
					ptr->prev->next = ptr2;
				ptr->prev = ptr2;
				if (!ptr2->prev)
					*list = ptr2;
				print_list(*list);
			}
			else
				break;
			if (ptr2->prev)
				ptr = ptr2->prev;
			else if (!ptr2->prev && ptr->next)
				ptr = ptr2;
		}
		if (ptr->next)
			ptr = ptr->next;
	} while (ptr->next);
}
