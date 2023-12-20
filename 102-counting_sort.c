#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: the array
 * @size: size of the array
 */

void counting_sort(int *array, size_t size)
{
	int i, max_val, *counts = NULL, *store = NULL;
	size_t j, temp, count_sum = 0;

	if (array == NULL || size < 2)
		return;

	store = malloc(sizeof(int) * size);
	if (store == NULL)
		return;

	for (j = 0, max_val = 0; j < size; j++)
	{
		store[j] = array[j];
		if (array[j] > max_val)
			max_val = array[j];
	}
	counts = malloc(sizeof(int) * (max_val + 1));
	if (counts == NULL)
	{
		free(store);
		return;
	}
	for (i = 0; i <= max_val; i++)
		counts[i] = 0;
	for (j = 0; j < size; j++)
		counts[array[j]] += 1;
	for (i = 0; i <= max_val; i++)
	{
		temp = counts[i];
		counts[i] = count_sum;
		count_sum += temp;
	}
	for (j = 0; j < size; j++)
	{
		array[counts[store[j]]] = store[j];
		counts[store[j]] += 1;
	}
	print_array(counts, max_val + 1);
	free(counts);
	free(store);
}
