#include <stdio.h>
#include <stdlib.h>

#include "exit.h"
#include "matrix.h"

int test_find_foll_fined_one()
{
    printf("Test find_max_followers. One finded case. ");

    int rc = EXIT_SUCCESS;

    int findn;
    int rowsn = 5;
    int colsn = 5;
    int src[] = { 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 };
    int expected[] = { 3 };
    MATRIX initial;
    MATRIX recieved;

    initial = matrix_allocate(rowsn, colsn);
    for (int i = 0; i < rowsn; i++)
        for (int j = 0; j < colsn; j++)
            initial[i][j] = src[i * rowsn + j];

    recieved = find_max_followers(initial, rowsn, colsn, &findn);
    if (findn == sizeof(expected) / sizeof(expected[0]))
    {
        for (int i = 0; i < findn; i++)
        {
            if (recieved[0][i] != expected[i])
            {
                rc = EXIT_FAILURE;
                break;
            }
        }
    }
    else
    {
        rc = EXIT_FAILURE;
    }

    if (rc == EXIT_SUCCESS)
    {
        printf("Success.\n");
    }
    else
    {
        printf("Failure.\n");

        printf("Initial:\n");
        for (int i = 0; i < rowsn; i++)
        {
            for (int j = 0; j < colsn; j++)
                printf("%d ", src[i * rowsn + j]);
            printf("\n");
        }

        printf("Expected:\n");
        for (int i = 0; i < sizeof(expected) / sizeof(expected[0]); i++)
        {
            printf("%d ", expected[i]);
        }
        printf("\n");

        printf("Recieved:\n");
        for (int i = 0; i < findn; i++)
        {
            printf("%d ", recieved[0][i]);
        }
        printf("\n");
    }

    matrix_free(initial, rowsn);
    matrix_free(recieved, 1);

    return rc;
}

int test_find_foll_fined_two()
{
    printf("Test find_max_followers. Two finded case. ");

    int rc = EXIT_SUCCESS;

    int findn;
    int rowsn = 5;
    int colsn = 5;
    int src[] = { 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0 };
    int expected[] = { 2, 3 };
    MATRIX initial;
    MATRIX recieved;

    initial = matrix_allocate(rowsn, colsn);
    for (int i = 0; i < rowsn; i++)
        for (int j = 0; j < colsn; j++)
            initial[i][j] = src[i * rowsn + j];

    recieved = find_max_followers(initial, rowsn, colsn, &findn);
    if (findn == sizeof(expected) / sizeof(expected[0]))
    {
        for (int i = 0; i < findn; i++)
        {
            if (recieved[i][0] != expected[i])
            {
                rc = EXIT_FAILURE;
                break;
            }
        }
    }
    else
    {
        rc = EXIT_FAILURE;
    }

    if (rc == EXIT_SUCCESS)
    {
        printf("Success.\n");
    }
    else
    {
        printf("Failure.\n");

        printf("Initial:\n");
        for (int i = 0; i < rowsn; i++)
        {
            for (int j = 0; j < colsn; j++)
                printf("%d ", src[i * rowsn + j]);
            printf("\n");
        }

        printf("Expected:\n");
        for (int i = 0; i < sizeof(expected) / sizeof(expected[0]); i++)
        {
            printf("%d ", expected[i]);
        }
        printf("\n");

        printf("Recieved:\n");
        for (int i = 0; i < findn; i++)
        {
            printf("%d ", recieved[i][0]);
        }
        printf("\n");
    }

    matrix_free(initial, rowsn);
    matrix_free(recieved, findn);

    return rc;
}

int main(void)
{
    int return_code = 0;

    return_code += test_find_foll_fined_one();
    return_code += test_find_foll_fined_two();

    return return_code;
}