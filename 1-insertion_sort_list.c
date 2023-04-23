#include "sort.h"

void pos_node(listint_t **head, listint_t **node_1, listint_t *node_2);

/**
 * insertion_sort_list - a function that sorts a doubly linked list
 *	of integers in ascending order using the Insertion sort algorithm
 *
 * @list: linked list of integers
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *unsorted, *sorted;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (unsorted = (*list)->next; unsorted != NULL; unsorted = temp)
	{
		temp = unsorted->next;
		sorted = unsorted->prev;
		while (sorted != NULL && unsorted->n < sorted->n)
		{
			pos_node(list, &sorted, unsorted);
			print_list((const listint_t *)*list);
		}
	}
}

/**
 * pos_node - Puts nodes in thier right position in a
 *	listint_t doubly-linked list.
 * @head: A points to the head of the doubly-linked list.
 * @node_1: First node to position.
 * @node_2: The second node to position.
 */
void pos_node(listint_t **head, listint_t **node_1, listint_t *node_2)
{
	(*node_1)->next = node_2->next;
	if (node_2->next != NULL)
		node_2->next->prev = *node_1;
	node_2->prev = (*node_1)->prev;
	node_2->next = *node_1;
	if ((*node_1)->prev != NULL)
		(*node_1)->prev->next = node_2;
	else
		*head = node_2;
	(*node_1)->prev = node_2;
	*node_1 = node_2->prev;
}
