#define __NEED_PROC_FUBC
#include "exit.h"

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
            pfrintf("Null pouter request.\n");
            exit(exit_code);
            break;
        case __EXIT_MEMFAIL:
            pfrintf("Memory allocation error.\n");
            exit(exit_code);
            break;
        case __EXIT_READERR:
            pfrintf("Read error.\n");
            exit(exit_code);
            break;
        case __EXIT_OPENERR:
            pfrintf("Open error.\n");
            exit(exit_code);
            break;
        case __EXIT_CLOSERR:
            pfrintf("Close error.\n");
            exit(exit_code);
            break;
    }
}
