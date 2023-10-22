#ifndef _SORT_H_
#define _SORT_H_

/* headers */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>



/* data structures*/
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Function Prototypes */
void counting_sort(int *array, size_t size);
void swap_list(listint_t **list, listint_t *node1, listint_t *node2);
void cocktail_sort_list(listint_t **list);
void swapDoubleList(listint_t **head, listint_t **nodeA, listint_t *nodeB);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quicksort(int *array, int low, int high, size_t size);
int partition_lomuto(int *array, int low, int high, size_t size);
void shell_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge_subarr(int *subarr, int *buff,
		  size_t front, size_t mid, size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void heap_sort(int *array, size_t size);
void makeHeap(int *array, size_t size, size_t base, size_t root);
void radix_sort(int *array, size_t size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void merge_bitonic_sequence(int *array, size_t size,
			    size_t start, size_t seq, char order);
void create_bitonic_sequence(int *array, size_t size,
			     size_t start, size_t seq, char order);
void bitonic_sort(int *array, size_t size);

#endif /* _SORT_H_ */
