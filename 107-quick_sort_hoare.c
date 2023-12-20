#include "sort.h"

/**
 * hoare_partition - partitioning
 * @array: the array
 * @low: to the left
 * @high: to the right
 * @size: size of the array
 * Return: the pivot
 */

int hoare_partition(int *array, int low, int high, size_t size)
{
	int i, j, pivot, temp;

	pivot = array[high];
	i = low - 1;
	j = high + 1;

	for (; i < j;)
	{
		do {
			i = i + 1;
		} while (array[i] < pivot);
		do {
			j = j - 1;
		} while (array[j] > pivot);
		if (i < j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}
	return (i);
}

/**
 * recursive - performs recursion
 * @array: the array
 * @low: lower bound of the array
 * @high: higher bound of the array
 * @size: size of the entire array
 */

void recursive(int *array, int low, int high, size_t size)
{
	int pivot;

	if (high - low > 0)
	{
		pivot = hoare_partition(array, low, high, size);

		recursive(array, low, pivot - 1, size);
		recursive(array, pivot, high, size);
	}
}

/**
 * quick_sort_hoare - sorts an array using Quick sort algorithm
 * with Hoare Partition Scheme
 * @array: array to be sorted
 * @size: size of the array
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (size <= 1)
		return;
	recursive(array, 0, (size - 1), size);
}
