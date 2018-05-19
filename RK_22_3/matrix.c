#include <stdio.h>
#include <math.h>

#include "matrix.h"

void matrix_mulp(double* a, double* b, double*c, int len)
{
    int n = (int)(sqrt(len));
    
    for (int i = 0; i < len; i++)
    {
        int ind = (i/n)*n + (i%n);
        c[ind] = 0;
        printf("%d", ind);
        for (int j = 0; j < n; j++)
        {
            c[ind] += a[ind*n + j] * b[ind + j*n];
        }
    }
}