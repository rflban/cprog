#include <stdio.h>
#include <math.h>

#include "matrix.h"

int get_element(double* a, int len, int ind1, int ind2, double* number)
{
    int n = (int)(sqrt(len));
    int ind = n*ind1 + ind2;

    *number = a[ind];
    return ind;
}

int set_element(double* a, int len, int ind1, int ind2, double number)
{
    int n = (int)(sqrt(len));
    int ind = n*ind1 + ind2;

    a[ind] = number;
    return ind;
}

int find_min_saddle(double* a, int len, double* min_saddle)
{
    int n = (int)(sqrt(len));
    int flag = 0;

    for (int i = 0; i < n; i++)
    {
        double cur_num, sup_saddle;
        int j_row_min = 0;
        for (int j = 0; j < n; j++)
        {
            double min_num, cur_num;
            get_element(a, len, i, j, &cur_num);
            get_element(a, len, i, j_row_min, &min_num);
            if (cur_num < min_num)
                j_row_min = j;
        }
        int i_col_max = 0;
        for (int i_ = 0; i_ < n; i_++)
        {
            double max_num, cur_num;
            get_element(a, len, i_, j_row_min, &cur_num);
            get_element(a, len, i_col_max, j_row_min, &max_num);
            if (cur_num > max_num)
                i_col_max = i_;
        }
        get_element(a, len, i_col_max, j_row_min, &sup_saddle);
        get_element(a, len, i, j_row_min, &cur_num);
        if (cur_num == sup_saddle && (flag == 0 || cur_num < *min_saddle))
        {
            flag = 1;
            *min_saddle = cur_num;
        }
    }

    return flag;
}

void matrix_mulp(double* a, double* b, double*c, int len)
{
    int n = (int)(sqrt(len));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            double val = 0;
            for (int k = 0; k < n; k++)
            {
                double cur_a, cur_b;
                get_element(a, len, i, k, &cur_a);
                get_element(b, len, k, j, &cur_b);
                val += cur_a*cur_b;
            }
            set_element(c, len, i, j, val);
        }
    }
}

void print_matrix(double* a, int len)
{
    int n = (int)(sqrt(len));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            double number;
            get_element(a, len, i, j, &number);
            printf("%lf ", number);
        }
        printf("\n");
    }
}
