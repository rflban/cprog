#if !defined __EXIT_H
#define __EXIT_H 1

#if !defined _STDIO_H
#include <stdio.h>
#endif /*_STDIO_H*/

#if !defined _STDLIB_H
#include <stdlib.h>
#endif /*_STDLIB_H*/

#if !defined _ERRNO_H
#include <errno.h>
#endif /*_ERRNO_H*/

#if !defined _STRING_H
#include <string.h>
#endif /*_STRING_H*/

#define __EXIT(exit_code, leave) ((leave) ? exit(exit_code) : (void)0)

#define __EXIT_SUCCESS 0
#define __EXIT_FAILURE 1
#define __EXIT_IVALID_USAGE 2
#define __EXIT_FOPEN_ERROR 3
#define __EXIT_FCLOSE_ERROR 4
#define __EXIT_READ_ERROR 5
#define __EXIT_REQUEST_NULL 6
#define __EXIT_SSIZE_OVERFLOW 7
#define __EXIT_MEM_ERROR 8

extern int exit_code;

void exit_process(int leave);
void usage_check(const int argc, char **argv);

#endif /*__EXIT_H*/