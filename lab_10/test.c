#include <stdio.h>
#include <stdlib.h>

#include "my_list.h"

void test_insert_to_head(int *error_counter);
void test_insert_to_tail(int *error_counter);
void test_insert_to_null(int *error_counter);
void test_insert_nullptr(int *error_counter);

void test_remove_dups_none_dups(int *error_counter);
void test_remove_dups_with_dups(int *error_counter);
void test_remove_dups_dtnullptr(int *error_counter);
void test_remove_dups_rqnullptr(int *error_counter);

void test_reverse_growing(int *error_counter);
void test_reverse_nullptr(int *error_counter);

void test_sort_decreasing(int *error_counter);

int main(void)
{
    int error_counter = 0;

    test_insert_to_head(&error_counter);
    test_insert_to_tail(&error_counter);
    test_insert_to_null(&error_counter);
    test_insert_nullptr(&error_counter);

    test_remove_dups_none_dups(&error_counter);
    test_remove_dups_with_dups(&error_counter);
    test_remove_dups_dtnullptr(&error_counter);
    test_remove_dups_rqnullptr(&error_counter);

    test_reverse_growing(&error_counter);
    test_reverse_nullptr(&error_counter);

    test_sort_decreasing(&error_counter);

    return (0 == error_counter ? EXIT_SUCCESS : EXIT_FAILURE);
}

void test_insert_to_head(int *error_counter)
{
    printf("Test insert. Insertion before head case. ");

    int is_failure = 0;

    int ind = 0;
    int data[] = { 1, 2 };
    node_t elem;
    node_t head;
    node_t *head_ptr;

    elem.data = data + 0;
    head.data = data + 1;

    elem.next = NULL;
    head.next = NULL;

    head_ptr = &head;

    insert(&head_ptr, &elem, &head);

    for (node_t *cur_node = head_ptr; cur_node != NULL; cur_node = cur_node->next)
    {
        if (ind >= sizeof(data) / sizeof(data[0]))
        {
            is_failure = 1;
            break;
        }

        if (*(int*)(cur_node->data) != data[ind])
        {
            is_failure = 1;
            break;
        }

        ind++;
    }

    if (is_failure)
    {
        *error_counter += 1;

        printf("Failure.\n");

        printf("Insertion value: %d\n", data[0]);

        printf("Expected:\n");
        for (int i = 0, len = sizeof(data) / sizeof(data[0]); i < len; i++)
        {
            printf("%d ", data[i]);
        }
        printf("\n");

        printf("Received:\n");
        for (node_t *cur_node = head_ptr; cur_node != NULL; cur_node = cur_node->next)
        {
            printf("%d ", *(int*)(cur_node->data));
        }
        printf("\n");
    }
    else
    {
        printf("Success.\n");
    }
}

void test_insert_to_tail(int *error_counter)
{
    printf("Test insert. Insertion before tail case. ");

    int is_failure = 0;

    int ind = 0;
    int data[] = { 1, 2, 3 };
    node_t elem;
    node_t head;
    node_t tail;
    node_t *head_ptr;

    head.data = data + 0;
    elem.data = data + 1;
    tail.data = data + 2;

    head.next = &tail;
    elem.next = NULL;
    tail.next = NULL;

    head_ptr = &head;

    insert(&head_ptr, &elem, &tail);

    for (node_t *cur_node = head_ptr; cur_node != NULL; cur_node = cur_node->next)
    {
        if (ind >= sizeof(data) / sizeof(data[0]))
        {
            is_failure = 1;
            break;
        }

        if (*(int*)(cur_node->data) != data[ind])
        {
            is_failure = 1;
            break;
        }

        ind++;
    }

    if (is_failure)
    {
        *error_counter += 1;
        
        printf("Failure.\n");

        printf("Insertion value: %d\n", *(int*)(elem.data));

        printf("Expected:\n");
        for (int i = 0, len = sizeof(data) / sizeof(data[0]); i < len; i++)
        {
            printf("%d ", data[i]);
        }
        printf("\n");

        printf("Received:\n");
        for (node_t *cur_node = head_ptr; cur_node != NULL; cur_node = cur_node->next)
        {
            printf("%d ", *(int*)(cur_node->data));
        }
        printf("\n");
    }
    else
    {
        printf("Success.\n");
    }
}

