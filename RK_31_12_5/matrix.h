#ifndef __MATRIX_H
#define __MATRIX_H

#include <stdio.h>
#include <stdlib.h>

#define MATRIX double**
#define MATRIX_EL double
#define EL_FORMAt "%lf"

MATRIX matrix_allocate(int rows, int cols);
MATRIX matrix_read(FILE *stream, int *rows, int *cols);
void matrix_free(MATRIX matrix, int rows);
void print_matrix(FILE *stream, MATRIX matrix, int rows, int cols);

#endif