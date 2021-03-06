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
            printf("%5g ", data[i][j]);
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
    test_mtrx_add_neutral();
    test_mtrx_add_opposite();
    test_mtrx_add_rnd();
    test_mtrx_mltply_neutral();
    test_mtrx_mltply_opposite();
    test_mtrx_mltply_rnd();
    test_mtrx_dtrmnt_rnd1();
    test_mtrx_dtrmnt_rnd2();
    test_mtrx_dtrmnt_zero();
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
    int expected_result[2] = { 4, 4 };
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

void test_mtrx_add_neutral()
{
    int status = EXIT_SUCCESS;
    int n = 4;
    int m = 5;
    double s1_src[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
    double s2_src[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    double exp_src[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
    matrix summand1;
    matrix summand2;
    matrix expected_result;
    matrix received_result;

    printf("Test matrix_addition. Neutral second summand. ");

    summand1 = matrix_allocate(n, m);
    summand2 = matrix_allocate(n, m);
    expected_result = matrix_allocate(n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            summand1[i][j] = s1_src[i * m + j];
            summand2[i][j] = s2_src[i * m + j];
            expected_result[i][j] = exp_src[i * m + j];
        }
    
    received_result = matrix_addition(summand1, summand2);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (received_result[i][j] != expected_result[i][j])
                status = EXIT_FAILURE;

    if (status == EXIT_SUCCESS)
        printf("Success.\n");
    else
    {
        printf("Failure:\n");
        printf("Summand 1:\n");
        print_matrix(summand1, n, m);
        printf("Summand 2:\n");
        print_matrix(summand2, n, m);
        printf("Received result:\n");
        print_matrix(received_result, n, m);
        printf("Expected result:\n");
        print_matrix(expected_result, n, m);
    }

    matrix_free(summand1);
    matrix_free(summand2);
    matrix_free(expected_result);
    matrix_free(received_result);
}

void test_mtrx_add_opposite()
{
    int status = EXIT_SUCCESS;
    int n = 4;
    int m = 5;
    double s1_src[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
    double s2_src[] = { 0, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12, -13, -14, -15, -16, -17, -18, -19 };
    double exp_src[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    matrix summand1;
    matrix summand2;
    matrix expected_result;
    matrix received_result;

    printf("Test matrix_addition. Opposite second summand. ");

    summand1 = matrix_allocate(n, m);
    summand2 = matrix_allocate(n, m);
    expected_result = matrix_allocate(n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            summand1[i][j] = s1_src[i * m + j];
            summand2[i][j] = s2_src[i * m + j];
            expected_result[i][j] = exp_src[i * m + j];
        }

    received_result = matrix_addition(summand1, summand2);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (received_result[i][j] != expected_result[i][j])
                status = EXIT_FAILURE;

    if (status == EXIT_SUCCESS)
        printf("Success.\n");
    else
    {
        printf("Failure:\n");
        printf("Summand 1:\n");
        print_matrix(summand1, n, m);
        printf("Summand 2:\n");
        print_matrix(summand2, n, m);
        printf("Received result:\n");
        print_matrix(received_result, n, m);
        printf("Expected result:\n");
        print_matrix(expected_result, n, m);
    }

    matrix_free(summand1);
    matrix_free(summand2);
    matrix_free(expected_result);
    matrix_free(received_result);
}

void test_mtrx_add_rnd()
{
    int status = EXIT_SUCCESS;
    int n = 4;
    int m = 5;
    double s1_src[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
    double s2_src[] = { 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    double exp_src[] = { 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19 };
    matrix summand1;
    matrix summand2;
    matrix expected_result;
    matrix received_result;

    printf("Test matrix_addition. Case of random summands. ");

    summand1 = matrix_allocate(n, m);
    summand2 = matrix_allocate(n, m);
    expected_result = matrix_allocate(n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            summand1[i][j] = s1_src[i * m + j];
            summand2[i][j] = s2_src[i * m + j];
            expected_result[i][j] = exp_src[i * m + j];
        }

    received_result = matrix_addition(summand1, summand2);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (received_result[i][j] != expected_result[i][j])
                status = EXIT_FAILURE;

    if (status == EXIT_SUCCESS)
        printf("Success.\n");
    else
    {
        printf("Failure:\n");
        printf("Summand 1:\n");
        print_matrix(summand1, n, m);
        printf("Summand 2:\n");
        print_matrix(summand2, n, m);
        printf("Received result:\n");
        print_matrix(received_result, n, m);
        printf("Expected result:\n");
        print_matrix(expected_result, n, m);
    }

    matrix_free(summand1);
    matrix_free(summand2);
    matrix_free(expected_result);
    matrix_free(received_result);
}

void test_mtrx_mltply_neutral()
{
    int status = EXIT_SUCCESS;
    int n = 4;
    int m = 4;
    double s1_src[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
    double s2_src[] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };
    double exp_src[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
    matrix multiplier1;
    matrix multiplier2;
    matrix expected_result;
    matrix received_result;

    printf("Test matrix_multiplication. Neutral second multiplier. ");

    multiplier1 = matrix_allocate(n, m);
    multiplier2 = matrix_allocate(n, m);
    expected_result = matrix_allocate(n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            multiplier1[i][j] = s1_src[i * m + j];
            multiplier2[i][j] = s2_src[i * m + j];
            expected_result[i][j] = exp_src[i * m + j];
        }

    received_result = matrix_multiplication(multiplier1, multiplier2);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (received_result[i][j] != expected_result[i][j])
                status = EXIT_FAILURE;

    if (status == EXIT_SUCCESS)
        printf("Success.\n");
    else
    {
        printf("Failure:\n");
        printf("Multiplier 1:\n");
        print_matrix(multiplier1, n, m);
        printf("Multiplier 2:\n");
        print_matrix(multiplier2, n, m);
        printf("Received result:\n");
        print_matrix(received_result, n, m);
        printf("Expected result:\n");
        print_matrix(expected_result, n, m);
    }

    matrix_free(multiplier1);
    matrix_free(multiplier2);
    matrix_free(expected_result);
    matrix_free(received_result);
}

void test_mtrx_mltply_opposite()
{
    int status = EXIT_SUCCESS;
    int n = 2;
    int m = 2;
    double s1_src[] = { 7, 4, 5, 3 };
    double s2_src[] = { 3, -4, -5, 7 };
    double exp_src[] = { 1, 0, 0, 1 };
    matrix multiplier1;
    matrix multiplier2;
    matrix expected_result;
    matrix received_result;

    printf("Test matrix_multiplication. Opposite second multiplier. ");

    multiplier1 = matrix_allocate(n, m);
    multiplier2 = matrix_allocate(n, m);
    expected_result = matrix_allocate(n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            multiplier1[i][j] = s1_src[i * m + j];
            multiplier2[i][j] = s2_src[i * m + j];
            expected_result[i][j] = exp_src[i * m + j];
        }

    received_result = matrix_multiplication(multiplier1, multiplier2);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (received_result[i][j] != expected_result[i][j])
                status = EXIT_FAILURE;

    if (status == EXIT_SUCCESS)
        printf("Success.\n");
    else
    {
        printf("Failure:\n");
        printf("Multiplier 1:\n");
        print_matrix(multiplier1, n, m);
        printf("Multiplier 2:\n");
        print_matrix(multiplier2, n, m);
        printf("Received result:\n");
        print_matrix(received_result, n, m);
        printf("Expected result:\n");
        print_matrix(expected_result, n, m);
    }

    matrix_free(multiplier1);
    matrix_free(multiplier2);
    matrix_free(expected_result);
    matrix_free(received_result);
}

void test_mtrx_mltply_rnd()
{
    int status = EXIT_SUCCESS;
    int n = 2;
    int m = 2;
    double s1_src[] = { 0, 1, 2, 3 };
    double s2_src[] = { 3, 2, 1, 0 };
    double exp_src[] = { 1, 0, 9, 4 };
    matrix multiplier1;
    matrix multiplier2;
    matrix expected_result;
    matrix received_result;

    printf("Test matrix_multiplication. Case of random multipliers. ");

    multiplier1 = matrix_allocate(n, m);
    multiplier2 = matrix_allocate(n, m);
    expected_result = matrix_allocate(n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            multiplier1[i][j] = s1_src[i * m + j];
            multiplier2[i][j] = s2_src[i * m + j];
            expected_result[i][j] = exp_src[i * m + j];
        }

    received_result = matrix_multiplication(multiplier1, multiplier2);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (received_result[i][j] != expected_result[i][j])
                status = EXIT_FAILURE;

    if (status == EXIT_SUCCESS)
        printf("Success.\n");
    else
    {
        printf("Failure:\n");
        printf("Multiplier 1:\n");
        print_matrix(multiplier1, n, m);
        printf("Multiplier 2:\n");
        print_matrix(multiplier2, n, m);
        printf("Received result:\n");
        print_matrix(received_result, n, m);
        printf("Expected result:\n");
        print_matrix(expected_result, n, m);
    }

    matrix_free(multiplier1);
    matrix_free(multiplier2);
    matrix_free(expected_result);
    matrix_free(received_result);
}

void test_mtrx_dtrmnt_rnd1()
{
    int status = EXIT_SUCCESS;
    int n = 3;
    int m = 3;
    double src[] = { 5, 6, 2, 3, 4, 5, 5, 6, 0 };
    matrix initial;
    double expected_result = -4;
    double received_result;

    printf("Test matrix_determinant. Case of random matrix #1. ");

    initial = matrix_allocate(n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            initial[i][j] = src[i * m + j];

    received_result = matrix_determinant(initial);
    {
        double temp = received_result - expected_result;
        if (temp < 0)
            temp *= -1;
        if (temp > EPS)
            status = EXIT_FAILURE;
    }

    if (status == EXIT_SUCCESS)
        printf("Success.\n");
    else
    {
        printf("Failure.\n");
        printf("Initial matrix:\n");
        print_matrix(initial, m, n);
        printf("Expected result: %g\n", expected_result);
        printf("Received result: %g\n", received_result);
    }

    matrix_free(initial);
}

void test_mtrx_dtrmnt_rnd2()
{
    int status = EXIT_SUCCESS;
    int n = 2;
    int m = 2;
    double src[] = { 11, -2, 7, 5 };
    matrix initial;
    double expected_result = 69;
    double received_result;

    printf("Test matrix_determinant. Case of random matrix #2. ");

    initial = matrix_allocate(n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            initial[i][j] = src[i * m + j];

    received_result = matrix_determinant(initial);
    {
        double temp = received_result - expected_result;
        if (temp < 0)
            temp *= -1;
        if (temp > EPS)
            status = EXIT_FAILURE;
    }

    if (status == EXIT_SUCCESS)
        printf("Success.\n");
    else
    {
        printf("Failure.\n");
        printf("Initial matrix:\n");
        print_matrix(initial, m, n);
        printf("Expected result: %g\n", expected_result);
        printf("Received result: %g\n", received_result);
    }

    matrix_free(initial);
}

void test_mtrx_dtrmnt_zero()
{
    int status = EXIT_SUCCESS;
    int n = 4;
    int m = 4;
    double src[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
    matrix initial;
    double expected_result = 0;
    double received_result;

    printf("Test matrix_determinant. Zero determinant. ");

    initial = matrix_allocate(n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            initial[i][j] = src[i * m + j];

    received_result = matrix_determinant(initial);
    {
        double temp = received_result - expected_result;
        if (temp < 0)
            temp *= -1;
        if (temp > EPS)
            status = EXIT_FAILURE;
    }

    if (status == EXIT_SUCCESS)
        printf("Success.\n");
    else
    {
        printf("Failure.\n");
        printf("Initial matrix:\n");
        print_matrix(initial, m, n);
        printf("Expected result: %g\n", expected_result);
        printf("Received result: %g\n", received_result);
    }

    matrix_free(initial);
}