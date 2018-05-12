#include <stdio.h>

#define RETURN_SUCCESS_ 0
#define RETURN_USAGE_ERROR_ -1
#define RETURN_OPEN_ERROR_ -2
#define RETURN_CLOSE_ERROR_ -3
#define RETURN_INPUT_ERROR_ -4

#define EXIT_SUCCESS_ 0
#define EXIT_INPUT_ERROR_ -1
#define EXIT_ARRAY_OVERFLOW_ 1


void show_example(FILE * output)
{
    fprintf(output,
            "\n"
           "Unexpected usage. Example:\n"
           "example.exe <file_name>\n");
}
