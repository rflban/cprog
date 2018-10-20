#if ! defined __ACTIONS_H
#define __ACTIONS_H

#include "matrix.h"

/*!
Выполнение команды сложения матриц a и b с выводом в поток outputf.

@param outputf [in]
@param a [in]
@param b [in]

@return Ничего.
*/
void action_a(FILE *outputf, const matrix a, const matrix b);

/*!
Выполнение команды произведения матриц a и b с выводом в поток outputf.

@param outputf [in]
@param a [in]
@param b [in]

@return Ничего.
*/
void action_m(FILE *outputf, const matrix a, const matrix b);

/*!
Выполнение команды вычисления определителя
матрицы a с выводом в поток outputf.

@param outputf [in]
@param a [in]

@return Ничего.
*/
void action_o(FILE *outputf, const matrix a);

/*!
Вывод справки в stderr.

@return Ничего.
*/
void action_h();

/*!
Выполнение команды action с матрицами a и b. Вывод в поток outputf.

@param outputf [in]
@param action [in]
@param a [in]
@param b [in]

@return Ничего.
*/
void carry_out(FILE *outputf, const char action, const matrix a, const matrix b);

#endif
