#ifndef __MY_LIST_H
#define __MY_LIST_H

#include <stddef.h>

typedef struct node node_t;

struct node
{
    void *data;
    node_t *next;
};

int comparator_int(const void *pointer1, const void *pointer2);
int comparator_double(const void *pointer1, const void *pointer2);

void insert(node_t **head, node_t *elem, node_t *before);
void front_back_split(node_t *head, node_t **back);
// void remove_duplicates(node_t **head, int (*comparator)(const void*, const void*));
void *pop_back(node_t **head);

node_t *sort(node_t *head, int (*comparator)(const void*, const void*));
node_t *reverse(node_t *head);
node_t *sorted_merge(node_t **head_a, node_t **head_b, int (*comparator)(const void *, const void *));

#endif /*__MY_LIST_H*/
