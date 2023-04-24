#include "sort.h"

void swap_back(listint_t **list, listint_t **back, listint_t **stir);
void swap_front(listint_t **list, listint_t **back, listint_t **stir);

/**
 * cocktail_sort_list - a function that sorts a doubly linked list of
 *	integers in ascending order using the Cocktail shaker sort algorithm
 *
 * @list: pointer to fisrt node of listint_t list
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *back, *stir;
	bool stired = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	back = *list;
	while (back->next != NULL)
		back = back->next;
	while (stired == false)
	{
		stired = true;
		for (stir = *list; stir != back; stir = stir->next)
		{
			if (stir->n > stir->next->n)
			{
				swap_front(list, &back, &stir);
				print_list((const listint_t *)*list);
				stired = false;
			}
		}
		for (stir = stir->prev; stir != *list; stir = stir->prev)
		{
			if (stir->n < stir->prev->n)
			{
				swap_back(list, &back, &stir);
				print_list((const listint_t *)*list);
				stired = false;
			}
		}
	}
}

/**
 * swap_back - rotate doubly linked list integer with the node behind it
 *
 * @list: pointer to first node in listint_t list
 * @back: pointer to last node
 * @stir: pointer to the current rotating node
 *
 * Return: void
 */
void swap_back(listint_t **list, listint_t **back, listint_t **stir)
{
	listint_t *temp;

	temp = (*stir)->prev;
	if ((*stir)->next != NULL)
		(*stir)->next->prev = temp;
	else
		*back = temp;
	temp->next = (*stir)->next;
	(*stir)->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = *stir;
	else
		*list = *stir;
	(*stir)->next = temp;
	temp->prev = *stir;
	*stir = temp;
}

/**
 * swap_front - rotate doubly linked list integer with the node ahead of it
 *
 * @list: pointer to first node
 * @back: pointer to last node
 * @stir: ponter to current rotating node
 *
 * Return: void
 */
void swap_front(listint_t **list, listint_t **back, listint_t **stir)
{
	listint_t *temp = (*stir)->next;

	if ((*stir)->prev != NULL)
		(*stir)->prev->next = temp;
	else
		*list = temp;
	temp->prev = (*stir)->prev;
	(*stir)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stir;
	else
		*back = *stir;
	(*stir)->prev = temp;
	temp->next = *stir;
	*stir = temp;
}
