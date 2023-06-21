#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list
 * in acsending order using Insertion Sort algorithm
 * @list: The Doubly Linked List
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current_node = *list, *tmp, *next_node;

    if (list == NULL || *list == NULL)
        return;

    while (current_node != NULL)
    {
        next_node = current_node->next;
        tmp = current_node;
        while (tmp->prev != NULL && tmp->n < tmp->prev->n)
        {
            tmp->prev->next = tmp->next;
            if (tmp->next != NULL)
                tmp->next->prev = tmp->prev;
            tmp->next = tmp->prev;
            tmp->prev = tmp->prev->prev;
            tmp->next->prev = tmp;
            if (tmp->prev == NULL)
                *list = tmp;
            else
                tmp->prev->next = tmp;
            print_list(*list);
        }
        current_node = next_node;
    }
}