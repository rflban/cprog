#include "file.h"

FILE *openf(const char *const name, const char *const mode)
{
    exit_code = __EXIT_SUCCESS;

    FILE *file;

    file = fopen(name, mode);
    if (file == NULL)
        exit_code = __EXIT_FOPEN_ERROR;

    return file;
}

void closef(FILE *file)
{
    exit_code = __EXIT_SUCCESS;

    if (fclose(file) == EOF)
        exit_code = __EXIT_FCLOSE_ERROR;
}