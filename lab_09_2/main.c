// #include <features.h>
// #define __USE_GNU
// #define __BEOS__
//#include <features.h>
#if !defined _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 200809L
#endif /*_POSIX_C_SOURCE macro for getline*/

#include <stdio.h>
#include <stdlib.h>

#include "exit.h"
#include "file.h"
#include "my_str.h"


int main(int argc, char ** argv)
{
    setbuf(stdout, NULL);

    // usage_check(argc, argv);
    // exit_process(1);

    char *lineptr = malloc(10);
    char *r = str_replace("sanya eto kruto\n", "sanya eto kruto", "T");
    printf("%s\n", r);
    free(r);
    size_t n = 0;

    // ssize_t ssz = my_getline(&lineptr, &n, stdin);
    // ssize_t ssz = getline(&lineptr, &n, stdin);
    // printf("%s\n%ld\n%ld\n", lineptr, ssz, n);

    // fgets(lineptr, 4, stdin);
    // printf("%s\n", lineptr);

    free(lineptr);

    return __EXIT_SUCCESS;
}