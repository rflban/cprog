#include "myio.h"

#include <stdarg.h>
#include <stdio.h>

int my_snprintf(char *str, size_t size, const char *format, ...)
{
    if ((str == NULL) || (format == NULL))
    {
        return 0;
    }

    int pch_counter;
    va_list vl;
    const char *actual_char;

    pch_counter = 0;
    actual_char = format;

    va_start(vl, format);

    while ((*actual_char != '\0') && (pch_counter + 1 < (int)size))
    {
        printf("%%\n");
        if (*actual_char != '%')
        {
            str[pch_counter] = *actual_char;

            actual_char++;
            pch_counter++;
        }
        else
        {
            int break_loop = 0;

            actual_char++;


            if (*actual_char == 'h')
            {
                char *_str;
                short int value;

                actual_char++;

                switch (*actual_char)
                {
                    case 'd':
                    case 'i':
                        value = (short int)va_arg(vl, int);

                        if (value == 0)
                        {
                            str[pch_counter] = '0' + 0;

                            pch_counter++;
                        }
                        else
                        {
                            int cover;
                            short int temp;

                            if (value < 0)
                            {
                                value *= -1;

                                str[pch_counter] = '-';

                                pch_counter++;
                            }

                            if (!(pch_counter + 1 < (int)size))
                            {
                                break_loop = 1;
                                break;
                            }

                            temp = value;
                            cover = 1;

                            while (temp / 10 > 0)
                            {
                                cover *= 10;
                                temp /= 10;
                            }

                            while ((cover > 0) && (pch_counter + 1 < (int)size))
                            {
                                int cur_digit = value / cover;

                                str[pch_counter] = '0' + cur_digit;

                                value -= cur_digit * cover;
                                cover /= 10;

                                pch_counter++;
                            }
                        }

                        break;

                    case 's':
                        _str = va_arg(vl, char*);
                        
                        while ((*_str != '\0') && (pch_counter + 1 < (int)size))
                        {
                            str[pch_counter] = *_str;

                            _str++;
                            pch_counter++;
                        }
                        break;

                    default:
                        break;
                }
            }
            else
            {
                char *_str;
                int value;

                switch (*actual_char)
                {
                    case 'd':
                    case 'i':
                        value = (int)va_arg(vl, int);

                        if (value == 0)
                        {
                            str[pch_counter] = '0' + 0;

                            pch_counter++;
                        }
                        else
                        {
                            int cover;
                            int temp;

                            if (value < 0)
                            {
                                value *= -1;

                                str[pch_counter] = '-';

                                pch_counter++;
                            }

                            if (!(pch_counter + 1 < (int)size))
                            {
                                break_loop = 1;
                                break;
                            }

                            temp = value;
                            cover = 1;

                            while (temp / 10 > 0)
                            {
                                cover *= 10;
                                temp /= 10;
                            }

                            while ((cover > 0) && (pch_counter + 1 < (int)size))
                            {
                                int cur_digit = value / cover;

                                str[pch_counter] = '0' + cur_digit;

                                value -= cur_digit * cover;
                                cover /= 10;

                                pch_counter++;
                            }
                        }

                        break;

                    case 's':
                        _str = va_arg(vl, char*);
                        
                        while ((*_str != '\0') && (pch_counter + 1 < (int)size))
                        {
                            str[pch_counter] = *_str;

                            _str++;
                            pch_counter++;
                        }
                        break;

                    default:
                        break;
                }
            }

            if (break_loop)
            {
                break;
            }

            actual_char++;
        }
    }

    if ((*actual_char == '\0') || (pch_counter + 1 <= (int)size))
    {
        str[pch_counter] = '\0';
    }

    return pch_counter;
}
