#include "sort.h"

/**
 * merge_subarr - works with othe functions to sort a subarray of integers.
 * for the mergesort funstion
 * @subarr: A subarray.
 * @buff: buffer to store the sorted subarray.
 * @front: front index of the array.
 * @mid: middle index of the array.
 * @back: end index of the array.
 */
void merge_subarr(int *subarr, int *buff,
		  size_t front, size_t mid, size_t back)
{
	size_t j, k = 0, i = 0;

	printf("Merging...\n[left]: ");
	for (i = front; i < mid; ++i)
		printf("%d ", subarr[i]);
	printf("\n[right]: ");
	for (i = mid; i < back; ++i)
		printf("%d ", subarr[i]);
	printf("\n");

	for (i = front, j = mid; i < mid && j < back; ++k)
		buff[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < mid; ++i)
	{
		buff[k++] = subarr[i];
	}
	for (; j < back; ++j)
	{
		buff[k++] = subarr[j];
	}
	for (i = front, k = 0; i < back; ++i)
	{
		subarr[i] = buff[k++];
	}

	printf("[Done]: ");
	for (i = front; i < back; ++i)
	{
		printf("%d ", subarr[i]);
	}
	printf("\n");
}

/**
 * merge_sort_recursive - merge sort algorithm by recursion.
 * @subarr: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted result.
 * @front: The front index of the subarray.
 * @back: The back index of the subarray.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, mid);
		merge_sort_recursive(subarr, buff, mid, back);
		merge_subarr(subarr, buff, front, mid, back);
	}
}
/**
 * merge_sort - Sorts an array of integers in ascending order using
 * the Merge sort algorithm (top-down approach).
 * @array: The array to be sorted.
 * @size: Size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}
