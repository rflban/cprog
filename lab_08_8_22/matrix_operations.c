#include <stdio.h>

#include "matrix.h"
#include "matrix_operations.h"
#include "exit.h"

static void swap_rows(matrix data, const int rown1, const int rown2)
{
    int rowsq;
    int colsq;

    get_sizes(data, &rowsq, &colsq);
    if (rown1 > rowsq - 1 || rown2 >= rowsq - 1)
        return;

    for (int j = 0; j < colsq; j++)
    {
        double buff = data[rown1][j];
        data[rown1][j] = data[rown2][j];
        data[rown2][j] = buff;
    }
}

static void swap_cols(matrix data, const int coln1, const int coln2)
{
    int rowsq;
    int colsq;

    get_sizes(data, &rowsq, &colsq);
    if (coln1 > colsq - 1 || coln2 >= colsq - 1)
        return;

    for (int i = 0; i < rowsq; i++)
    {
        double buff = data[i][coln1];
        data[i][coln1] = data[i][coln2];
        data[i][coln2] = buff;
    }
}

matrix matrix_addition(const matrix a, const matrix b)
{
    exit_code = 1;

    int rowsq;
    int colsq;
    matrix result;

    get_sizes(a, &rowsq, &colsq);
    result = matrix_allocate(rowsq, colsq);
    if (exit_code != __EXIT_SUCCESS)
    {
        exit_code = __EXIT_ALLOC_ERROR;
        return NULL;
    }

    for (int i = 0; i < rowsq; i++)
        for (int j = 0; j < colsq; j++)
            result[i][j] = a[i][j] + b[i][j];

    return result;
}

matrix matrix_multiplication(const matrix a, const matrix b)
{
    exit_code = 1;

    int rowsq;
    int colsq;
    int r;
    matrix result;

    get_sizes(a, &rowsq, &r);
    get_sizes(b, &r, &colsq);
    result = matrix_allocate(rowsq, colsq);
    if (exit_code != __EXIT_SUCCESS)
    {
        exit_code = __EXIT_ALLOC_ERROR;
        return NULL;
    }

    matrix_fill(result, 0);
    for (int i = 0; i < rowsq; i++)
        for (int j = 0; j < colsq; j++)
            for (int k = 0; k < r; k++)
                result[i][j] += a[i][k] * b[k][j];
    
    return result;
}

double matrix_determinant(const matrix data)
{
    exit_code = 1;

    int rowsq;
    int colsq;
    double determinant = 1;
    matrix temp;

    get_sizes(data, &rowsq, &colsq);

    temp = matrix_copy(data);
    for (int i = 0; i < rowsq; i++)
    {
        if (nabs(temp[i][i]) < EPS)
        {
            int cur_ind;

            cur_ind = i;
            while (cur_ind < rowsq && temp[cur_ind][i] < EPS)
                cur_ind++;

            if (cur_ind >= rowsq)
            {
                cur_ind = i;
                while (cur_ind < colsq && temp[i][cur_ind] < EPS)
                    cur_ind++;

                if (cur_ind < colsq)
                {
                    swap_cols(temp, cur_ind, i);
                    determinant *= -1;
                }
            }
            else
            {
                swap_rows(temp, cur_ind, i);
                determinant *= -1;
            }
        }

        for (int j = i + 1; j < rowsq; j++)
        {
            double koef; // 0 = temp[j][i] + koef * temp[i][i]

            if (temp[i][i] < EPS)
                continue;

            koef = -temp[j][i] / temp[i][i];
            for (int k = i + 1; k < colsq; k++)
                temp[j][k] += koef * temp[i][k];
        }
    }

    for (int i = 0; i < rowsq; i++)
        determinant *= temp[i][i];
    matrix_free(temp);

    return determinant;
}

double nabs(const double number)
{
    if (number < 0)
        return -number;
    return number;
}