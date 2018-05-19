#include <stdio.h>

#include "file.h"


int read_array(FILE* target, double* array, int *len)
{
    fscanf("%d", len);
    
    for (int i = 0; i < *len; i++)
    {
        fscanf("%lf", &array[i]);
    }
}