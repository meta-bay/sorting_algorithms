#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm
 * @list: pointer to the list
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *temp1, *temp2;

	if (list != NULL)
		temp2 = (*list)->next;

	while (list != NULL && temp2 != NULL)
	{
		temp1 = temp2->prev;
		while (temp1 != NULL && temp1->n > temp2->n)
		{
			temp1->next = temp2->next;
			if (temp2->next != NULL)
				temp2->next->prev = temp1;
			temp2->next = temp1;
			temp2->prev = temp1->prev;
			if (temp1->prev != NULL)
				temp1->prev->next = temp2;
			temp1->prev = temp2;

			if (temp2->prev == NULL)
			{
				(*list) = temp2;
				print_list(*list);
				break;
			}
			temp1 = temp2->prev;
			print_list(*list);
		}
		temp2 = temp2->next;
	}
}
