#include "sort.h"

void sort_count(int *array, size_t size, int dig, int *temp);
int get_max(int *array, size_t size);

/**
 * radix_sort - a function that sorts an array of integers in ascending
 *		order using the Radix sort algorithm
 *
 * @array: array to be sorted
 * @size: size of array
 *
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int *temp, max, dig;

	if (array == NULL || size < 2)
		return;
	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;
	max = get_max(array, size);
	dig = 1;
	while ((max / dig) > 0)
	{
		sort_count(array, size, dig, temp);
		print_array(array, size);
		dig *= 10;
	}
	free(temp);
}

/**
 * get_max - return max number in array of integers
 *
 * @array: set of integers to return max
 * @size: size fo array
 *
 * Return: the maximum integer
 */
int get_max(int *array, size_t size)
{
	int max;
	size_t i;

	max = array[0];
	i = 1;
	while (i < size)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}
	return (max);
}

/**
 * sort_count - sort arrays of integers using the counting sort algorithm.
 *
 * @array: array of integers
 * @size: size of array
 * @dig: the significant digit to sort
 * @temp: temporal store of array
 *
 * Return: void
 */
void sort_count(int *array, size_t size, int dig, int *temp)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	i = 0;
	while (i < size)
	{
		count[(array[i] / dig) % 10] += 1;
		i++;
	}
	i = 0;
	while (i < 10)
	{
		count[i] += count[i - 1];
		i++;
	}
	for (i = size - 1; (int)i >= 0; i--)
	{
		temp[count[(array[i] / dig) % 10] - 1] = array[i];
		count[(array[i] / dig) % 10] -= 1;
	}
	i = 0;
	while (i < size)
	{
		array[i] = temp[i];
		i++;
	}
}
