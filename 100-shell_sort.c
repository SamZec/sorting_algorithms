#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @arg1: The first integer to swap.
 * @arg2: The second integer to swap.
 */
void swap_ints(int *arg1, int *arg2)
{
	int temp;

	temp = *arg1;
	*arg1 = *arg2;
	*arg2 = temp;
}

/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	size_t i = gap;
	size_t j = i;

    /* Check for invalid inputs */
	if (array == NULL || size < 2)
	{
		return;
	}

	while (gap < size / 3)
	{
		gap = gap * 3 + 1;
	}

    /* Sort the array using Shell sort */
	for (; gap >= 1; gap /= 3)
	{
		for (; i < size; i++)
	{
			while (j >= gap && array[j - gap] > array[j])
			{
				/* Swap array[j] and array[j-gap] */
				swap_ints(&array[j], &array[j - gap]);
				j -= gap;
			}

	}

		/* Print the current state of the array */
		print_array(array, size);
	}
}
