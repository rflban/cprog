#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define RETURN_SUCCESS_ 0
#define RETURN_USAGE_ERROR_ -1
#define RETURN_OPEN_ERROR_ -2
#define RETURN_CLOSE_ERROR_ -3
#define RETURN_INPUT_ERROR_ -4

#define EXIT_SUCCESS_ 0
#define EXIT_INPUT_ERROR_ -1
#define EXIT_ARRAY_OVERFLOW_ 1

#define MAX_ARRAY_LEN 100

int read_array(FILE * target, int * fa, int * len);
void get_mentioned_max(int * fa, int * la, int * m_max);
void show_example(FILE* output);
void close_file(FILE* file, FILE* err_output);


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
