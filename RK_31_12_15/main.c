#include <stdio.h>

#include "matrix.h"

int main(int argc, char** argv)
{
    int n;
    int rows, cols;
    FILE *inputf;
    MATRIX matrix;
    MATRIX res;
    
    inputf = fopen(argv[1], "r");
    
    matrix = matrix_read(inputf, &rows, &cols);
    
    res = find_max_followers(matrix, rows, cols, &n);
    
    print_matrix(stdout, res, n, 1);
    
    return 0;
}