#ifndef __MATRIX_H
#define __MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include "exit.h"

#ifndef DATA_TYPE
#define DATA_TYPE int
#endif

#ifndef DATA_FORMAT
#define DATA_FORMAT "%d"
#endif

#define MATRIX DATA_TYPE**

void matrix_free(MATRIX matrix, int rows);
void matrix_print(FILE *stream, MATRIX matrix, int rows, int cols);
MATRIX matrix_read(FILE *stream, int *rows, int *cols);
MATRIX matrix_allocate(int rows, int cols);
MATRIX find_max_followers(MATRIX matrix, int rows, int cols, int *n);

#endif