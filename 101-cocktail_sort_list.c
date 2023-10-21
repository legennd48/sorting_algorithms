#include "sort.h"

/**
 * swap_list - Swaps two nodes in a doubly linked list.
 * @list: Pointer to the head of the doubly linked list.
 * @a: First node to be swapped.
 * @b: Second node to be swapped.
 */
void swap_list(listint_t **list, listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	else
		*list = b;

	if (b->next)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;
	b->next = a;
	a->prev = b;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list in ascending order
 * using the Cocktail Shaker Sort algorithm.
 * @list: Pointer to the head of the doubly linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *left = NULL, *right = NULL, *current;
	int swapped = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	while (swapped)
	{
		swapped = 0;
		current = *list;
		/* Traverse the list from left to right */
		while (current->next != right)
		{
			if (current->n > current->next->n)
			{
				swap_list(list, current, current->next);
				swapped = 1;
				print_list((const listint_t *)*list);
			}
			else
				current = current->next;
		}
		/* If no swaps occurred, the list is already sorted */
		if (swapped == 0)
			break;
		right = current;
		/* Traverse the list from right to left */
		while (current->prev != left)
		{
			if (current->n < current->prev->n)
			{
				swap_list(list, current->prev, current);
				swapped = 1;
				print_list((const listint_t *)*list);
			}
			else
				current = current->prev;
		}
		left = current;
	}
}
