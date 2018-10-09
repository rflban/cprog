#if ! defined __MATRIX_OPERATIONS_H
#define __MATRIX_OPERATIONS_H

matrix matrix_addition(double **matrix1, double **matrix2, int n, int m);
matrix matrix_multiplication(double **matrix1, double **matrix2, int n, int m, int r);
double matrix_determinant(double **matrix, int n, int m);

#endif
