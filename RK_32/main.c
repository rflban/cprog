#include <stdio.h>
#include <stdlib.h>

#include "mylib.h"

int main(int argc, char **argv)
{
    str_t *str = str_create();

    str_insert(str, 0, '5');

    str_delete(str);

    return EXIT_SUCCESS;
}

