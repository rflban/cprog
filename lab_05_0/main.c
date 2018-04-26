#include <stdio.h>
#include <errno.h>
#include <string.h>

#define RETURN_SUCCESS_ 0
#define RETURN_USAGE_ERROR_ -1
#define RETURN_OPEN_ERROR_ -2
#define RETURN_CLOSE_ERROR_ -2
#define RETURN_INPUT_ERROR_ -4

#define EXIT_SUCCESS_ 0
#define EXIT_INPUT_ERROR_ -1
#define EXIT_ARRAY_OVERFLOW_ 1

#define MAX_ARRAY_LEN 100

int read_array(FILE * target, int * fa, int * len);
int get_mentioned_max(int * fa, int * la, int * m_max);
void show_example(FILE * output);


int main(int argc, char ** argv)
{
    int return_code = RETURN_SUCCESS_;
    int proccess_rc;
    int numbers[MAX_ARRAY_LEN];
    int n;
    int mentioned_max;
    FILE * input;
    FILE * output = stdout;
    FILE * err_output = stderr;

    if (argc != 2)
    {
        return_code = RETURN_USAGE_ERROR_;
        show_example(err_output);
        goto END;
    }

    input = fopen(argv[1], "r");
    if (input == NULL)
    {
        return_code = RETURN_OPEN_ERROR_;
        fprintf(err_output,
                "\nError. Could not open `%s`:\n%s.\n",
                argv[1],
                strerror(errno));
        goto END;
    }

    proccess_rc = read_array(input, numbers, &n);
    if (proccess_rc == EXIT_INPUT_ERROR_)
    {
        return_code = RETURN_INPUT_ERROR_;
        fprintf(err_output,
                "\nIncorrect content of input file.\n");
        goto INPUT_FILE_CLOSING;
    }
    else if(proccess_rc == EXIT_ARRAY_OVERFLOW_)
    {
        fprintf(err_output,
                "\nArray was overflowed.\n");
    }

    get_mentioned_max(numbers, numbers + n-1, &mentioned_max);
    fprintf(output, "%d", mentioned_max);

    INPUT_FILE_CLOSING:
    proccess_rc = fclose(input);
    if (proccess_rc == EOF)
    {
        return_code = RETURN_CLOSE_ERROR_;
        fprintf(err_output,
                "\nError. Could not close `%s`:\n%s.\n",
                argv[1],
                strerror(errno));
        goto END;
    }

    END: return return_code;
}

void show_example(FILE * output)
{
    fprintf(output,
            "\n"
           "Unexpected usage. Example:\n"
           "example.exe <file_name>\n");
}

int read_array(FILE * target, int * fa, int * len)
{
    int return_code = EXIT_SUCCESS_;
    int proccess_rc;
    int * pa;

    for(pa = fa;
        (proccess_rc = fscanf(target, "%d", pa)) != EOF;
        pa++)
    {
        if (proccess_rc != 1)
        {
            return_code = EXIT_INPUT_ERROR_;
            goto END;
        }

        if (pa - fa > MAX_ARRAY_LEN)
        {
            return_code = EXIT_ARRAY_OVERFLOW_;
            *len = MAX_ARRAY_LEN;
            goto END;
        }
    }

    *len = pa - fa;

    END: return return_code;
}

int get_mentioned_max(int * fa, int * la, int * m_max)
{
    int return_code = EXIT_SUCCESS_;
    int flag = 0;

    for(int * pa1 = fa, * pa2 = la; pa2 - pa1 > 0; pa1++, pa2--)
    {
        if (!flag || (*m_max < *pa1 + *pa2))
        {
            flag = 1;
            *m_max = *pa1 + *pa2;
        }
    }

    return return_code;
}
