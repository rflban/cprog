#include "rewrite.h"

void rewrite(FILE *source, FILE *destination, const char *search, const char *replace)
{
    ssize_t read_counter = 0;

    while (!feof(source))
    {
        char *str;
        char *rewrited_str;
        size_t str_size = 1;
        ssize_t read_res;

        str = (char*)malloc(str_size);
        if (!str)
        {
            exit_code = __EXIT_MEM_ERROR;
            return;
        }

        read_res = my_getline(&str, &str_size, source);
        if (exit_code != __EXIT_SUCCESS)
        {
            free(str);
            return;
        }
        if (read_res != EOF)
            read_counter += read_res;

        rewrited_str = str_replace(str, search, replace);
        if (exit_code != __EXIT_SUCCESS)
        {
            free(str);
            return;
        }

        fprintf(destination, "%s", rewrited_str);

        free(rewrited_str);
        free(str);
    }

    if (read_counter == 0)
        exit_code = __EXIT_READ_ERROR;
}