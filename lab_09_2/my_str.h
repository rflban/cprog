#if !defined __MY_STR_H
#define __MY_STR_H 1

#if !defined _STDIO_H
#include <stdio.h>
#endif /*_STDIO_H*/

#if !defined _STDLIB_H
#include <stdlib.h>
#endif /*_STDLIB_H*/

#if !defined ssize_t
#if defined __unix__ && __unix__
#include <unistd.h>
#endif /*unix ssize_t*/
#endif /*ssize_t*/

#if !defined __EXIT_H
#include "exit.h"
#endif /*__EXIT_H*/

#if !defined _STDINT_H
#include <stdint.h>
#endif /*_STDINT_H*/

#define BUFFER_INIT_SIZE 120

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);
char *str_replace(const char *source, const char *search, const char *replace);
    
#endif /*__MY_STR_H*/