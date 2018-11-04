#if !defined __MY_STR_H
#define __MY_STR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "exit.h"

#if !defined ssize_t
#if defined __unix__ && __unix__
#include <unistd.h>
#endif /*unix ssize_t*/
#endif /*ssize_t*/

#define BUFFER_INIT_SIZE 120

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);
char *str_replace(const char *source, const char *search, const char *replace);
char *str_find(const char *source, const char *search);
    
#endif /*__MY_STR_H*/