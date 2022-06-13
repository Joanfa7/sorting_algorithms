#include "sort.h"

/**
 * bubble_sort - sorts a list by using the bubble sort algorith
 *
 * @array: list to sort
 * @size: lenght of list
 *
 * Return: nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int hold;

	if (size < 2)
	{
		return;
	}

	for (i = 0; i < size; i++)
	{
		for (j = 1; j < size - i; j++)
		{
			if (array[j - 1] > array[j])
			{
				hold = array[j - 1];
				array[j - 1] = array[j];
				array[j] = hold;
				print_array(array, size);
			}
		}
	}
}

