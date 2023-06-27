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
	listint_t *ptr, *ptr2;
	int swapped;

	if (!(*list) || !(*list)->next)
		return;

	ptr = *list;
	do {
		swapped = 0;
		while (ptr->next != NULL)
		{
			ptr2 = ptr->next;
			printf("ptr2 dey\n");
			if (ptr2->n < ptr->n)
			{
				printf("will be swapped\n");
				swap_nodes(list, ptr, ptr2);
				print_list(*list);
				swapped = 1;
			}
			else
				ptr = ptr2;
		}

		if (swapped)
		{
			printf("swapped\n");
			ptr = ptr->prev;

			swapped = 0;
			while (ptr->prev)
			{
				ptr2 = ptr;
				if (ptr2->n < ptr->n)
				{
					printf("will be swapped\n");
					swap_nodes(list, ptr, ptr2);
					swapped = 1;
					ptr = ptr2;
				}
				else
					ptr = ptr2;
			}
		}

		printf("end first while\n");
	} while (swapped);
}
