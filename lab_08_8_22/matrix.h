#if ! defined __MATRIX_H
#define __MATRIX_H

typedef double** matrix;

matrix matrix_allocate(int n, int m);
void matrix_free(matrix data);
matrix read_matrix(FILE *source);
void memory_check(matrix one);

#endif
