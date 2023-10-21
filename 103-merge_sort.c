#include "sort.h"

/**
 * merge - Merges two sorted sub-arrays into a single sorted array.
 * @array: The original array.
 * @left: The left sub-array.
 * @left_size: Size of the left sub-array.
 * @right: The right sub-array.
 * @right_s: Size of the right sub-array.
 */
void merge(int *array, int *left, size_t left_size, int *right, size_t right_s)
{
	size_t i = 0, j = 0, k = 0;

	while (i < left_size && j < right_s)
	{
		if (left[i] <= right[j])
		{
			array[k] = left[i];
			i++;
		}
		else
		{
			array[k] = right[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements, if any, from left sub-array */
	while (i < left_size)
	{
		array[k] = left[i];
		i++;
		k++;
	}

	/* Copy the remaining elements, if any, from right sub-array */
	while (j < right_s)
	{
		array[k] = right[j];
		j++;
		k++;
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order using
 *              the Merge sort algorithm (top-down approach).
 * @array: The array to be sorted.
 * @size: Size of the array.
 */
void merge_sort(int *array, size_t size)
{
	size_t mid, left_size, right_size;
	int *left, *right;

	if (array == NULL || size < 2)
		return;

	/* Base case: if the array contains only one element*/
	if (size <= 1)
		return;

	/* Calculate the mid index */
	mid = size / 2;

	/* Create left and right sub-arrays */
	left = array;
	right = array + mid;

	/* Sizes of left and right sub-arrays */
	left_size = mid;
	right_size = size - mid;

	/* Recursively sort the left and right sub-arrays */
	merge_sort(left, left_size);
	merge_sort(right, right_size);

	/* Merge the sorted sub-arrays */
	merge(array, left, left_size, right, right_size);
}
