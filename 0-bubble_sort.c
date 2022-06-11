#include "sort.h"

/**
 * bubble_sort - sorts a list by using the bubble sort algorith
 *
 * @array: list to sort
 * @size: lenght of list
 *
 * Return: array sorted in ascending order
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int hold;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				hold = array[j];
				array[j] = array[j + 1];
				array[j + 1] = hold;
				print_array(array, size);
			}
		}
	}
}

