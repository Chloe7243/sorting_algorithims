#include "sort.h"

/**
 * partition - parts array into two using pivot
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
	int pivot = array[high], smaller;
	size_t i = low, j = high;

	while (i < j)
	{
		while (array[i] < pivot && i < high)
			i++;
		do {
			j--;
		} while (array[j] > pivot && j > low);
		if (i < j)
		{
			smaller = array[j];
			array[j] = array[i];
			array[i] = smaller;
			print_array(array, size);
		}
	}
	if (high != i)
	{
		array[high] = array[i];
		array[i] = pivot;
		print_array(array, size);
	}

	return (j);
}

/**
 * main_sort - sort using quick sort algo
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

	if (!array || size < 2)
		return;
	main_sort(array, low, high, size);
}
