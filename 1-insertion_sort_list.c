#include "sort.h"

/**
 * insertion_sort_list- sorts a linked list of integers in ascending order
 * @list: list to be sorted
 * Return: success
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *NextPtr, *PrevPtr, *Traverse;

	if (list == NULL || (*list)->next == NULL)
		return;

	for (NextPtr = (*list); NextPtr != NULL; NextPtr = Traverse)
	{
		Traverse = NextPtr->next;
		PrevPtr = NextPtr->prev;

		while (PrevPtr != NULL && NextPtr->n < PrevPtr->n)
		{
			swaping(list, &PrevPtr, NextPtr);
			print_list((const listint_t *)*list);
		}
	}
}

/**
 * swaping- swaps the order of nodes
 * @head: first node of the list
 * @right: node to change
 * @left: node to evalueate
 * Return: success
 */

void swaping(listint_t **head, listint_t **left, listint_t *right)
{
	(*left)->next = right->next;
	if (right->next != NULL)
		right->next->prev = *left;

	right->prev = (*left)->prev;
	right->prev = (*left)->prev;
	right->next = *left;

	if ((*left)->prev != NULL)
	{
		(*left)->prev->next = right;
	}
	else
		*head = right;
	(*left)->prev = right;
	*left = right->prev;
}
