#include "rewrite.h"

void rewrite(FILE *source, FILE *destination, const char *search, const char *replace)
{
    while (!feof(source))
    {
        char *str;
        char *rewrited_str;
        size_t str_size = 1;

        str = (char*)malloc(str_size);
        if (!str)
        {
            exit_code = __EXIT_MEM_ERROR;
            return;
        }

        my_getline(&str, &str_size, source);
        if (exit_code != __EXIT_SUCCESS)
        {
            free(str);
            return;
        }

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
}