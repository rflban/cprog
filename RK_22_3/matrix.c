#include <stdio.h>
#include <math.h>

#include "matrix.h"

void matrix_mulp(double* a, double* b, double*c, int len)
{
    int n = (int)(sqrt(len));
    
    for (int i = 0; i < len; i++)
    {
        int ind = (i/n) + (i%n)*n;
        c[ind] = 0;
        for (int j = 0; j < n; j++)
        {
            c[ind] += a[i%n + j] * b[ind*n + j];
        }
    }
}