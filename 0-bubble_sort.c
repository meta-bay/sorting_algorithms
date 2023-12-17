#include "sort.h"

/**
 * bubble_sort - sorts integers in ascending order using bubble sort algorithm
 * @array: pointer to integer array
 * @size: the size
*/

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	if (size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		for (j = 1; j < size; j++)
		{
			if (array[j - 1] > array[j])
			{
				temp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = temp;
			}
		}
	}
}

