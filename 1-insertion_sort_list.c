#include "sort.h"
/**
 * insertion_sort_list -  insertion sort on list
 * @list: list of ints
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{

listint_t *current, *prev_n, *next_n;

if ((*list)->next == NULL)
	return;
else if (list == NULL)
	return;
else if (*list == NULL)
	return;
current = (*list)->next;

while (current != NULL)
	{
	next_n = current->next;
	prev_n = current->prev;

	while (prev_n != NULL && prev_n->n > current->n)
	{
		prev_n->next = current->next;

		if (current->next != NULL)
			current->next->prev = prev_n;

		current->next = prev_n;
		current->prev = prev_n->prev;
		prev_n->prev = current;

		if (current->prev != NULL)
			current->prev->next = current;
		else
			*list = current;

		print_list(*list);
		prev_n = current->prev;
	}
	current = next_n;
	}
}
