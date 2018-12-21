#include <stdlib.h>

#include "my_list.h"
#include "exit.h"

int comparator_int(const void *pointer1, const void *pointer2)
{
    return (*(const int*)(pointer1) - *(const int*)(pointer2));
}

int comparator_double(const void *pointer1, const void *pointer2)
{
    return (*(const double*)(pointer1) - *(const double*)(pointer2));
}

void *pop_back(node_t **head)
{
    exit_code = __EXIT_SUCCESS;

    if ((head == NULL) || (*head == NULL))
    {
        exit_code = __EXIT_NULLPTR;
        return NULL;
    }

    void *poped_value;
    node_t *parent_node;
    node_t *actual_node;

    parent_node = NULL;
    actual_node = *head;

    while (actual_node->next != NULL)
    {
        parent_node = actual_node;
        actual_node = actual_node->next;
    }

    poped_value = actual_node->data;

    if (parent_node == NULL)
    {
        *head = NULL;
    }
    else
    {
        parent_node->next = NULL;
    }

    free(actual_node);

    return poped_value;
}

void insert(node_t **head, node_t *elem, node_t *before)
{
    exit_code = __EXIT_SUCCESS;

    if ((head == NULL) || (*head == NULL) || (elem == NULL))
    {
        exit_code = __EXIT_NULLPTR;
        return;
    }

    node_t *actual_node;
    node_t *parent_node;

    parent_node = NULL;
    actual_node = *head;

    while (actual_node != before && actual_node != NULL)
    {
        parent_node = actual_node;
        actual_node = actual_node->next;
    }

    if (actual_node == NULL)
    {
        return;
    }

    if (parent_node == NULL)
    {
        *head = elem;
    }
    else
    {
        parent_node->next = elem;
    }

    elem->next = before;
}

void remove_duplicates(node_t **head, int (*comparator)(const void*, const void*))
{
    exit_code = __EXIT_SUCCESS;

    if ((head == NULL) || (*head == NULL) || (comparator == NULL))
    {
        exit_code = __EXIT_NULLPTR;
        return;
    }

    node_t *previos_node;
    node_t *present_node;

    previos_node = *head;
    present_node = previos_node->next;

    while (present_node != NULL)
    {
        int compare_result = 0;

        if (previos_node->data == NULL || present_node->data == NULL)
        {
            exit_code = __EXIT_NULLPTR;
            return;
        }

        compare_result = comparator(previos_node->data, present_node->data);
        
        if (compare_result >= 0)
        {
            previos_node->next = present_node->next;

            // free(present_node);

            present_node = previos_node;
        }

        previos_node = present_node;
        present_node = previos_node->next;
    }
}

node_t *reverse(node_t *head)
{
    exit_code = __EXIT_SUCCESS;
    
    if (head == NULL)
    {
        exit_code = __EXIT_NULLPTR;
        return NULL;
    }

    node_t *ensuing_node;
    node_t *present_node;
    node_t *reverse_list;

    reverse_list = NULL;
    present_node = head;

    while (present_node != NULL)
    {
        ensuing_node = present_node->next;
        present_node->next = reverse_list;
        reverse_list = present_node;
        present_node = ensuing_node;
    }

    return reverse_list;
}

void front_back_split(node_t *head, node_t **back)
{
    exit_code = __EXIT_SUCCESS;
    
    if ((head == NULL) || (back == NULL))
    {
        exit_code = __EXIT_NULLPTR;
        return;
    }

    int total_length;
    node_t *current_node;

    total_length = 0;

    for (current_node = head; current_node != NULL; current_node = current_node->next)
    {
        total_length++;
    }

    current_node = head;

    for (int i = 0, length = (total_length / 2) + (total_length % 2); i < length - 1; i++)
    {
        current_node = current_node->next;
    }

    *back = current_node->next;
    current_node->next = NULL;
}

node_t *sorted_merge(node_t **head_a, node_t **head_b, int (*comparator)(const void *, const void *))
{
    exit_code = __EXIT_SUCCESS;

    if ((head_a == NULL) || (head_b == NULL) || (comparator == NULL))
    {
        exit_code = __EXIT_NULLPTR;
        return NULL;
    }

    int compare_result;
    node_t *head;
    node_t *actual_a;
    node_t *actual_b;

    if (*head_a == NULL)
    {
        head = *head_b;
        *head_b = NULL;

        return head;
    }

    if (*head_b == NULL)
    {
        head = *head_a;
        *head_a = NULL;

        return head;
    }

    if (((*head_a)->data == NULL) || ((*head_b)->data == NULL))
    {
        exit_code = __EXIT_NULLPTR;
        return NULL;
    }

    compare_result = comparator((*head_a)->data, (*head_b)->data);

    if (compare_result > 0)
    {
        node_t *temp;

        temp = *head_a;
        *head_a = *head_b;
        *head_b = temp;
    }

    head = *head_a;
    actual_b = *head_b;
    actual_a = *head_a;

    while (actual_a->next != NULL && actual_b != NULL)
    {
        node_t *temp;

        if ((actual_a->next->data == NULL) || (actual_b->data == NULL))
        {
            exit_code = __EXIT_NULLPTR;
            return NULL;
        }

        compare_result = comparator(actual_a->next->data, actual_b->data);

        if (compare_result > 0)
        {
            temp = actual_b;
            actual_b = actual_b->next;

            temp->next = actual_a->next;
            actual_a->next = temp;

            actual_a = actual_a->next;
        }
        else
        {
            actual_a = actual_a->next;
        }
    }

    if (actual_b != NULL)
    {
        actual_a->next = actual_b;
    }

    *head_a = NULL;
    *head_b = NULL;

    return head;
}

node_t *sort(node_t *head, int (*comparator)(const void *, const void *))
{
    exit_code = __EXIT_SUCCESS;

    if (comparator == NULL)
    {
        exit_code = __EXIT_NULLPTR;
        return NULL;
    }

    if (head == NULL)
    {
        return NULL;
    }

    if (head->next == NULL)
    {
        return head;
    }

    node_t *back;
    node_t *head_a;
    node_t *head_b;

    back = NULL;

    front_back_split(head, &back);

    head_a = sort(head, comparator);
    head_b = sort(back, comparator);

    return sorted_merge(&head_a, &head_b, comparator);
}
