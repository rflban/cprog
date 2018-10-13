#if ! defined __MATRIX_OPERATIONS_H
#define __MATRIX_OPERATIONS_H

#include "matrix.h"

#define EPS 0.000000000001

matrix matrix_addition(matrix a, matrix b);
matrix matrix_multiplication(matrix a, matrix b);
double matrix_determinant(matrix data);
double nabs(double number);

#endif
