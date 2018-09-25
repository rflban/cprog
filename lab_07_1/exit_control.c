#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "exit_control.h"

int usage_check(int argc, char **argv)
{
    if (argc == 3)
        return EXIT_SUCCESS_;
    //if (argc == 4 && argv[3][0] == 'f' && argv[3][1] == 0)
    if (argc == 4)
        return EXIT_SUCCESS_;

    return EXIT_USAGE_ERROR_;
}

void exitcode_processing(FILE *error_output, const int exit_code)
{
    switch (exit_code)
    {
        case EXIT_USAGE_ERROR_:
            fprintf(error_output,
                "Unexpected usage. Example:\n"
                "example.exe <input_file> <output_file> (f)\n");
            exit(EXIT_USAGE_ERROR_);
            break;
        case EXIT_OPEN_ERROR_:
            fprintf(error_output, "Could not open file:\n%s.\n",
                strerror(errno));
            exit(EXIT_OPEN_ERROR_);
            break;
        case EXIT_CLOSE_ERROR_:
            fprintf(error_output, "File closing error.\n");
            exit(EXIT_CLOSE_ERROR_);
            break;
        case EXIT_INPUT_ERROR_:
            fprintf(error_output, "Invalid input.\n");
            exit(EXIT_INPUT_ERROR_);
            break;
        case EXIT_FILE_CR_ERROR_:
            fprintf(error_output, "File reading error.\n");
            exit(EXIT_FILE_CR_ERROR_);
            break;
        case EXIT_EMPTY_ARRAY_:
            fprintf(error_output, "No elements for sorting.\n");
            exit(EXIT_EMPTY_ARRAY_);
            break;
        case EXIT_EMPTY_INPUT_:
            fprintf(error_output, "Empty input.\n");
            exit(EXIT_EMPTY_INPUT_);
            break;
        case EXIT_NULL_POINTER_REQ_:
            fprintf(error_output, "Null pointer request.\n");
            exit(EXIT_NULL_POINTER_REQ_);
            break;
    }
}
