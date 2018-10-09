#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "exit.h"

int exit_code = __EXIT_SUCCESS;

void exit_process()
{
    switch (exit_code)
    {
        case __EXIT_INVALID_USAGE:
            fprintf(stderr,
                "Unexpected usage. Example:\n"
                "example.exe <action> <input_file_1> [<input_file_2>] <output_file>\n"
                "For more information use the only <action>=h");
            exit(__EXIT_INVALID_USAGE);
            break;
        case __EXIT_OPEN_ERROR:
            fprintf(stderr, "Could not open file:\n%s.\n", strerror(errno));
            exit(__EXIT_OPEN_ERROR);
            break;
    }
}
