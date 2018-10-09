#include <stdio.h>

#include "ref.h"
#include "exit.h"

int is_correct_usage(int argc, char **argv)
{
    exit_code = __EXIT_SUCCESS;

    if (argc != 4 && argc != 5)
        exit_code = __EXIT_INVALID_USAGE;
    else if (argv[1][0] != 'a' && argv[1][0] != 'm' && argv[1][0] != 'o')
        exit_code = __EXIT_INVALID_USAGE;
    else if (argv[1][1] != 0)
        exit_code = __EXIT_INVALID_USAGE;

    if (argc == 2 && argv[1][0] == 'h' && argv[1][1] != '0')
        exit_code = __EXIT_SUCCESS;

    return exit_code == __EXIT_SUCCESS;
}

void show_help()
{
    fprintf(stderr, "Action values:\n"
        "a\taddition\n"
        "m\tmultiplication\n"
        "o\tcalculation of the determinant by Gauss method\n"
        "h\thelp\n");
}
