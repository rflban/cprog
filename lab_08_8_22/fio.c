#include <stdio.h>

#include "fio.h"
#include "exit.h"


FILE* openf(const char *const name, const char *const mode)
{
    exit_code = 0;

    FILE* file = fopen(name, mode);
    if (file == NULL)
        exit_code = __EXIT_OPEN_ERROR;

    return file;
}

void closef(FILE *file)
{
    exit_code = 0;
    if (fclose(file) == EOF)
        exit_code = __EXIT_CLOSE_ERROR;
}
