#include <stdio.h>

#include "array_process.h"

void test_get_mentioned_max_positive_nums();
void test_get_mentioned_max_negative_nums();
void test_get_mentioned_max_signed_nums();

void test_read_array_positive_nums();
void test_read_array_negative_nums();
void test_read_array_signed_nums();


int main(void)
{
    printf("1. ");
    test_get_mentioned_max_positive_nums();
    printf("2. ");
    test_get_mentioned_max_negative_nums();
    printf("3. ");
    test_get_mentioned_max_signed_nums();

    printf("\n");


    printf("1. ");
    test_read_array_positive_nums();
    printf("2. ");
    test_read_array_negative_nums();
    printf("3. ");
    test_read_array_signed_nums();

    return 0;
}

void test_get_mentioned_max_positive_nums()
{
    int A[] = {1, 3, 4, 2, 25, 6, 7, 3, 1, 5, 6, 12};
    int n = 12;
    int received_result;
    int expected_result = 28;

    get_mentioned_max(A, A + n-1, &received_result);
    if (expected_result == received_result)
    {
        printf("Test get_mentioned_max, positive nums was successed.\n");
        return;
    }

    printf("Test get_mentioned_max, positive nums was failed.\n");

    printf("Initial array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    printf("expected_result: %d\n", expected_result);
    printf("received_result: %d\n", received_result);

    printf("\n");
}

void test_get_mentioned_max_negative_nums()
{
    int A[] = {-23, -24, -33, -22, -14, -39, -33, -33, -7, -17, -17, -19};
    int n = 12;
    int received_result;
    int expected_result = -29;

    get_mentioned_max(A, A + n-1, &received_result);
    if (expected_result == received_result)
    {
        printf("Test get_mentioned_max, negative nums was successed.\n");
        return;
    }

    printf("Test get_mentioned_max, negative nums was failed.\n");

    printf("Initial array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    printf("expected_result: %d\n", expected_result);
    printf("received_result: %d\n", received_result);

    printf("\n");
}

void test_get_mentioned_max_signed_nums()
{
    int A[] = {-7, 3, -15, 17, 22, -22, -37, -18, -5, -16};
    int n = 10;
    int received_result;
    int expected_result = 0;

    get_mentioned_max(A, A + n-1, &received_result);
    if (expected_result == received_result)
    {
        printf("Test get_mentioned_max, signed nums was successed.\n");
        return;
    }

    printf("Test get_mentioned_max, signed nums was failed.\n");

    printf("Initial array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    printf("expected_result: %d\n", expected_result);
    printf("received_result: %d\n", received_result);

    printf("\n");
}

void test_read_array_positive_nums()
{
    int received_result[MAX_ARRAY_LEN];
    int r_n;
    int expected_result[] = {1, 3, 4, 2, 25, 6, 7, 3, 1, 5, 6, 12};
    int e_n = 12;
    FILE* test_file;
    char test_file_name[] = "in_1.txt";

    test_file = fopen(test_file_name, "r");

    read_array(test_file, received_result, &r_n);
    if (r_n == e_n)
    {
        int flag = 0;
        for (int i = 0; i < e_n; i++)
        {
            if (received_result[i] != expected_result[i])
            {
                flag = 1;
            }
        }
        if (!flag)
        {
            printf("Test read_array, positive nums was successed.\n");
            fclose(test_file);
            return;
        }
    }

    printf("Test read_array, positive nums was failed.\n");

    printf("Input file - %s\n", test_file_name);
    printf("Expected array:\n");
    for (int i = 0; i < e_n; i++)
        printf("%d ", expected_result[i]);
    printf("\n");

    printf("Received array:\n");
    for (int i = 0; i < r_n; i++)
        printf("%d ", received_result[i]);
    printf("\n");

    printf("\n");
    fclose(test_file);
}

void test_read_array_negative_nums()
{
    int received_result[MAX_ARRAY_LEN];
    int r_n;
    int expected_result[] = {-23, -24, -33, -22, -14, -39, -33, \
                             -33, -7, -17, -17, -19};
    int e_n = 12;
    FILE* test_file;
    char test_file_name[] = "in_2.txt";

    test_file = fopen(test_file_name, "r");

    read_array(test_file, received_result, &r_n);
    if (r_n == e_n)
    {
        int flag = 0;
        for (int i = 0; i < e_n; i++)
        {
            if (received_result[i] != expected_result[i])
            {
                flag = 1;
            }
        }
        if (!flag)
        {
            printf("Test read_array, negative nums was successed.\n");
            fclose(test_file);
            return;
        }
    }

    printf("Test read_array, negative nums was failed.\n");

    printf("Input file - %s\n", test_file_name);
    printf("Expected array:\n");
    for (int i = 0; i < e_n; i++)
        printf("%d ", expected_result[i]);
    printf("\n");

    printf("Received array:\n");
    for (int i = 0; i < r_n; i++)
        printf("%d ", received_result[i]);
    printf("\n");

    printf("\n");
    fclose(test_file);
}

void test_read_array_signed_nums()
{
    int received_result[MAX_ARRAY_LEN];
    int r_n;
    int expected_result[] = {-7, 3, -15, 17, 22, -22, -37, -18, -5, -16};
    int e_n = 10;
    FILE* test_file;
    char test_file_name[] = "in_3.txt";

    test_file = fopen(test_file_name, "r");

    read_array(test_file, received_result, &r_n);
    if (r_n == e_n)
    {
        int flag = 0;
        for (int i = 0; i < e_n; i++)
        {
            if (received_result[i] != expected_result[i])
            {
                flag = 1;
            }
        }
        if (!flag)
        {
            printf("Test read_array, signed nums was successed.\n");
            fclose(test_file);
            return;
        }
    }

    printf("Test read_array, signed nums was failed.\n");

    printf("Input file - %s\n", test_file_name);
    printf("Expected array:\n");
    for (int i = 0; i < e_n; i++)
        printf("%d ", expected_result[i]);
    printf("\n");

    printf("Received array:\n");
    for (int i = 0; i < r_n; i++)
        printf("%d ", received_result[i]);
    printf("\n");

    printf("\n");
    fclose(test_file);
}
