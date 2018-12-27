#include "myio.h"

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#define INIT_BUF_SIZE 120

int update_container(char *container, int *capacity, int len);

int my_snprintf(char *str, size_t size, const char *format, ...)
{
    // if ((str == NULL && size != 0) || (format == NULL))
    if (format == NULL)
    {
        return 0;
    }

    va_list vl;

    int rc;
    int buf_size;
    int pch_counter;
    char *buffer;
    const char *actual_char;

    buf_size = INIT_BUF_SIZE;
    buffer = (char*)malloc(sizeof(char) * buf_size);

    if (buffer == NULL)
    {
        return EOF;
    }

    pch_counter = 0;
    actual_char = format;

    va_start(vl, format);

    while (*actual_char != '\0')
    {
        if (*actual_char != '%')
        {
            rc = update_container(buffer, &buf_size, pch_counter);

            if (rc != 0)
            {
                return EOF;
            }

            buffer[pch_counter] = *actual_char;

            actual_char++;
            pch_counter++;
        }
        else
        {
            actual_char++;

            if (*actual_char == 'h')
            {
                char *str_value;
                short int value;

                actual_char++;

                switch (*actual_char)
                {
                    case 'd':
                    case 'i':
                        value = (short int)va_arg(vl, int);

                        if (value == 0)
                        {
                            rc = update_container(buffer, &buf_size, pch_counter);

                            if (rc != 0)
                            {
                                return EOF;
                            }
                            
                            buffer[pch_counter] = '0' + 0;

                            pch_counter++;
                        }
                        else
                        {
                            int cover;
                            short int temp;

                            if (value < 0)
                            {
                                rc = update_container(buffer, &buf_size, pch_counter);

                                if (rc != 0)
                                {
                                    return EOF;
                                }

                                value *= -1;

                                buffer[pch_counter] = '-';

                                pch_counter++;
                            }

                            temp = value;
                            cover = 1;

                            while (temp / 10 > 0)
                            {
                                cover *= 10;
                                temp /= 10;
                            }

                            while (cover > 0)
                            {
                                rc = update_container(buffer, &buf_size, pch_counter);

                                if (rc != 0)
                                {
                                    return EOF;
                                }

                                int cur_digit = value / cover;

                                buffer[pch_counter] = '0' + cur_digit;

                                value -= cur_digit * cover;
                                cover /= 10;

                                pch_counter++;
                            }
                        }
                        break;
                    case 's':
                        str_value = va_arg(vl, char*);
                        
                        while (*str_value != '\0')
                        {
                            rc = update_container(buffer, &buf_size, pch_counter);

                            if (rc != 0)
                            {
                                return EOF;
                            }

                            buffer[pch_counter] = *str_value;

                            str_value++;
                            pch_counter++;
                        }
                        break;
                    default:
                        break;
                }
            }
            else
            {
                char *str_value;
                int value;

                switch (*actual_char)
                {
                    case 'd':
                    case 'i':
                        value = (int)va_arg(vl, int);

                        if (value == 0)
                        {
                            rc = update_container(buffer, &buf_size, pch_counter);

                            if (rc != 0)
                            {
                                return EOF;
                            }
                            
                            buffer[pch_counter] = '0' + 0;

                            pch_counter++;
                        }
                        else
                        {
                            int cover;
                            int temp;

                            if (value < 0)
                            {
                                rc = update_container(buffer, &buf_size, pch_counter);

                                if (rc != 0)
                                {
                                    return EOF;
                                }

                                value *= -1;

                                buffer[pch_counter] = '-';

                                pch_counter++;
                            }

                            temp = value;
                            cover = 1;

                            while (temp / 10 > 0)
                            {
                                cover *= 10;
                                temp /= 10;
                            }

                            while (cover > 0)
                            {
                                rc = update_container(buffer, &buf_size, pch_counter);

                                if (rc != 0)
                                {
                                    return EOF;
                                }

                                int cur_digit = value / cover;

                                buffer[pch_counter] = '0' + cur_digit;

                                value -= cur_digit * cover;
                                cover /= 10;

                                pch_counter++;
                            }
                        }
                        break;
                    case 's':
                        str_value = va_arg(vl, char*);
                        
                        while (*str_value != '\0')
                        {
                            rc = update_container(buffer, &buf_size, pch_counter);

                            if (rc != 0)
                            {
                                return EOF;
                            }

                            buffer[pch_counter] = *str_value;

                            str_value++;
                            pch_counter++;
                        }
                        break;
                    default:
                        break;
                }
            }

            actual_char++;
        }
    }

    va_end(vl);

    if (pch_counter + 1 <= (int)size)
    {
        for (int i = 0; i < pch_counter; i++)
        {
            str[i] = buffer[i];
        }

        str[pch_counter] = '\0';
    }
    
    free(buffer);

    return pch_counter;
}

int update_container(char *container, int *capacity, int len)
{
    if (len >= *capacity)
    {
        *capacity *= 2;
        container = (char*)realloc(container, *capacity);

        if (container == NULL)
        {
            return EOF;
        }
    }

    return 0;
}
