#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "exit_control.h"

int usage_check(int argc, char** argv)
{
    if (argc == 3)
        return EXIT_SUCCESS_;
    if (argc == 4 && argv[3][0] == 'f' && argv[3][1] == 0)
        return EXIT_SUCCESS_;

    return EXIT_USAGE_ERROR_;
}

void exitcode_processing(FILE* error_output, const int exit_code)
{
    switch (exit_code)
    {
        case EXIT_USAGE_ERROR_:
            fprintf(error_output, \
                    "Unexpected usage. Example:\n"\
                    "example.exe <input_file> <output_file> (f)\n");
            exit(EXIT_USAGE_ERROR_);
            break;
    }
}
