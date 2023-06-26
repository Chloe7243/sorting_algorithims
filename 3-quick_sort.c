#include "sort.h"

/**
 * partition - part
 *
 * @array - array to partion
 * @low: low index
 * @high: high index
 */

size_t partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high], smaller;
	size_t i = low, j = high;

	while(i < j)
	{
		while (array[i] <= pivot && i < high)
			i++;
		do {
			j--;
		}while (array[j] > pivot && j > low);
		if (i < j)
		{
			smaller = array[j];
			array[j] = array[i];
			array[i] = smaller;
			print_array(array, size);
		}
	}
	array[high] = array[i];
	array[i] = pivot;
	print_array(array, size);

	return j;
}

void main_sort(int *array, size_t low, size_t high, size_t size)
{
	size_t j;
	if (low < high)
	{
		j = partition(array, low, high, size);
		main_sort(array, low, j, size);
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

	if (!array)
		return;
	main_sort(array, low, high, size);
}
