#include <stdio.h>

#include "matrix.h"

int main(int argc, char** argv)
{
    int rows, cols;
    FILE *inputf;
    MATRIX matrix;
    
    inputf = fopen(argv[1], "r");
    
    matrix = matrix_read(inputf, &rows, &cols);
    
    print_matrix(stdout, matrix, rows, cols);
    
    return 0;
}