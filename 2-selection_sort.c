#include "sort.h"

/**
 * selection_sort - sorts an array of integers using selection sort algorithm
 *
 * @array: arrray to sort
 * @size: size of array
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, idx;
	int smallest;

	if (!array)
		return;
	for (i = 0; i < size; i++)
	{
		smallest = array[i];
		idx = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < smallest)
			{
				smallest = array[j];
				idx = j;
			}
		}
		array[idx] = array[i];
		array[i] = smallest;
		print_array(array, size);
	}
}
