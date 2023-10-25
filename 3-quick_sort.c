#include "sort.h"
/**
 * quick_sort - sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * @array: array to be sorted
 * @size: size of array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	if (check_sort(array, size) == 0)
		return;
	/* Call the recursive quicksort function */
	quicksort(array, 0, size - 1, size);
}


/**
 * partition_lomuto - Partition the array using Lomuto scheme.
 * @array: Array to be partitioned.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: Size of the array.
 * Return: Index of the pivot element after partition.
 */
int partition_lomuto(int *array, int low, int high, size_t size)
{
	int pivot = array[high]; /* Choose the pivot as the last element */
	int i = low - 1, temp, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				/* Swap array[i] and array[j] */
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}

	/* Swap array[i + 1] and array[high] (pivot) */
	if (i + 1 != high)
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (i + 1); /* Return the index of the pivot element */
}

/**
 * quicksort - Recursive function to sort the partitioned array.
 * @array: Array to be sorted.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: Size of the array.
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		/* Partition the array and get the index of the pivot element */
		pi = partition_lomuto(array, low, high, size);

		/* Recursive calls to sort the sub-arrays */
		quicksort(array, low, pi - 1, size);
		quicksort(array, pi + 1, high, size);
	}
}

/**
 * check_sort - checks if an array contains sorted elements.
 * @array: array to be chhecked
 * @size: size of array
 * Return: checks if a swap tookplace while traversing the array
 */
int check_sort(int *array, size_t size)
{
	int flag = 0;
	size_t i;

	for (i = 0; i < size - 1; i++)
	{
		if (array[i] > array[i + 1])
		{
			flag = 1;
			break;
		}
	}
	return (flag);
}
