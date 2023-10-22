#include "sort.h"

/**
 * counting_sort - Sort an array of integers in ascending order
 * using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */

void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, i;

	if (array == NULL || size < 2)
		return;
	/* Find the maximum value */
	for (max = array[0], i = 1; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	sorted = malloc(sizeof(int) * size);
	count = malloc(sizeof(int) * (max + 1));
	if (sorted == NULL || count == NULL)
	{
		free(sorted);
		free(count);
		return;
	}
	/* Initialize the counting array */
	for (i = 0; i <= max; i++)
		count[i] = 0;
	/* Count occurrences of each element in the input array */
	for (i = 0; i < (int)size; i++)
		count[array[i]]++;
	/* Build the counting array */
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);
	/* Build the sorted array */
	for (i = size - 1; i >= 0; i--)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	/* Copy sorted elements back to the original array */
	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];
	/* Free allocated memory */
	free(sorted);
	free(count);
}
