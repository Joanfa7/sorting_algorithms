#include "sort.h"

/**
 * quick_sort- sorts an array in asending order
 * @array: array of integers
 * @size: length of integer
 * Return: success
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	recursion(array, 0, size - 1, size);
}

/**
 * recursion- sort a the given array
 * @array: given array
 * @small: smalest int of partion
 * @big: bigest int of partion
 * @size: length of the array
 * Return: success
 */

void recursion(int *array, int small, int big, size_t size)
{
	int pivot;

	if (small < big)
	{
		pivot = partion(array, small, big, size);
		recursion(array, small, pivot - 1, size);
		recursion(array, pivot + 1, big, size);
	}
}

/**
 * partion- find partions of the given array
 * @array: given array
 * @small: smalest int of partion
 * @big: bigest int of partion
 * @size: length of the array
 * Return: success
 */


int partion(int *array, int small, int big, size_t size)
{
	int x = small, y, pivot = array[big];

	for (y = small; y < big; y++)
	{
		if (array[y] <= pivot)
		{
			if (array[x] != array[y])
			{
				swap(&array[x], &array[y]);
				print_array(array, size);
			}
			x++;
		}
	}
	if (x != big)
	{
		swap(&array[x], &array[big]);
		print_array(array, size);
	}
	return (x);
}

/**
 * swap- change values of position
 * @F_elem: element one
 * @Sec_elem: element 2
 * Return: success
 */

void swap(int *F_elem, int *Sec_elem)
{
	int temp = *F_elem;
	*F_elem = *Sec_elem;
	*Sec_elem = temp;
}

