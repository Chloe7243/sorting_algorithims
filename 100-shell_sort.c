#include "sort.h"

/**
 * shell_sort - sorts an array of integers using the Shell sort algorithm
 *
 * @array: array to be sorted
 * @size: size of array
 * Return: void
 */

void shell_sort(int *array, size_t size)
{
	size_t i, j, interval = 1;
	int tmp;


	while (interval < size){
		interval *= 3 + 1;
	}

	while (interval > 0)
	{
		for (j = interval; j < size; j++)
		{
			tmp = array[j];
			i = j;

			while (i > (interval - 1) && array[i - interval] >= tmp)
			{
				array[i] = array[i - interval];
				i -= interval;
			}

			array[i] = tmp;
		}
		interval = (interval - 1) / 3;
		print_array(array, size);
	}

}
