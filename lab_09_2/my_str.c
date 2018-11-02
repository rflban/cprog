#include "my_str.h"

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
    if (lineptr == NULL || n == NULL || stream == NULL)
    {
        exit_code = __EXIT_REQUEST_NULL;
        return EOF;
    }

    if (*n > SIZE_MAX / 2)
    {
        exit_code = __EXIT_SSIZE_OVERFLOW;
        return EOF;
    }

    char *buffer;
    char read_ending = '\0';
    size_t buf_size = BUFFER_INIT_SIZE;
    ssize_t read_counter = 0;

    buffer = (char*)malloc(buf_size);
    if (!buffer)
    {
        exit_code = __EXIT_MEM_ERROR;
        return EOF;
    }

    while (read_ending != '\n' && buffer != NULL)
    {
        char *temp = buffer;
        ssize_t zero_ind = 0;

        buffer = fgets(buffer, buf_size, stream);

        if (buffer)
        {
            while (buffer[zero_ind] != '\0')
                zero_ind++;

            if (read_counter + zero_ind + 1> *n)
            {
                *n = read_counter + zero_ind + 1;

                *lineptr = (char*)realloc(*lineptr, *n);
                if (!(*lineptr))
                {
                    exit_code = __EXIT_MEM_ERROR;
                    free(buffer);
                    return EOF;
                }
            }

            for (ssize_t i; i < zero_ind; i++)
                (*lineptr)[read_counter + i] = buffer[i];

            read_counter += zero_ind;
            read_ending = buffer[zero_ind - 1];
        }
        else
            free(temp);
    }
    (*lineptr)[read_counter] = '\0';

    free(buffer);

    if (read_counter == 0)
    {
        exit_code = __EXIT_READ_ERROR;
        return EOF;
    }

    *lineptr = (char*)realloc(*lineptr, (read_counter + 1) * sizeof(char));
    if (!(*lineptr))
    {
        exit_code = __EXIT_MEM_ERROR;
        return EOF;
    }

    return read_counter;
}

char *str_replace(const char *source, const char *search, const char *replace)
{
    return "&";
}