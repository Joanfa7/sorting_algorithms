#include "sort.h"

/**
 * selection_sort - sorts a list using the selection sort algorithm
 *
 * @array: list to sort
 * @size: lenght of list
 *
 * Return: nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int hold, num;

	if (size < 2)
	{
		return;
	}

	for (i = 0; i < size; i++)
	{
		hold = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (hold > array[j])
			{
				hold = array[j];
				num = j;
			}
		}
		if (hold < array[i])
		{
			array[num] = array[i];
			array[i] = hold;
			print_array(array, size);
		}
	}
}