void test_insert_to_null(int *error_counter)
{
    printf("Test insert. Insertion after tail case. ");

    int is_failure = 0;

    int ind = 0;
    int data[] = { 1, 2 };
    node_t elem;
    node_t head;
    node_t *head_ptr;

    head.data = data + 0;
    elem.data = data + 1;

    head.next = NULL;
    elem.next = NULL;

    head_ptr = &head;

    insert(&head_ptr, &elem, NULL);

    for (node_t *cur_node = head_ptr; cur_node != NULL; cur_node = cur_node->next)
    {
        if (ind >= sizeof(data) / sizeof(data[0]))
        {
            is_failure = 1;
            break;
        }

        if (*(int*)(cur_node->data) != data[ind])
        {
            is_failure = 1;
            break;
        }

        ind++;
    }

    if (is_failure)
    {
        *error_counter += 1;

        printf("Failure.\n");

        printf("Insertion value: %d\n", *(int*)(elem.data));

        printf("Expected:\n");
        for (int i = 0, len = sizeof(data) / sizeof(data[0]); i < len; i++)
        {
            printf("%d ", data[i]);
        }
        printf("\n");

        printf("Received:\n");
        for (node_t *cur_node = head_ptr; cur_node != NULL; cur_node = cur_node->next)
        {
            printf("%d ", *(int*)(cur_node->data));
        }
        printf("\n");
    }
    else
    {
        printf("Success.\n");
    }
}

void test_insert_nullptr(int *error_counter)
{
    printf("Test insert. Null request case. ");

    insert(NULL, NULL, NULL);

    printf("Success.\n");
}

void test_remove_dups_none_dups(int *error_counter)
{
    printf("Test remove_duplicates. Nu duplicates case. ");

    int is_failure = 0;

    int i;
    int len;
    int initial[5] = { 1, 2, 3, 4, 5 };
    int expected[5] = { 1, 2, 3, 4, 5 };
    int received[5] = { 0 };
    node_t *head;
    node_t *tail;

    head = malloc(sizeof(node_t));
    head->data = initial + 0;
    head->next = NULL;
    tail = head;

    for (i = 1, len = sizeof(initial) / sizeof(initial[0]); i < len; i++)
    {
        tail->next = malloc(sizeof(node_t));

        tail->next->data = initial + i;
        tail->next->next = NULL;

        tail = tail->next;
    }

    remove_duplicates(&head, comparator_int);

    tail = head;
    len = sizeof(expected) / sizeof(expected[0]);

    for (i = 0; tail != NULL; i++)
    {
        node_t *temp;

        if (i >= len || expected[i] != *(int*)(tail->data))
        {
            is_failure = 1;
        }
        
        received[i] = *(int*)(tail->data);

        temp = tail;
        tail = tail->next;

        free(temp);
    }

    if (is_failure)
    {
        *error_counter += 1;

        printf("Failure.\n");

        printf("Initial:\n");
        for (int j = 0; j < sizeof(initial) / sizeof(initial[0]); j++)
        {
            printf("%d ", initial[j]);
        }
        printf("\n");

        printf("Expected:\n");
        for (int j = 0; j < len; j++)
        {
            printf("%d ", expected[j]);
        }
        printf("\n");

        printf("Received:\n");
        for (int j = 0; j < i; j++)
        {
            printf("%d ", received[j]);
        }
        printf("\n");
    }
    else
    {
        printf("Success.\n");
    }
}

void test_remove_dups_with_dups(int *error_counter)
{
    printf("Test remove_duplicates. List with duplicates case. ");

    int is_failure = 0;

    int i;
    int len;
    int initial[5] = { 1, 1, 3, 4, 3 };
    int expected[3] = { 1, 3, 4 };
    int received[5] = { 0 };
    node_t *head;
    node_t *tail;

    head = malloc(sizeof(node_t));
    head->data = initial + 0;
    head->next = NULL;
    tail = head;

    for (i = 1, len = sizeof(initial) / sizeof(initial[0]); i < len; i++)
    {
        tail->next = malloc(sizeof(node_t));

        tail->next->data = initial + i;
        tail->next->next = NULL;

        tail = tail->next;
    }

    remove_duplicates(&head, comparator_int);

    tail = head;
    len = sizeof(expected) / sizeof(expected[0]);

    for (i = 0; tail != NULL; i++)
    {
        node_t *temp;

        if (i >= len || expected[i] != *(int*)(tail->data))
        {
            is_failure = 1;
        }
        
        received[i] = *(int*)(tail->data);

        temp = tail;
        tail = tail->next;

        free(temp);
    }

    if (is_failure)
    {
        *error_counter += 1;

        printf("Failure.\n");

        printf("Initial:\n");
        for (int j = 0; j < sizeof(initial) / sizeof(initial[0]); j++)
        {
            printf("%d ", initial[j]);
        }
        printf("\n");

        printf("Expected:\n");
        for (int j = 0; j < len; j++)
        {
            printf("%d ", expected[j]);
        }
        printf("\n");

        printf("Received:\n");
        for (int j = 0; j < i; j++)
        {
            printf("%d ", received[j]);
        }
        printf("\n");
    }
    else
    {
        printf("Success.\n");
    }
}

