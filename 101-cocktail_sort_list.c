#include "sort.h"
#include <stdio.h>

void sw(listint_t *first, listint_t *sec)
{
	if (first->prev != NULL)
	{
		first->prev->next = sec;
		sec->prev = first->prev;
	}
	else
	{
		sec->prev = NULL;
	}

	first->prev = sec;

	if (sec->next != NULL)
	{
		sec->next->prev = first;
		first->next = sec->next;
	}
	else
	{
		first->next = NULL;
	}

	sec->next = first;
}

/*
 * cocktail_sort_list - sorts a list using cocktail shaker sort algorithm
 *
 * @list: list to be sorted
 *
 * Return: nothing
 */

void cocktail_sort_list(listint_t **list)
{
	int size, start = 0, i, con = 1;
	listint_t *node = *list;
	listint_t *hold = *list;

	if (list == NULL)
	{
		return;
	}

	for (size = 0; node->next != NULL; size++)
	{
		node = node->next;
	}

	if (size < 2)
	{
		return;
	}

	node = hold;

	while (con > 0)
	{
		con = -1;
		for (i = start; i < size; i++)
		{
			if (node->n > node->next->n)
			{
				sw(node, node->next);
				node = node->prev;
				print_list((const listint_t *)*list);
			}
			if (node->next != NULL)
			{
				node = node->next;
			}

		}

		node = node->prev;
		size--;
		for (i = size - 1; i > start; i--)
		{
			if (node->n < node->prev->n)
			{
				sw(node->prev, node);
				node = node->next;
				print_list((const listint_t *)*list);
				con = 1;
			}
			if (node->prev != NULL)
			{
				node = node->prev;
			}
		}
		start++;
	}
}

