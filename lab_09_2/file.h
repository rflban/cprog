#if !defined __FILE_H
#define __FILE_H

#include <stdio.h>

#include "exit.h"

FILE *openf(const char *const name, const char *const mode);
void closef(FILE *file);

#endif /*__FILE_H*/