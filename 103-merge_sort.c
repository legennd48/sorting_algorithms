#include "sort.h"

/**
 * merge_subarray - Merge two subarrays into a sorted subarray.
 * @sub: subarray
 * @buff: buffer
 * @f: front
 * @mid: middle
 * @back: end
 */
void merge_subarray(int *sub, int *buff, size_t f, size_t mid, size_t back)
{
	size_t i, j, k = 0;

	for (i = f, j = mid; i < mid && j < back; k++)
	{
		buff[k] = (sub[i] < sub[j]) ? sub[i++] : sub[j++];
	}
	for (; i < mid; i++)
	{
		buff[k++] = sub[i];
	}
	for (; j < back; j++)
	{
		buff[k++] = sub[j];
	}
	for (i = f, k = 0; i < back; i++)
	{
		sub[i] = buff[k++];
	}
}

/**
 * top_down_merge_sort - Implement the merge sort algorithm using
 * the top-down approach.
 * @array: array to be sorted
 * @buffer: just a buffer
 * @left: left element index
 * @right: right index
 */
void top_down_merge_sort(int *array, int *buffer, size_t left, size_t right)
{
	size_t mid;

	if (right - left > 1)
	{
		mid = left + (right - left) / 2;
		top_down_merge_sort(array, buffer, left, mid);
		top_down_merge_sort(array, buffer, mid, right);
		merge_subarray(array, buffer, left, mid, right);
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
	int *buffer;

	if (array == NULL || size < 2)
	{
		return;
	}

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
	{
		return;
	}

	top_down_merge_sort(array, buffer, 0, size);
	free(buffer);
}
