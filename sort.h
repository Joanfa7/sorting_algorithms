#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <stdlib.h>



typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);

void print_list(const listint_t *list);


void bubble_sort(int *array, size_t size);

void selection_sort(int *array, size_t size);

void insertion_sort_list(listint_t **list);

void quick_sort(int *array, size_t size);



#endif
