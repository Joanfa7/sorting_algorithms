#include "sort.h"
#include <stdio.h>

/**
 * sw - switches nodes in a souble linked list
 *
 * @h: head of double linked list
 * @first: first node to swap
 * @sec: second node to swap
 *
 * Return: nothing
 */

void sw(listint_t **h, listint_t *first, listint_t *sec)
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

	if (sec->prev == NULL)
	{
		(*h) = sec;
	}
}

/**
 * cocktail_sort_list - sorts a list using cocktail shaker sort algorithm
 *
 * @list: list to be sorted
 *
 * Return: nothing
 */

void cocktail_sort_list(listint_t **list)
{
	int size, start = 0, i, con = 1;
	listint_t *node;

	if (list == NULL)
		return;
	node = *list;
	for (size = 0; node != NULL; size++)
		node = node->next;
	if (size < 2)
		return;
	node = *list;
	while (con > 0)
	{
		con = -1;
		for (i = start; i < size && node->next != NULL; i++)
		{
			if (node->n > node->next->n)
			{
				sw(list, node, node->next);
				node = node->prev;
				print_list((const listint_t *)*list);
			}
			node = node->next;
		}
		node = node->prev;
		size--;
		for (i = size; i > start && node->prev != NULL; i--)
		{
			if (node->n < node->prev->n)
			{
				sw(list, node->prev, node);
				node = node->next;
				print_list((const listint_t *)*list);
				con = 1;
			}
			node = node->prev;
		}
		start++;
		node = node->next;
	}
}

