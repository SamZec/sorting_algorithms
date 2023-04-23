#include "sort.h"

void swap(int *arg1, int *arg2);

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
	size_t gap, i, j;

    /* Check for invalid inputs */
	if (array == NULL || size < 2)
	{
		return;
	}

	while (gap < (size / 3))
	{
		gap = gap * 3 + 1;
	}

    /* Sort the array using Shell sort */
	for (gap = 1; gap <= (size / 3);)
		gap = gap * 3 + 1;
	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				/* Swap array[j] and array[j-gap] */
				swap(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}
}

/**
 * swap - Swap two integers in an array.
 * @arg1: The first integer to swap.
 * @arg2: The second integer to swap.
 */
void swap(int *arg1, int *arg2)
{
	int temp;

	temp = *arg1;
	*arg1 = *arg2;
	*arg2 = temp;
}

