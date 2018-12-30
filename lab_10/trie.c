#include "trie.h"

#include <stdlib.h>
#include <stdio.h>

node_t *node_init(char mark);
trie_node_t *trie_node_create();
void node_destroy(node_t *node);
void trie_node_destroy(trie_node_t *tnode);

void trie_add(trie_t *trie, char *key, void *data)
{
    char *mark;
    node_t *present_node;
    node_t *previos_node;
    trie_node_t *present_tnode;

    if (trie->root == NULL)
    {
        trie->root = node_init(key[0]);
    }

    mark = key;
    previos_node = NULL;
    present_node = trie->root;

    while ('\0' != *mark)
    {
        while (present_node != NULL)
        {
            present_tnode = (trie_node_t*)(present_node->data);

            if (*mark == present_tnode->mark)
            {
                if ('\0' == *(mark + 1))
                {
                    mark++;
                    break;
                }

                if (present_tnode->childs == NULL)
                {
                    present_tnode->childs = node_init(*mark);
                }

                mark++;
                present_node = present_tnode->childs;

                break;
            }

            previos_node = present_node;
            present_node = present_node->next;
        }

        if (('\0' != *mark) && (present_node == NULL))
        {
            previos_node->next = node_init(*mark);
            present_node = previos_node->next;
        }
    }

    present_tnode = (trie_node_t*)(present_node->data);

    if (present_tnode->data != NULL)
    {
        return;
    }


    present_tnode->data = data;
}

void trie_destroy(trie_t *trie)
{
    node_destroy(trie->root);

    free(trie);
}

void node_destroy(node_t *node)
{
    if (node == NULL)
    {
        return;
    }

    node_destroy(node->next);
    trie_node_destroy(node->data);

    free(node);
}

void trie_node_destroy(trie_node_t *tnode)
{
    node_destroy(tnode->childs);
    
    free(tnode);
}

void *trie_read(const trie_t *trie, char *key)
{
    char *mark;
    const node_t *present_node;
    const trie_node_t *present_tnode;

    mark = key;
    present_node = trie->root;

    while ('\0' != *mark)
    {
        while (present_node != NULL)
        {
            present_tnode = (trie_node_t*)(present_node->data);

            if (*mark == present_tnode->mark)
            {
                if ('\0' == *(mark + 1))
                {
                    return present_tnode->data;
                }

                mark++;
                present_node = present_tnode->childs;
            }
            else
            {
                present_node = present_node->next;
            }
        }

        if (present_node == NULL)
        {
            break;
        }
    }

    return NULL;
}

trie_t *trie_create()
{
    trie_t *trie;

    trie = (trie_t*)malloc(sizeof(trie_t));

    if (trie == NULL)
    {
        return NULL;
    }

    trie->root = NULL;

    return trie;
}

trie_node_t *trie_node_create()
{
    trie_node_t *trie_node;

    trie_node = (trie_node_t*)malloc(sizeof(trie_node_t));

    if (trie_node == NULL)
    {
        return NULL;
    }

    trie_node->mark = 0;
    trie_node->data = NULL;
    trie_node->childs = NULL;

    return trie_node;
}

node_t *node_init(char mark)
{
    node_t *new_node;
    trie_node_t *new_trie_node;

    new_node = (node_t*)malloc(sizeof(node_t));

    if (new_node == NULL)
    {
        return NULL;
    }

    new_trie_node = trie_node_create();

    if (new_trie_node == NULL)
    {
        return NULL;
    }

    new_trie_node->mark = mark;

    new_node->next = NULL;
    new_node->data = new_trie_node;

    return new_node;
}
