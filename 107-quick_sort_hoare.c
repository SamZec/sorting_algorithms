#include "sort.h"

void hoare_sort(int *array, size_t size, int lob, int upb);
void swap(int *array, int a, int b);
int hoare_partition(int *array, size_t size, int lob, int upb);

/**
 * quick_sort_hoare - a function that sorts an array of integers
 *		in ascending order using the Quick sort algorithm
 *
 * @array: list of integers to sort
 * @size: size of array
 *
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	hoare_sort(array, size, 0, size - 1);
}

/**
 * hoare_sort - a funtion that sorts intigers base Hoare on partition scheme.
 *
 * @array: array to be sorted
 * @size: size of array
 * @lob: lower boundr of array
 * @upb: upper boundry of rray
 *
 * Return: void
 */
void hoare_sort(int *array, size_t size, int lob, int upb)
{
	int p;

	if (lob < upb && lob >= 0 && upb >= 0)
	{
		p = hoare_partition(array, size, lob, upb);
		hoare_sort(array, size, lob, p - 1);
		hoare_sort(array, size, p + 1, upb);
	}
}

/**
 * swap - a function that rotates to integers
 *
 * @array: list of integers to rotate
 * @a: index of first integer
 * @b: index of second integer
 *
 * Return: void
 */
void swap(int *array, int a, int b)
{
	int temp;

	temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

/**
 * hoare_partition - a function that partition arrays into sub arrays using
 *	Hoare partition scheme.
 *
 * @array: array to partition
 * @size: size of aaray
 * @lob: lower boundry of array
 * @upb: upper boundry of rray
 *
 * Return: position to pivot
 */
int hoare_partition(int *array, size_t size, int lob, int upb)
{
	int p, start = 0, end;

	start = lob - 1;
	end = upb + 1;
	p = array[upb];
	while (start < end)
	{
		while (array[start] < p)
			start++;
		while (array[end] > p)
			end--;
		if (start < end)
		{
			swap(array, start, end);
			print_array(array, size);
		}
	}
	return (start);
}
