#include "sort.h"

/**
 * partition - partitions array using the Lomuto partition scheme
 *
 * @array: array to sort
 * @low: lowest index to iterate to
 * @high: highest index to iterate to
 * @size: size of original array
 *
 * Return: sorted index
 */

size_t partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high], tmp;
	size_t i = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
			i++;
		}
	}

	if (array[i] != array[high])
	{
		tmp = array[i];
		array[i] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}

	return i;
}

/**
 * main_sort - sorts using the quick sort algorithm
 *
 * @array: array to sort
 * @low: lowest index to iterate to
 * @high: highest index to iterate to
 * @size: size of original array
 *
 * Return: void
 */

void main_sort(int *array, size_t low, size_t high, size_t size)
{
	size_t j;

	if (low < high)
	{
		j = partition(array, low, high, size);
		main_sort(array, low, j - 1, size);
		main_sort(array, j + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers using the quick sort algorithm
 *
 * @array: array to be sorted
 * @size: size of array
 */

void quick_sort(int *array, size_t size)
{
	size_t low = 0, high = size - 1;

	if (!array || size < 2)
		return;

	main_sort(array, low, high, size);
}
