#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "exit.h"

int exit_code = 0;

void exit_process()
{
    switch (exit_code)
    {
        case __EXIT_OPEN_ERROR:
            fprintf(stderr, "Could not open file:\n%s.\n", strerror(errno));
            exit(__EXIT_OPEN_ERROR);
            break;
    }
}
