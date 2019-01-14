#ifndef __TRIE_H
#define __TRIE_H

#include "my_list.h"

typedef struct trie_t
{
    node_t *root;
}
trie_t;

typedef struct trie_node_t
{
    char mark;
    void *data;
    node_t *childs;
}
trie_node_t;

void trie_add(trie_t *trie, char *key, void *data);

void trie_destroy(trie_t *trie);

void *trie_read(const trie_t *trie, char *key);

trie_t *trie_create();

#endif
