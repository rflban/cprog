#include <stdio.h>
#include <stdlib.h>

#include "mylib.h"

int main(int argc, char **argv)
{
    str_t *str = str_create();

    str_insert(str, 0, '5');
    str_insert(str, 1, '4');

    printf("%d\n", str_search(str, "54"));
    str_remove(str, 0);

    str_delete(str);

    return EXIT_SUCCESS;
}

