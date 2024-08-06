#include "sort.h"

/**
 * swap - Swaps two integers in an array
 * @a: The first integer to swap
 * @b: The second integer to swap
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


/**
 * selection_sort - Sorts an array of integers in ascending order using the
 *                  Selection sort algorithm.
 * @array: The array to be sorted
 * @size: The number of elements in the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}
		if (min_index != i)
		{
			swap(&array[i], &array[min_index]);
			print_array(array, size);
		}
	}
}
