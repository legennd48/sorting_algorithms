#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: pointert ti head of list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *next_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	/* Loop through the list starting from the second element */
	for (current = (*list)->next; current != NULL; current = next_node)
	{
		/* Save the next node to be processed */
		next_node = current->next;
		/* Set the prev pointer to the previous node of current */
		prev = current->prev;


		while (prev != NULL && current->n < prev->n)
		{
			/* Swap nodes if the current node is smaller */
			swapDoubleList(list, &prev, current);
			/* Print the list after each swap */
			print_list((const listint_t *)*list);
		}
	}
}


/**
 * swapDoubleList - Helper function to swap two nodes in a doubly-linked list.
 * It updates the pointers of the nodes and the head of the list if necessary.
 * @head: Pointer to the head of the list.
 * @nodeA: First node to be swapped.
 * @nodeB: Second node to be swapped.
 */
void swapDoubleList(listint_t **head, listint_t **nodeA, listint_t *nodeB)
{
	(*nodeA)->next = nodeB->next;
	if (nodeB->next != NULL)
		nodeB->next->prev = *nodeA;
	nodeB->prev = (*nodeA)->prev;
	nodeB->next = *nodeA;
	if ((*nodeA)->prev != NULL)
		(*nodeA)->prev->next = nodeB;
	else
		*head = nodeB;
	(*nodeA)->prev = nodeB;
	*nodeA = nodeB->prev;
}
