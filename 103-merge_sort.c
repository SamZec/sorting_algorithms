#include "sort.h"
#include <stdio.h>

void merge_array(int *subarr, int *buff, size_t lob, size_t mid,
		size_t upb);
void merge(int *subarr, int *buff, size_t lob, size_t upb);
void merge_sort(int *array, size_t size);

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;
	merge(array, temp, 0, size);
	free(temp);
}

/**
 * merge_array - Sort a subarray of integers.
 * @subarr: subarray of an array of integers to sort.
 * @buff: buffer to store the sorted subarray.
 * @lob: lower boundry of array.
 * @mid: middle boundry of array.
 * @upb: upper boundry of array.
 */
void merge_array(int *subarr, int *buff, size_t lob, size_t mid,
		size_t upb)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + lob, mid - lob);

	printf("[right]: ");
	print_array(subarr + mid, upb - mid);

	for (i = lob, j = mid; i < mid && j < upb; k++)
		buff[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < mid; i++)
		buff[k++] = subarr[i];
	for (; j < upb; j++)
		buff[k++] = subarr[j];
	for (i = lob, k = 0; i < upb; i++)
		subarr[i] = buff[k++];

	printf("[Done]: ");
	print_array(subarr + lob, upb - lob);
}

/**
 * merge - Implement the merge sort algorithm through recursion.
 * @subarr: subarray of an array of integers to sort.
 * @buff: buffer to store the sorted result.
 * @lob: lower boundry of subarray.
 * @upb: upper boundry of subarray.
 */
void merge(int *subarr, int *buff, size_t lob, size_t upb)
{
	size_t mid;

	if (upb - lob > 1)
	{
		mid = lob + (upb - lob) / 2;
		merge(subarr, buff, lob, mid);
		merge(subarr, buff, mid, upb);
		merge_array(subarr, buff, lob, mid, upb);
	}
}
