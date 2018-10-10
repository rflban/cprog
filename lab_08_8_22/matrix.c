#include <stdio.h>
#include <stdlib.h>

#include "exit.h"
#include "matrix.h"

matrix matrix_allocate(int n, int m)
{
    exit_code = __EXIT_SUCCESS;

    int *space;
    matrix data;

    space = malloc(2 * sizeof(int) + n * sizeof(double*));
    if (space == NULL)
    {
        exit_code = __EXIT_ALLOC_ERROR;
        return NULL;
    }

    space += 2;
    *(space - 1) = n;
    *(space - 2) = m;

    data = (matrix)((void*)(space));
    for (int i = 0; i < n; i++)
    {
        data[i] = malloc(m * sizeof(double));
        if (data[i] == NULL)
        {
            exit_code = __EXIT_ALLOC_ERROR;
            matrix_free(data);
            return NULL;
        }
    }

    return data;
}

void matrix_free(matrix data)
{
    if (data == NULL)
        return;

    int n = *((int*)data - 1);
    for (int i = 0; i < n; i++)
        free(data[i]);
    free(data);
}

void get_sizes(matrix data, int *n, int *m)
{
    *n = *((int*)data - 1);
    *m = *((int*)data - 2);
}

void matrix_fill(matrix data, double value)
{
    int rowsq;
    int colsq;

    get_sizes(data, &rowsq, &colsq);
    for (int i = 0; i < rowsq; i++)
        for (int j = 0; j < colsq; j++)
            data[i][j] = value;
}

matrix read_matrix(FILE *source)
{
    exit_code = __EXIT_SUCCESS;

    matrix data;
    int rowsq;
    int colsq;
    int nonzeroesq;
    int rc;

    rc = fscanf(source, "%d%d%d", &rowsq, &colsq, &nonzeroesq);
    if (rc != 3)
    {
        exit_code = __EXIT_INVALID_INPUT;
        return NULL;
    }

    if (rowsq <= 0 || colsq <= 0 || nonzeroesq < 0)
    {
        exit_code = __EXIT_INVALID_INPUT;
        return NULL;
    }

    data = matrix_allocate(rowsq, colsq);
    if (exit_code != __EXIT_SUCCESS)
    {
        exit_code = __EXIT_ALLOC_ERROR;
        return NULL;
    }
    matrix_fill(data, 0);

    for (int i = 0; i < nonzeroesq; i++)
    {
        int rown;
        int coln;
        double value;

        rc = fscanf(source, "%d%d%lf", &rown, &coln, &value);
        if (rc != 3)
        {
            exit_code = __EXIT_INVALID_INPUT;
            matrix_free(data);
            return NULL;
        }

        if (rown <= 0 || coln <= 0)
        {
            exit_code = __EXIT_INVALID_DATA;
            matrix_free(data);
            return NULL;
        }

        data[rown - 1][coln - 1] = value;
    }

    {
        int tmp;

        if (fscanf(source, "%d", &tmp) != EOF)
        {
            exit_code = __EXIT_INVALID_INPUT;
            matrix_free(data);
            return NULL;
        }
    }

    return data;
}

void write_matrix(FILE *destinaion, matrix data)
{
    int rowsq;
    int colsq;
    int nonzeroesq;

    get_sizes(data, &rowsq, &colsq);

    nonzeroesq = 0;
    for (int i = 0; i < rowsq; i++)
        for (int j = 0; j < colsq; j++)
            if (data[i][j] != 0)
                nonzeroesq++;

    fprintf(destinaion, "%d %d %d\n", rowsq, colsq, nonzeroesq);

    for (int i = 0; i < rowsq; i++)
        for (int j = 0; j < colsq; j++)
            if (data[i][j] != 0)
                fprintf(destinaion, "%d %d %lf\n", i + 1, j + 1, data[i][j]);
}

    void memory_check(matrix data)
{
    if (exit_code != __EXIT_SUCCESS)
        matrix_free(data);
}