void test_remove_dups_dtnullptr(int *error_counter)
{
    printf("Test remove_duplicates. Null data case. ");

    node_t head;
    node_t *head_ptr;

    head.data = NULL;
    head.next = NULL;

    head_ptr = &head;

    remove_duplicates(&head_ptr, comparator_int);

    printf("Success.\n");
}

void test_remove_dups_rqnullptr(int *error_counter)
{
    printf("Test remove_duplicates. Null request case. ");

    remove_duplicates(NULL, NULL);

    printf("Success.\n");
}

void test_reverse_growing(int *error_counter)
{
    printf("Test reverse. Growing sequence case. ");

    int is_failure = 0;

    int i;
    int len;
    int initial[5] = { 1, 2, 3, 4, 5 };
    int expected[5] = { 5, 4, 3, 2, 1 };
    int received[5] = { 0 };
    node_t *head;
    node_t *tail;

    head = malloc(sizeof(node_t));
    head->data = initial + 0;
    head->next = NULL;
    tail = head;

    for (i = 1, len = sizeof(initial) / sizeof(initial[0]); i < len; i++)
    {
        tail->next = malloc(sizeof(node_t));

        tail->next->data = initial + i;
        tail->next->next = NULL;

        tail = tail->next;
    }

    head = reverse(head);

    tail = head;
    len = sizeof(expected) / sizeof(expected[0]);

    for (i = 0; tail != NULL; i++)
    {
        node_t *temp;

        if (i >= len || expected[i] != *(int*)(tail->data))
        {
            is_failure = 1;
        }
        
        received[i] = *(int*)(tail->data);

        temp = tail;
        tail = tail->next;

        free(temp);
    }

    if (is_failure)
    {
        *error_counter += 1;

        printf("Failure.\n");

        printf("Initial:\n");
        for (int j = 0; j < sizeof(initial) / sizeof(initial[0]); j++)
        {
            printf("%d ", initial[j]);
        }
        printf("\n");

        printf("Expected:\n");
        for (int j = 0; j < len; j++)
        {
            printf("%d ", expected[j]);
        }
        printf("\n");

        printf("Received:\n");
        for (int j = 0; j < i; j++)
        {
            printf("%d ", received[j]);
        }
        printf("\n");
    }
    else
    {
        printf("Success.\n");
    }   
}

void test_reverse_nullptr(int *error_counter)
{
    printf("Test reverse. Null request case. ");

    reverse(NULL);

    printf("Success.\n");
}

void test_sort_decreasing(int *error_counter)
{
    printf("Test sort. Decreasing sequence case. ");

    int is_failure = 0;

    int i;
    int len;
    int initial[5] = { 5, 4, 3, 2, 1 };
    int expected[5] = { 1, 2, 3, 4, 5 };
    int received[5] = { 0 };
    node_t *head;
    node_t *tail;

    head = malloc(sizeof(node_t));
    head->data = initial + 0;
    head->next = NULL;
    tail = head;

    for (i = 1, len = sizeof(initial) / sizeof(initial[0]); i < len; i++)
    {
        tail->next = malloc(sizeof(node_t));

        tail->next->data = initial + i;
        tail->next->next = NULL;

        tail = tail->next;
    }

    head = sort(head, comparator_int);

    tail = head;
    len = sizeof(expected) / sizeof(expected[0]);

    for (i = 0; tail != NULL; i++)
    {
        node_t *temp;

        if (i >= len || expected[i] != *(int*)(tail->data))
        {
            is_failure = 1;
        }
        
        received[i] = *(int*)(tail->data);

        temp = tail;
        tail = tail->next;

        free(temp);
    }

    if (is_failure)
    {
        *error_counter += 1;

        printf("Failure.\n");

        printf("Initial:\n");
        for (int j = 0; j < sizeof(initial) / sizeof(initial[0]); j++)
        {
            printf("%d ", initial[j]);
        }
        printf("\n");

        printf("Expected:\n");
        for (int j = 0; j < len; j++)
        {
            printf("%d ", expected[j]);
        }
        printf("\n");

        printf("Received:\n");
        for (int j = 0; j < i; j++)
        {
            printf("%d ", received[j]);
        }
        printf("\n");
    }
    else
    {
        printf("Success.\n");
    }   
}
