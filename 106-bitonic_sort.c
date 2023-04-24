#include "sort.h"
#include <stdio.h>

void merge(int *array, size_t size, size_t index, size_t _size, char dir);
void bitonic(int *array, size_t size, size_t index, size_t _size, char dir);
void swap(int *a, int *b);

/**
 * bitonic_sort - a function that sorts an array of integers in
 *		ascending order using the Bitonic sort algorithm
 *
 * @array: array to be sorted
 * @size: size of array
 *
 * Return: void
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	bitonic(array, size, 0, size, UP);
}

/**
 * bitonic - a function that converts integers into bitonic sequence
 *
 * @array: array of integers
 * @size: size of array
 * @index: starting index the sequence
 * @_size: size of the squence
 * @dir: direction for sequence
 *
 * Return: void
 */
void bitonic(int *array, size_t size, size_t index, size_t _size, char dir)
{
	size_t half = _size / 2;
	char *str = (dir == UP) ? "UP" : "DOWN";

	if (_size > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", _size, size, str);
		print_array(array + index, _size);
		bitonic(array, size, index, half, UP);
		bitonic(array, size, index + half, half, DOWN);
		merge(array, size, index, _size, dir);
		printf("Result [%lu/%lu] (%s):\n", _size, size, str);
		print_array(array + index, _size);
	}
}

/**
 * swap - a function that rotates two integers
 *
 * @a: first integer
 * @b: second integer
 *
 * Return: void
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * merge - merge bitonic sequence in an array
 *
 * @array: array of integers
 * @size: size of array
 * @index: starting index of sequence
 * @_size: size of sequence
 * @dir: dir of sequence
 *
 * Return: void
 */
void merge(int *array, size_t size, size_t index, size_t _size, char dir)
{
	size_t i, _step;

	_step = _size / 2;
	if (_size > 1)
	{
		i = index;
		while (i < (index + _step))
		{
			if ((dir == UP && array[i] > array[i + _step]) ||
			(dir == DOWN && array[i] < array[i + _step]))
				swap(array + i, array + i + _step);
			i++;
		}
		 merge(array, size, index, _step, dir);
		 merge(array, size, index + _step, _step, dir);
	}
}
