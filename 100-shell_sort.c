#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using the
 * Shell sort algorithm
 * @array: the array
 * @size: size of the array
 */

void shell_sort(int *array, size_t size)
{
	size_t i, j, btn;
	int put_temp;

	if (array == NULL || size < 2)
		return;
	btn = 1;
	while (btn < size / 3)
		btn = btn * 3 + 1;

	while (btn > 0)
	{
		for (i = btn; i < size; i++)
		{
			put_temp = array[i];
			for (j = i; j >= btn && array[j - btn] > put_temp; j = j - btn)
				array[j] = array[j - btn];
			array[j] = put_temp;
		}
		btn = (btn - 1) / 3;
		print_array(array, size);
	}
}
