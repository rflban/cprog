#include <stdio.h>

#include "exit.h"
#include "my_list.h"
#include "trie.h"


int main(int argc, char **argv)
{
    int data[] = { 1, 2, 3, 4, 5 };
    trie_t *trie = trie_create();
    void *res;

    trie_add(trie, "one", data);
    trie_add(trie, "two", data + 1);
    trie_add(trie, "five", data + 4);

    res = trie_read(trie, "one");
    if (res != NULL)
    {
        printf("%d\n", *(int*)res);
    }
    else
    {
        printf("Not found.\n");
    }

    res = trie_read(trie, "two");
    if (res != NULL)
    {
        printf("%d\n", *(int*)res);
    }
    else
    {
        printf("Not found.\n");
    }

    res = trie_read(trie, "four");
    if (res != NULL)
    {
        printf("%d\n", *(int*)res);
    }
    else
    {
        printf("Not found.\n");
    }

    res = trie_read(trie, "five");
    if (res != NULL)
    {
        printf("%d\n", *(int*)res);
    }
    else
    {
        printf("Not found.\n");
    }

    trie_destroy(trie);

    return __EXIT_SUCCESS;
}
