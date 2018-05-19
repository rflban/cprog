/*
Набиев Фарис. ИУ7-23Б. Вариант 3.
Задан два одномерных массива a и b, 
в которых находятся элементы двумерного массива.
Они расположены в следующем порядке (пример для матрицы 3x3):
a= [ a11, a12, a13, a21, a22, a23,…, a33 ] и
b= [ b11, b12, b13, b21, b22, b23,…, b33 ].
Не используя двумерные массивы определите a*b.
Итоговый результат вывести в формате входных данных.

Матрицы квадратные.
*/

#include <stdio.h>

#include "exit_codes.h"
#include "exit_codes.h"
#include "matrix.h"

int main(int argc, char** argv)
{
    int rc;
    double a[MAX_SIDE_LEN];
    int a_len;
    double b[MAX_SIDE_LEN];
    int b_len;
    double c[MAX_SIDE_LEN];
    int c_len;
    FILE* input;
    
    input = fopen(argv[1], "r");
    rc = read_array(input, a, &a_len);
    fclose(input);
    for (int i = 0; i < a_len; i++)
        printf("%lf ", a[i]);
    printf("\n");
    
    input = fopen(argv[2], "r");
    rc = read_array(input, b, &b_len);
    fclose(input);
    
    matrix_mulp(a, b, c);
    c_len = a_len;
    
    printf("%d", c_len);
    for (int i = 0; i < c_len; i++)
        printf("%lf ", c[i]);
    printf("\n");
    
    return SUCCESS;
}