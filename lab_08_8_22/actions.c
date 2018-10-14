#include <stdio.h>

#include "actions.h"
#include "matrix.h"
#include "matrix_operations.h"
#include "exit.h"
#include "ref.h"

void carry_out(FILE *outputf, const char action, const matrix a, const matrix b)
{
    switch (action)
    {
        case 'a':
            action_a(outputf, a, b);
            break;
        case 'm':
            action_m(outputf, a, b);
            break;
        case 'o':
            action_o(outputf, a);
            break;
        case 'h':
            action_h();
            break;
    }
}

void action_a(FILE *outputf, const matrix a, const matrix b)
{
    exit_code = __EXIT_SUCCESS;

    int rowsq_a;
    int colsq_a;
    int rowsq_b;
    int colsq_b;
    matrix result;

    get_sizes(a, &rowsq_a, &colsq_a);
    get_sizes(b, &rowsq_b, &colsq_b);

    if (rowsq_a != rowsq_b || colsq_a != colsq_b)
    {
        exit_code = __EXIT_MATRICES_SIZE_MISMATCH;
        return;
    }

    result = matrix_addition(a, b);
    write_matrix(outputf, result);
    matrix_free(result);
}

void action_m(FILE *outputf, const matrix a, const matrix b)
{
    exit_code = __EXIT_SUCCESS;

    int rowsq_a;
    int colsq_a;
    int rowsq_b;
    int colsq_b;
    matrix result;

    get_sizes(a, &rowsq_a, &colsq_a);
    get_sizes(b, &rowsq_b, &colsq_b);

    if (rowsq_b != colsq_a)
    {
        exit_code = __EXIT_MATRICES_SIZE_MISMATCH;
        return;
    }

    result = matrix_multiplication(a, b);
    write_matrix(outputf, result);
    matrix_free(result);
}

void action_o(FILE *outputf, const matrix a)
{
    exit_code = __EXIT_SUCCESS;

    int rowsq;
    int colsq;
    double result;

    get_sizes(a, &rowsq, &colsq);
    if (rowsq != colsq)
    {
        exit_code = __EXIT_MATRICES_SIZE_MISMATCH;
        return;
    }

    result = matrix_determinant(a);
    fprintf(outputf, "%g\n", result);
}

void action_h()
{
    exit_code = __EXIT_SUCCESS;
    show_help();
}