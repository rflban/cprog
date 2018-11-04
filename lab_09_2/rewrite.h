#if !defined __REWRITE_H
#define __REWRITE_H

#include "exit.h"
#include "my_str.h"

void rewrite(FILE *source, FILE *destination, const char *search, const char *replace);

#endif /*__REWRITE_H*/