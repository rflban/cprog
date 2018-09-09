#include <stdio.h>

#include "file_control.h"
#include "exit_control.h"


int open_file(FILE** file, const char* const name, const char* const mode)
{
    *file = fopen(name, mode);
    if (*file == NULL)
        return EXIT_OPEN_ERROR_;
    return EXIT_SUCCESS_;
}

int close_file(FILE* file)
{
    if (fclose(file) == EOF)
        return EXIT_CLOSE_ERROR_;
    return EXIT_SUCCESS_;
}

int carriage_return(FILE* file)
{
    int rc;

    rc = fseek(file, 0, SEEK_SET);
    if (rc != 0)
        return EXIT_INPUT_ERROR_;

    return EXIT_SUCCESS_;
}
