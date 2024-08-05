#include "sort.h"

/**
 * swap_nodes - Swaps two adjacent nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @left: Pointer to the left node
 * @right: Pointer to the right node
 */

void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	if (!left || !right || left == right)
		return;

	if (left->prev)
		left->prev->next = right;
	else
		*list = right;

	if (right->next)
		right->next->prev = left;

	left->next = right->next;
	right->prev = left->prev;
	right->next = left;
	left->next = right;
	print_list(*list);
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                       order using the Insertion sort algorithm
 * @list: Double pointer to the head of the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next, *insert_point;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;

	while (current)
	{
		next = current->next;
		insert_point = current->prev;

		while (insert_point && current->n < insert_point->n)
		{
			listint_t *prev_insert_point = insert_point->prev;
			swap_nodes(list, insert_point, current);
			insert_point = prev_insert_point;
		}
		current = next;
	}
}
