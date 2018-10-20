#if ! defined __MATRIX_H
#define __MATRIX_H

typedef double **matrix;

/*!
Выделяет память под матрицу размера n на m.

@param n [in]
@param m [in]

@return узказатель на указатель на первый элемент матрицы - переменную типа matrix.
*/
matrix matrix_allocate(const int n, const int m);

/*!
Считывает матрицу из потока source.

@param source [in]

@return узказатель на указатель на первый элемент считанной матрицы - переменную типа matrix.
*/
matrix read_matrix(FILE *source);

/*!
Создает копию матрицы data.

@param data [in]

@return узказатель на указатель на первый элемент копии матрицы - переменную типа matrix.
*/
matrix matrix_copy(const matrix data);

/*!
Выводит матрицу data в поток destination.

@param destination [in]
@param data [in]

@return Ничего.
*/
void write_matrix(FILE *destinaion, const matrix data);

/*!
Получает размеры матрицы data, записывая их в n и m соответственно.

@param data [in]
@param n [out]
@param m [out]

@return Ничего.
*/
void get_sizes(const matrix data, int *n, int *m);

/*!
Освобождает память, выделенную для матрицы data.

@param data [in]

@return Ничего.
*/
void matrix_free(matrix data);

/*!
Заполняет матрицу data значением value.

@param data [in]
@param value [in]

@return Ничего.
*/
void matrix_fill(matrix data, const double value);

/*!
Проверяет необходдимость освобождения памяти, занятой матрицей data.

@param data [in]const 

@return Ничего.
*/
void memory_check(matrix data);

#endif
