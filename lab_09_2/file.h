#if !defined __FILE_H
#define __FILE_H

#if !defined __EXIT_H
#include "exit.h"
#endif /*__EXIT_H*/

#if !defined FILE
//#include <bits/types/FILE.h>
#include <stdio.h>
#endif /*FILE*/

FILE *openf(const char *const name, const char *const mode);
void closef(FILE *file);

#endif /*__FILE_H*/