#include "sort.h"

void swap(int *a, int *b);
int part_array(int *array, size_t size, int lob, int upb);
void lomuto_sort(int *array, size_t size, int lob, int upb);
void quick_sort(int *array, size_t size);

/**
 * quick_sort - Sort an array of integers in ascending
 *		order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lomuto_sort(array, size, 0, size - 1);
}

/**
 * swap - rotate two integers in an array.
 *
 * @int_a: The first integer to swap.
 * @int_b: The second integer to swap.
 */
void swap(int *int_a, int *int_b)
{
	int tmp;

	tmp = *int_a;
	*int_a = *int_b;
	*int_b = tmp;
}

/**
 * part_array - partition array of integers according to
 *	the lomuto partition scheme (last element as pivot).
 *
 * @array: The array of integers.
 * @size: The size of the array.
 * @lob: The starting index of the subset to order.
 * @upb: The ending index of the subset to order.
 *
 * Return: pivot index.
 */
int part_array(int *array, size_t size, int lob, int upb)
{
	int *pivot, above, below;

	pivot = array + upb;
	for (above = below = lob; below < upb; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 *
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @lob: The starting index of the array partition to order.
 * @upb: The ending index of the array partition to order.
 *
 * Return: void
 */
void lomuto_sort(int *array, size_t size, int lob, int upb)
{
	int part;

	if (upb - lob > 0)
	{
		part = part_array(array, size, lob, upb);
		lomuto_sort(array, size, lob, part - 1);
		lomuto_sort(array, size, part + 1, upb);
	}
}
