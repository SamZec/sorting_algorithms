#include "sort.h"

int get_max_num(int *array, int size);

/**
 * get_max_num - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */

int get_max_num(int *array, int size)
{
	int max_num = array[0];
	int i = 1;

	if (array == NULL || size == 0)
		return (0);
	for (; i < size; i++)
	{
		if (array[i] > max_num)
			max_num = array[i];
	}
	return (max_num);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, i, max;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;

	max = get_max_num(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		count[i] = 0;

	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;

	for (i = 1; i < (max + 1); i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(count);
}
