#include "sort.h"


/**
 * merge_bitonic_sequence - Sort a bitonic sequence inside an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the sequence in array to sort.
 * @seq: The size of the sequence to sort.
 * @order: The direction to sort in (UP or DOWN).
 */
void merge_bitonic_sequence(int *array, size_t size,
			    size_t start, size_t seq, char order)
{
	size_t i, jump = seq / 2;
	int temp;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((order == 'U' && array[i] > array[i + jump]) ||
			    (order == 'D' && array[i] < array[i + jump]))
			{
				temp = array[i];
				array[i] = array[i + jump];
				array[i + jump] = temp;
			}
		}
		merge_bitonic_sequence(array, size, start, jump, order);
		merge_bitonic_sequence(array, size, start + jump, jump, order);
	}
}

/**
 * create_bitonic_sequence - Convert an array of integers into a bitonic seq.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of a block of the building bitonic sequence.
 * @seq: The size of a block of the building bitonic sequence.
 * @order: The direction to sort the bitonic sequence block in (UP or DOWN).
 */

void create_bitonic_sequence(int *array, size_t size,
			     size_t start, size_t seq, char order)
{
	size_t cut = seq / 2;
	const char *direction = (order == 'U') ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, direction);
		print_array(array + start, seq);

		create_bitonic_sequence(array, size, start, cut, 'U');
		create_bitonic_sequence(array, size, start + cut, cut, 'D');
		merge_bitonic_sequence(array, size, start, seq, order);

		printf("Result [%lu/%lu] (%s):\n", seq, size, direction);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 * order using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (i.e., size equal to powers of 2).
 */

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	create_bitonic_sequence(array, size, 0, size, 'U');
}
