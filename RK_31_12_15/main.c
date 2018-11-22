#include <stdio.h>

#include "exit.h"
#include "matrix.h"

int main(int argc, char** argv)
{
    int n;
    int rows;
    int cols;
    FILE *inputf;
    MATRIX matrix;
    MATRIX res;

    if (argc != 2)
    {
        fprintf(stderr, "Incorrect usage. Example:\n./rk31.exe <input file>\n");
        return __EXIT_INV_INP;
    }
    
    inputf = fopen(argv[1], "r");
    if (inputf == NULL)
    {
        fprintf(stderr, "Incorrect file.\n");
        return __EXIT_INV_INP;
    }
    
    matrix = matrix_read(inputf, &rows, &cols);
    exit_proccess();
    
    res = find_max_followers(matrix, rows, cols, &n);
    
    matrix_print(stdout, res, n, 1);

    fclose(inputf);
    matrix_free(res, n);
    matrix_free(matrix, rows);
    
    return 0;
}