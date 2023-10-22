#include "sort.h"
/**
 * shell_sort - sorts an array of integers in ascending order using
 * the Shell sort algorithm, using the Knuth sequence
 * @array: Array to be sorted
 * @size: size of array
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	if (array == NULL || size <= 1)
		return;
	/* Calculate the initial gap using Knuth sequence */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	/* Start sorting with decreasing intervals */
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			/* Perform insertion sort within the interval gap */
			temp = array[i];
			j = i;
			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}

			array[j] = temp;
		}

		/* Print the array after decreasing the interval */
		print_array(array, size);

		/* Calculate the next gap using Knuth sequence */
		gap = (gap - 1) / 3;
	}
}
