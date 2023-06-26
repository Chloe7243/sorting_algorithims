#include "sort.h"

/**
 * insertion_sort_list - sorts a list  using the insertion sort algorithm
 *
 * @list: list to sort
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
    if (!list || !(*list) || !(*list)->next)
        return;

    listint_t *ptr, *ptr2, *current;

    current = (*list)->next;
    while (current) {
        ptr = current;
        ptr2 = ptr->prev;

        while (ptr2 && ptr->n < ptr2->n) {
            if (ptr->next)
                ptr->next->prev = ptr2;

            if (ptr2->prev)
                ptr2->prev->next = ptr;
            else
                *list = ptr;

            ptr->prev = ptr2->prev;
            ptr2->next = ptr->next;
            ptr->next = ptr2;
            ptr2->prev = ptr;

            ptr = ptr2->prev;
            ptr2 = ptr ? ptr->prev : NULL;
        }

        current = current->next;
    }
}

