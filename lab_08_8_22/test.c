#include <stdio.h>
#include <stdlib.h>

#include "exit.h"
#include "matrix.h"
#include "matrix_operations.h"

// matrix.h
void test_matrix_h();
void test_mtrx_cpy();
void test_mtrx_fill();
void test_mtrx_szs();

// matrix_operations.h
void test_matrix_operations_h();
void test_abs_positive();
void test_abs_negative();
void test_abs_neutral();
void test_mtrx_add_neutral();
void test_mtrx_add_opposite();
void test_mtrx_add_rnd();
void test_mtrx_mltply_neutral();
void test_mtrx_mltply_opposite();
void test_mtrx_mltply_rnd();
void test_mtrx_dtrmnt_rnd1();
void test_mtrx_dtrmnt_rnd2();
void test_mtrx_dtrmnt_zero();

// help functions
void print_matrix(matrix data, int n, int m);


int main(void)
{
    setbuf(stdout, NULL);

    test_matrix_h();
    test_matrix_operations_h();

    return EXIT_SUCCESS;
}

void print_matrix(matrix data, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%g ", data[i][j]);
        printf("\n");
    }
}

void test_matrix_h()
{
    printf("\"matrix.h\"\n");
    test_mtrx_cpy();
    test_mtrx_fill();
    test_mtrx_szs();
    printf("\n");
}

void test_matrix_operations_h()
{
    printf("\"matrix_operations.h\"\n");
    test_abs_positive();
    test_abs_negative();
    test_abs_neutral();
    printf("\n");
}


void test_mtrx_cpy()
{
    int status = EXIT_SUCCESS;
    int n = 4;
    int m = 4;
    matrix received_result;
    matrix expected_result;

    printf("Test matrix_copy. ");

    expected_result = matrix_allocate(n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            expected_result[i][j] = i * m + j;

    received_result = matrix_copy(expected_result);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (received_result[i][j] != expected_result[i][j])
                status = EXIT_FAILURE;

    if (status == EXIT_SUCCESS)
        printf("Success.\n");
    else
    {
        printf("Failure:\n");
        printf("Initial sizes (rows quantity, columns quantity): %d, %d\n", n, m);
        printf("Initial matrix:\n");
        print_matrix(expected_result, n, m);
        printf("Received matrix:\n");
        print_matrix(received_result, n, m);
        printf("Expected matrix:\n");
        print_matrix(expected_result, n, m);
    }
    
    matrix_free(received_result);
    matrix_free(expected_result);
}

void test_mtrx_fill()
{
    int status = EXIT_SUCCESS;
    int n = 4;
    int m = 4;
    double fill_value = 3;
    matrix received_result;
    matrix expected_result;

    printf("Test matrix_fill. ");

    expected_result = matrix_allocate(n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            expected_result[i][j] = fill_value;

    received_result = matrix_allocate(n, m);
    matrix_fill(received_result, fill_value);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (received_result[i][j] != expected_result[i][j])
                status = EXIT_FAILURE;

    if (status == EXIT_SUCCESS)
        printf("Success.\n");
    else
    {
        printf("Failure:\n");
        printf("Initial sizes (rows quantity, columns quantity): %d, %d\n", n, m);
        printf("Fill value: %g\n", fill_value);
        printf("Received matrix:\n");
        print_matrix(received_result, n, m);
        printf("Expected matrix:\n");
        print_matrix(expected_result, n, m);
    }

    matrix_free(received_result);
    matrix_free(expected_result);
}

void test_mtrx_szs()
{
    int status = EXIT_SUCCESS;
    int expected_result[2] = {4, 4};
    int received_result[2];
    matrix data;

    printf("Test get_sizes. ");

    data = matrix_allocate(expected_result[0], expected_result[1]);
    get_sizes(data, received_result, received_result + 1);

    if (!(expected_result[0] == received_result[0] && expected_result[1] == received_result[1]))
        status = EXIT_FAILURE;

    if (status == EXIT_SUCCESS)
        printf("Success.\n");
    else
    {
        printf("Failure:\n");
        printf("Initial sizes: %d %d\n", expected_result[0], expected_result[1]);
        printf("Received sizes: %d %d\n", received_result[0], received_result[1]);
        printf("Expected sizes: %d %d\n", expected_result[0], expected_result[1]);
    }

    matrix_free(data);
}

void test_abs_positive()
{
    int status = EXIT_SUCCESS;
    double initial = 23;
    double expected_result = 23;
    double received_result;

    printf("Test nabs. Positive. ");

    received_result = nabs(initial);
    if (received_result != expected_result)
        status = EXIT_FAILURE;

    if (status == EXIT_SUCCESS)
        printf("Success.\n");
    else
    {
        printf("Failure:\n");
        printf("Initial value: %g\n", initial);
        printf("Received value: %g\n", received_result);
        printf("Expected value: %g\n", expected_result);
    }
}

void test_abs_negative()
{
    int status = EXIT_SUCCESS;
    double initial = -34;
    double expected_result = 34;
    double received_result;

    printf("Test nabs. Negative. ");

    received_result = nabs(initial);
    if (received_result != expected_result)
        status = EXIT_FAILURE;

    if (status == EXIT_SUCCESS)
        printf("Success.\n");
    else
    {
        printf("Failure:\n");
        printf("Initial value: %g\n", initial);
        printf("Received value: %g\n", received_result);
        printf("Expected value: %g\n", expected_result);
    }
}

void test_abs_neutral()
{
    int status = EXIT_SUCCESS;
    double initial = 0;
    double expected_result = 0;
    double received_result;

    printf("Test nabs. Neutral. ");

    received_result = nabs(initial);
    if (received_result != expected_result)
        status = EXIT_FAILURE;

    if (status == EXIT_SUCCESS)
        printf("Success.\n");
    else
    {
        printf("Failure:\n");
        printf("Initial value: %g\n", initial);
        printf("Received value: %g\n", received_result);
        printf("Expected value: %g\n", expected_result);
    }
}