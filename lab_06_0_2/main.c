#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "l_file_control.h"
#include "l_exit_control.h"
#include "l_array_process.h"


int main(int argc, char ** argv)
{
    int proccess_rc;
    int numbers[MAX_ARRAY_LEN];
    int n;
    int mentioned_max;
    FILE * input;
    FILE * output = stdout;
    FILE * err_output = stderr;

    if (argc != 2)
    {
        show_example(err_output);
        return RETURN_USAGE_ERROR_;
    }

    input = fopen(argv[1], "r");
    if (input == NULL)
    {
        fprintf(err_output,
                "\nError. Could not open `%s`:\n%s.\n",
                argv[1],
                strerror(errno));
        return RETURN_OPEN_ERROR_;
    }

    proccess_rc = read_array(input, numbers, &n);
    if (proccess_rc == EXIT_INPUT_ERROR_)
    {
        fprintf(err_output,
                "\nIncorrect content of input file.\n");
        close_file(input, err_output);
    }
    else if(proccess_rc == EXIT_ARRAY_OVERFLOW_)
    {
        fprintf(err_output,
                "\nArray was overflowed.\n");
    }

    get_mentioned_max(numbers, numbers + n-1, &mentioned_max);
    fprintf(output, "%d", mentioned_max);

    close_file(input, err_output);

    return RETURN_SUCCESS_;
}
