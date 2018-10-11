#if ! defined __MATRIX_H
#define __MATRIX_H

typedef double **matrix;

matrix matrix_allocate(int n, int m);
matrix read_matrix(FILE *source);
matrix matrix_copy(matrix data);
void write_matrix(FILE *destinaion, matrix data);
void get_sizes(matrix data, int *n, int *m);
void matrix_free(matrix data);
void matrix_fill(matrix data, double value);
void memory_check(matrix data);

#endif
