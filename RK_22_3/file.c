#include <stdio.h>

#include "file.h"


int read_array(FILE* target, double* array, int *len)
{
    fscanf(target, "%d", len);
    
    for (int i = 0; i < *len; i++)
    {
        fscanf(target, "%lf", &array[i]);
    }
}