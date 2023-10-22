#include "sort.h"

/**
 * heap_sort - sorts an array of integers in ascending order using
 * the Heap sort algorithm
 * @array: array to be sorted
 * @size: size of array
 */

void heap_sort(int *array, size_t size)
{
	int i, temp;
	size_t idx;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
	{
		idx = makeHeap(array, size, (size_t)i);
		if (idx != (size_t)i)
			print_array(array, size);
	}

	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		idx = makeHeap(array, (size_t)i, 0);
		if (idx != 0)
			print_array(array, size);
	}
}
/**
 * makeHeap - Ensures that the given binary tree rooted at index 'i' satisfies
 * the max-heap property: the value of each node is greater than or equal to
 * the values of its children. If the max-heap property is violated, the
 * function swaps the node with its largest child and recursively adjusts the
 * affected subtree.
 *
 * @arr: The array representing the binary tree.
 * @size: The total number of elements in the array.
 * @i: Index of the node to be checked and adjusted.
 * Return: flag
 */

size_t makeHeap(int arr[], size_t size, size_t i)
{
	size_t largest = i, left = 2 * i + 1, right = 2 * i + 2, temp;

	if (left < size && arr[left] > arr[largest])
		largest = left;

	if (right < size && arr[right] > arr[largest])
		largest = right;

	if (largest != i)
	{
		temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		return (largest);
	}

	return (i);
}
