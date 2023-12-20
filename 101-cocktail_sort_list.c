#include "sort.h"

/**
 * swapNodes - swaps two nodes in a doubly linked list.
 * @currentNode: the current node to be swapped.
 * @list: the whole list.
*/

void swapNodes(listint_t *currentNode, listint_t **list)
{
	currentNode->next->prev = currentNode->prev;
	if (currentNode->prev)
		currentNode->prev->next = currentNode->next;
	else
		*list = currentNode->next;

	currentNode->prev = currentNode->next;
	currentNode->next = currentNode->next->next;
	currentNode->prev->next = currentNode;

	if (currentNode->next)
		currentNode->next->prev = currentNode;
}

/**
 * cocktail_sort_list- performs cocktail sort on a doubly linked list
 * @list: the doubly linked list
*/

void cocktail_sort_list(listint_t **list)
{
	listint_t *temp;
	char swapped = 1;

	if (list == NULL || (*list) == NULL)
		return;

	temp = (*list);
	while (swapped != 0)
	{
		swapped = 0;
		while (temp->next != NULL)
		{
			if (temp->next->n < temp->n)
			{
				swapNodes(temp, list);
				swapped = 1;
				print_list(*list);
			} else
				temp = temp->next;
		}

		if (swapped == 0)
			break;

		swapped = 0;
		while (temp->prev != NULL)
		{
			if (temp->prev->n > temp->n)
			{
				swapNodes(temp->prev, list);
				swapped = 1;
				print_list(*list);
			} else
				temp = temp->prev;
		}
	}
}
