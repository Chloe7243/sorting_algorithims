#include "sort.h"

/**
 * bubble_sort - sorts an array using the Bubble sort algorithm
 *
 * @array: array to sort
 * @size: size of array
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j, swapped = 0, smaller;

	if (!array)
		exit(0);;
	do {
		for (j = 0; j < (size - 1); j++)
		{
			if (array[j + 1] < array[j])
			{
				smaller = array[j + 1];
				array[j + 1] = array[j];
				array[j] = smaller;
				print_array(array, size);
				swapped = 1;
			}
			else if (swapped == 0)
				swapped = 0;
		}
		i++;

	} while (i < size && swapped);
}
