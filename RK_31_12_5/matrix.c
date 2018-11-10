#include "matrix.h"

MATRIX matrix_allocate(int rows, int cols)
{
    MATRIX ptrs = (MATRIX)malloc(rows * sizeof(MATRIX_EL*));
    if (!ptrs)
    {
        return NULL;
    }
    
    for (int i = 0; i < rows; i++)
    {
        ptrs[i] = (MATRIX_EL*)malloc(cols * sizeof(MATRIX_EL));
        if (!ptrs[i])
        {
            matrix_free(ptrs, i);
            return NULL;
        }
    }
    
    return ptrs;
}

void matrix_free(MATRIX matrix, int rows)
{
    for (int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);
}

MATRIX matrix_read(FILE *stream, int *rows, int *cols)
{
    MATRIX matrix;
    
    fscanf(stream, "%d %d", rows, cols);
    
    matrix = matrix_allocate(*rows, *cols);
    for (int i = 0; i < *rows; i++)
        for (int j = 0; j < *cols; j++)
            matrix[i][j] = 0;
    
    while (!feof(stream))
    {
        int row_n;
        int col_n;
        MATRIX_EL tmp;
        
        fscanf(stream, "%d %d " EL_FORMAt, &row_n, &col_n, &tmp);
        matrix[row_n - 1][col_n - 1] = tmp;
    }
    
    return matrix;
}

void print_matrix(FILE *stream, MATRIX matrix, int rows, int cols)
{
    fprintf(stream, "%d %d\n", rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (matrix[i][j] != 0)
                fprintf(stream, "%d %d " EL_FORMAt "\n", i + 1, j + 1, matrix[i][j]);
}

MATRIX find_max_followers(MATRIX matrix, int rows, int cols, int *n)
{
    int max_foll;
    int max_foll_quan;
    int people[cols];
    MATRIX max_foll_mtrx;
    
    for (int i = 0; i < rows; i++)
        people[i] = 0;

    for (int i = 0; i < rows; i++)
    {
        int cur_foll = 0;
        
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j])
                people[j]++;
        }
    }
    
    max_foll = people[0];
    for (int i = 0; i < cols; i++)
        if (max_foll < people[i])
            max_foll = people[i];
    
    max_foll_quan = 0;
    for (int i = 0; i < cols; i++)
        if (max_foll == people[i])
            max_foll_quan++;
        
    max_foll_mtrx = matrix_allocate(max_foll_quan, 1);
    for (int i = 0, j = 0; i < cols; i++)
        if (max_foll == people[i])
            max_foll_mtrx[j][0] = i + 1;
    
    *n = max_foll_quan;
    
    return max_foll_mtrx;
}