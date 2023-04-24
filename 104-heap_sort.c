#include "sort.h"

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

/**
 * max_heapify - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap(array + root, array + large);
		print_array(array, size);
		max_heapify(array, size, base, large);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */

void heap_sort(int *array, size_t size)
{
	int index;

	/* Check if the array is NULL or has less than 2 elements */
	if (array == NULL || size < 2)
	return;

	/* Build the initial max heap */
	for (index = (size / 2) - 1; index >= 0; index--)
	{
		max_heapify(array, size, size, index);
	}

	/* Sort the array by repeatedly extracting the maximum element */
	for (index = size - 1; index > 0; index--)
	{
		/* Swap the maximum element with the last element */
		swap(array, array + index);

		/* Print the current state of the array*/
		print_array(array, size);

		/* Restore the heap property in the remaining elements */
		max_heapify(array, size, index, 0);
	}
}
