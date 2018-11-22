#include "exit.h"

int exit_code = __EXIT_SUCCESS;

void exit_proccess()
{
    switch (exit_code)
    {
        case __EXIT_INV_INP:
            fprintf(stderr, "Invalid input.\n");
            exit(exit_code);
            break;
        case __EXIT_MEM_ERR:
            fprintf(stderr, "Memory error.\n");
            exit(exit_code);
            break;
        case __EXIT_NUL_REQ:
            fprintf(stderr, "NULL request.\n");
            exit(exit_code);
            break;
    }
}