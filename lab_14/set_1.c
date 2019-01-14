#include <stdlib.h>

#include "set_1.h"

struct set_t
{
    int len;
    int capacity;
    item_t *items;
};

int set_pop(set_t set, item_t *item)
{
    if (set_is_empty(set))
    {
        return EXIT_FAILURE;
    }

    set->len -= 1;
    *item = set->items[set->len];

    return EXIT_SUCCESS;
}

int set_push(set_t set, item_t item)
{
    if (set_is_full(set))
    {
        return EXIT_FAILURE;
    }

    set->items[set->len] = item;
    set->len += 1;

    return EXIT_SUCCESS;
}

int set_is_containg(const set_t set, const item_t item)
{
    int pos;

    for (pos = 0; pos < set->len; pos++)
    {
        if (set->items[pos] == item)
        {
            break;
        }
    }

    return pos;
}

bool set_is_full(const set_t set)
{
    return (set->len == set->capacity);
}

bool set_is_empty(const set_t set)
{
    return (set->len == 0);
}

void set_clear(set_t set)
{
    set->len = 0;
}

void set_destroy(set_t set)
{
    free(set->items);
    free(set);
}

set_t set_create(int size)
{
    set_t set = (set_t)malloc(sizeof (struct set_t));

    if (set != NULL)
    {
        set->items = (item_t*)malloc(size * sizeof(item_t));

        if (set->items != NULL)
        {
            set->len = 0;
            set->capacity = size;
        }
        else
        {
            free(set);
            set = NULL;
        }
    }

    return set;
}
