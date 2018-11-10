#ifndef __MATRIX_H
#define __MATRIX_H

#include <stdio.h>
#include <stdlib.h>

#define MATRIX int**
#define MATRIX_EL int
#define EL_FORMAt "%d"

MATRIX matrix_allocate(int rows, int cols);
MATRIX matrix_read(FILE *stream, int *rows, int *cols);
MATRIX find_max_followers(MATRIX matrix, int rows, int cols, int *n);
void matrix_free(MATRIX matrix, int rows);
void print_matrix(FILE *stream, MATRIX matrix, int rows, int cols);

#endif