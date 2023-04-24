#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @n1: A pointer to the first node to swap.
 * @n2: The second node to swap.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *new_node, *previous_node, *temp_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	/* Iterate over each node in the list. */
	for (new_node = (*list)->next; new_node != NULL; new_node = temp_node)
	{
		temp_node = new_node->next; /* Store the next node to be visited. */
		previous_node = new_node->prev; /* Start from the previous node. */

		while (previous_node != NULL && new_node->n < previous_node->n)
		{
			swap_nodes(list, &previous_node, new_node);  /* Swap nodes if necessary. */
			print_list((const listint_t *)*list);  /* Print the updated list. */
			previous_node = new_node->prev;  /* Continue iterating backwards. */
		}
	}
}
