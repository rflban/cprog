#define __NEED_PROC_FUBC
#include "exit.h"

#include <stdio.h>
#include <stdlib.h>

int exit_code = __EXIT_SUCCESS;

void exit_process()
{
    switch (exit_code)
    {
        case __EXIT_FAILURE:
            exit(exit_code);
            break;
        case __EXIT_NULLPTR:
            fprintf(stderr, "Null pouter request.\n");
            exit(exit_code);
            break;
        case __EXIT_MEMFAIL:
            fprintf(stderr, "Memory allocation error.\n");
            exit(exit_code);
            break;
        case __EXIT_READERR:
            fprintf(stderr, "Read error.\n");
            exit(exit_code);
            break;
        case __EXIT_OPENERR:
            fprintf(stderr, "Open error.\n");
            exit(exit_code);
            break;
        case __EXIT_CLOSERR:
            fprintf(stderr, "Close error.\n");
            exit(exit_code);
            break;
    }
}
