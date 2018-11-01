#if !defined __FILE_H
#define __FILE_H 1

#if !defined __EXIT_H
#include "exit.h"
#endif /*__EXIT_H*/

#if !defined _STDIO_H
#include <stdio.h>
#endif /*_STDIO_H*/

FILE *openf(const char *const name, const char *const mode);
void closef(FILE *file);

#endif /*__FILE_H*/