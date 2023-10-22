#include "sort.h"

/**
 * heap_sort - sorts an array of integers in ascending order using
 * the Heap sort algorithm
 * @array: array to be sorted
 * @size: size of array
 */

void heap_sort(int *array, size_t size)
{
	int temp;
	size_t i;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2; i > 0; i--)
	{
		makeHeap(array, size, size, i - 1);
	}

	for (i = size; i > 1; i--)
	{
		temp = array[0];
		array[0] = array[i - 1];
		array[i - 1] = temp;
		print_array(array, size);
		makeHeap(array, size, i - 1, 0);
	}
}

/**
 * makeHeap - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 */
void makeHeap(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, largest;
	int temp;

	left = 2 * root + 1;
	right = 2 * root + 2;
	largest = root;

	if (left < base && array[left] > array[largest])
		largest = left;
	if (right < base && array[right] > array[largest])
		largest = right;

	if (largest != root)
	{
		temp = array[root];
		array[root] = array[largest];
		array[largest] = temp;
		print_array(array, size);
		makeHeap(array, size, base, largest);
	}
}
