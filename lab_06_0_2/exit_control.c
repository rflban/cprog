#include <stdio.h>

#include "exit_control.h"


void show_example(FILE * output)
{
    fprintf(output,
            "\n"
           "Unexpected usage. Example:\n"
           "example.exe <file_name>\n");
}
