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
        case __EXIT_CLOSE_ERROR:
            fprintf(stderr, "Could not close file:\n%s.\n", strerror(errno));
            exit(__EXIT_CLOSE_ERROR);
            break;
        case __EXIT_INVALID_INPUT:
            fprintf(stderr, "Invalid input\n");
            exit(__EXIT_INVALID_INPUT);
            break;
        case __EXIT_EMPTY_INPUT:
            fprintf(stderr, "Not enough data\n");
            exit(__EXIT_EMPTY_INPUT);
            break;
        case __EXIT_NULL_POINTER_REQ:
            fprintf(stderr, "Null pointer request\n");
            exit(__EXIT_NULL_POINTER_REQ);
            break;
        case __EXIT_ALLOC_ERROR:
            fprintf(stderr, "Memory allocate error\n");
            exit(__EXIT_ALLOC_ERROR);
            break;
        case __EXIT_INVALID_DATA:
            fprintf(stderr, "Invalid data\n");
            exit(__EXIT_INVALID_DATA);
            break;
        case __EXIT_MATRICES_SIZE_MISMATCH:
            fprintf(stderr, "Sizes of gotten matrices is mismatching\n");
            exit(__EXIT_MATRICES_SIZE_MISMATCH);
            break;
    }
}
