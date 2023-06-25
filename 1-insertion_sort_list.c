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

	do {
		ptr2 = ptr->next;
		while (ptr2->prev)
		{
			if (ptr2->n < ptr->n)
			{
				if (ptr2->next != NULL)
					ptr2->next->prev = ptr;
				ptr->next = ptr2->next;
				ptr2->next = ptr;
				ptr2->prev = ptr->prev;
				if (ptr->prev != NULL)
					ptr->prev->next = ptr2;
				ptr->prev = ptr2;
				if (ptr2->prev == NULL)
					*list = ptr2;
				print_list(*list);
			}
			else
				break;
			if (ptr2->prev != NULL)
				ptr = ptr2->prev;
			else if (ptr2->prev == NULL && ptr->next != NULL)
				ptr = ptr2;
		}
		if (ptr->next != NULL)
			ptr = ptr->next;
	} while (ptr->next);
}
