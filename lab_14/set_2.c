#include <stdlib.h>

#include "set_2.h"

struct node_t
{
    item_t item;
    struct node_t *next;
};

struct set_t
{
    struct node_t *head;
};

int set_pop(set_t set, item_t *item)
{
    if (set->head == NULL)
    {
        return EXIT_FAILURE;
    }

    struct node_t *present_node;
    struct node_t *previos_node;

    present_node = set->head;

    while (present_node->next != NULL)
    {
        previos_node = present_node;
        present_node = present_node->next;
    }

    *item = present_node->item;

    if (present_node == set->head)
    {
        set->head = NULL;
    }
    else
    {
        previos_node->next = NULL;
    }

    free(present_node);

    return EXIT_SUCCESS;
}

int set_push(set_t set, item_t item)
{
    struct node_t *cur_node;
    struct node_t *new_node;

    new_node = (struct node_t *)malloc(sizeof(struct node_t));

    if (new_node == NULL)
    {
        return EXIT_FAILURE;
    }

    new_node->item = item;
    new_node->next = NULL;

    if (set->head == NULL)
    {
        set->head = new_node;

        return EXIT_SUCCESS;
    }
    
    cur_node = set->head;

    while (cur_node->next != NULL)
    {
        cur_node = cur_node->next;
    }

    cur_node->next = new_node;

    return EXIT_SUCCESS;
}

bool set_is_full(const set_t set)
{
    return false;
}

bool set_is_empty(const set_t set)
{
    return (set->head == NULL);
}

void set_destroy(set_t set)
{
    struct node_t *node;
    struct node_t *temp;

    node = set->head;

    while (node != NULL)
    {
        temp = node;
        node = node->next;

        free(temp);
    }

    free(set);
}

set_t set_create(void)
{
    set_t set = (set_t)malloc(sizeof(struct set_t));

    if (set != NULL)
    {
        set->head = NULL;
    }

    return set;
}

struct node_t *set_is_containg(const set_t set, const item_t item)
{
    struct node_t *node;

    node =  set->head;

    while (node != NULL)
    {
        if (node->item == item)
        {
            break;
        }

        node = node->next;
    }

    return node;
}
