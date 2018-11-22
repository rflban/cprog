#include "matrix.h"

MATRIX matrix_allocate(int rows, int cols)
{
    exit_code = __EXIT_SUCCESS;

    MATRIX ptrs = (MATRIX)malloc(rows * sizeof(DATA_TYPE*));
    if (!ptrs)
    {
        exit_code = __EXIT_MEM_ERR;
        return NULL;
    }
    
    for (int i = 0; i < rows; i++)
    {
        ptrs[i] = (DATA_TYPE*)malloc(cols * sizeof(DATA_TYPE));
        if (!ptrs[i])
        {
            exit_code = __EXIT_MEM_ERR;
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
    exit_code = __EXIT_SUCCESS;

    if (stream == NULL || rows == NULL || cols == NULL)
    {
        exit_code = __EXIT_NUL_REQ;
        return NULL;
    }

    int non_zeroes;
    MATRIX matrix;
    
    if (fscanf(stream, "%d %d %d", rows, cols, &non_zeroes) != 3)
    {
        exit_code = __EXIT_INV_INP;
        return NULL;
    }

    if (*rows <= 0 || *cols <= 0 || non_zeroes < 0 || (*rows) * (*cols) < non_zeroes)
    {
        exit_code = __EXIT_INV_INP;
        return NULL;
    }
    
    matrix = matrix_allocate(*rows, *cols);
    if (matrix == NULL)
    {
        exit_code = __EXIT_MEM_ERR;
        return NULL;
    }

    for (int i = 0; i < *rows; i++)
        for (int j = 0; j < *cols; j++)
            matrix[i][j] = 0;
    
    while (non_zeroes)
    {
        int row_n;
        int col_n;
        DATA_TYPE tmp;
        
        if (fscanf(stream, "%d %d " DATA_FORMAT, &row_n, &col_n, &tmp) != 3)
        {
            exit_code = __EXIT_INV_INP;

            matrix_free(matrix, *rows);
            *rows = 0;
            *cols = 0;

            return NULL;
        }

        matrix[row_n - 1][col_n - 1] = tmp;

        non_zeroes--;
    }
    
    return matrix;
}

void matrix_print(FILE *stream, MATRIX matrix, int rows, int cols)
{
    fprintf(stream, "%d %d\n", rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (matrix[i][j] != 0)
                fprintf(stream, "%d %d " DATA_FORMAT "\n", i + 1, j + 1, matrix[i][j]);
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
            max_foll_mtrx[j++][0] = i + 1;
    
    *n = max_foll_quan;
    
    return max_foll_mtrx;
}