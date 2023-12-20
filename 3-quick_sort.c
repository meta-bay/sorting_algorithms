#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: the array
 * @size: size of the array
*/

void quick_sort(int *array, size_t size)
{
	partition(array, 0, size - 1, size);
}

/**
 * partition - partition them
 * @array: pointer to the array partition
 * @low: beginning of the array partition
 * @high: end of the array partition
 * @size: size of the array
 */

void partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, temp;

	if (low >= high)
		return;
	pivot = array[high];
	j = low;
	for (i = low; i < high; i++)
	{
		if (array[i] < pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (array[i] != array[j])
				print_array(array, size);
			j++;
		}
	}
	temp = array[high];
	array[high] = array[j];
	array[j] = temp;
	if (array[j] != array[high])
		print_array(array, size);
	partition(array, low, j - 1, size);
	partition(array, j + 1, high, size);
}
