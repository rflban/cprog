#if ! defined __MATRIX_OPERATIONS_H
#define __MATRIX_OPERATIONS_H

#include "matrix.h"

#define EPS 0.000000000001

/*!
Скалдывает матрицы a и b.

@param a [in]
@param b [in]

@return Возвращает сумму a и b.
*/
matrix matrix_addition(const matrix a, const matrix b);

/*!
Перемножает матрицу a на матрицу b.

@param a [in]
@param b [in]

@return Возвращает произведение a и b.
*/
matrix matrix_multiplication(const matrix a, const matrix b);

/*!
Вычисляет определитель матрицы a методом Гаусса.

@param a [in]

@return Возвращает определитель матрицы a.
*/
double matrix_determinant(const matrix data);

/*!
Вычисляет модуль числа number.

@param number [in]

@return Возвращает модуль числа number.
*/
double nabs(const double number);

#endif
