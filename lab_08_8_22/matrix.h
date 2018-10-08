#if ! defined __MATRIX_H
#define __MATRIX_H

double** matrix_allocate(int n, int m);
void matrix_free(double **data, int n);
double** matrix_sum(double **matrix1, double **matrix2, int n, int m);
double** matrix_multiply(double **matrix1, double **matrix2, int n, int m, int r);
double matrix_determinant(double **matrix, int n, int m);

#endif
