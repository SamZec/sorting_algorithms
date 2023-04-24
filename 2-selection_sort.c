#include "sort.h"

/**
 * selection_sort - a function that sorts an array of integers in ascending
 *	order using the Selection sort algorithm
 *
 * @array: array of intrgers to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	int temp;
	size_t loop, search, min;

	for (loop = 0; loop < size - 1; loop++)
	{
		min = loop;
		for (search = loop + 1; search < size; search++)
		{
			if (array[search] < array[min])
				min = search;
		}
		if (min != loop)
		{
			temp = array[loop];
			array[loop] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
