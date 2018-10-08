#include <stdio.h>
#include <stdlib.h>

#include "array_process.h"

void test_mysort_sorted_array();
void test_mysort_unsorted_array();
void test_mysort_identical_els_arr();

void test_key_first_max();
void test_key_first_min();
void test_key_many_extremas();


int main(void)
{
    setbuf(stdout, NULL);

    test_mysort_sorted_array();
    test_mysort_unsorted_array();
    test_mysort_identical_els_arr();

    test_key_first_max();
    test_key_first_min();
    test_key_many_extremas();

    printf("\n");

    return 0;
}

void test_mysort_sorted_array()
{
    int initial[] = { 1, 2, 3, 4, 5 };
    int n = 5;
    int received_result[] = { 1, 2, 3, 4, 5 };
    int expected_result[] = { 1, 2, 3, 4, 5 };

    mysort(received_result, n, sizeof(received_result[0]), comparator);
    for (int i = 0; i < n; i++)
    {
        if (received_result[i] != expected_result[i])
        {
            printf("Test mysort, sorted array, was failed.\n");

            printf("Initial array:\n");
            for (int j = 0; j < n; j++)
                printf("%d ", initial[j]);
            printf("\n");

            printf("Received array:\n");
            for (int j = 0; j < n; j++)
                printf("%d ", received_result[j]);
            printf("\n");

            printf("Expected array:\n");
            for (int j = 0; j < n; j++)
                printf("%d ", expected_result[j]);
            printf("\n");

            printf("\n");
            return;
        }
    }

    printf("Test mysort, sorted array, was successed.\n");
}

void test_mysort_unsorted_array()
{
    int initial[] = { 5, 4, 3, 2, 1 };
    int n = 5;
    int received_result[] = { 5, 4, 3, 2, 1 };
    int expected_result[] = { 1, 2, 3, 4, 5 };

    mysort(received_result, n, sizeof(received_result[0]), comparator);
    for (int i = 0; i < n; i++)
    {
        if (received_result[i] != expected_result[i])
        {
            printf("Test mysort, unsorted array, was failed.\n");

            printf("Initial array:\n");
            for (int j = 0; j < n; j++)
                printf("%d ", initial[j]);
            printf("\n");

            printf("Received array:\n");
            for (int j = 0; j < n; j++)
                printf("%d ", received_result[j]);
            printf("\n");

            printf("Expected array:\n");
            for (int j = 0; j < n; j++)
                printf("%d ", expected_result[j]);
            printf("\n");

            return;
        }
    }

    printf("Test mysort, unsorted array, was successed.\n");
}

void test_mysort_identical_els_arr()
{
    int initial[] = { 1, 1, 1, 1, 1 };
    int n = 5;
    int received_result[] = { 1, 1, 1, 1, 1 };
    int expected_result[] = { 1, 1, 1, 1, 1 };

    mysort(received_result, n, sizeof(received_result[0]), comparator);
    for (int i = 0; i < n; i++)
    {
        if (received_result[i] != expected_result[i])
        {
            printf("Test mysort, identical elements array, was failed.\n");

            printf("Initial array:\n");
            for (int j = 0; j < n; j++)
                printf("%d ", initial[j]);
            printf("\n");

            printf("Received array:\n");
            for (int j = 0; j < n; j++)
                printf("%d ", received_result[j]);
            printf("\n");

            printf("Expected array:\n");
            for (int j = 0; j < n; j++)
                printf("%d ", expected_result[j]);
            printf("\n");

            return;
        }
    }

    printf("Test mysort, identical elements array, was successed.\n");
}

void test_key_first_max()
{
    int initial[] = { 5, 4, 3, 2, 1 };
    int n = 3;
    int *rr_pb, *rr_pe;
    int expected_result[] = { 4, 3, 2 };

    key(&initial[0], &initial[sizeof(initial) / sizeof(initial[0])], &rr_pb, &rr_pe);
    for (int i = 0; i < n; i++)
    {
        if (rr_pb[i] != expected_result[i])
        {
            printf("Test key, first max, was failed.\n");

            printf("Initial array:\n");
            for (int j = 0; j < sizeof(initial) / sizeof(initial[0]); j++)
                printf("%d ", initial[j]);
            printf("\n");

            printf("Received array:\n");
            for (int j = 0; j < n; j++)
                printf("%d ", rr_pb[j]);
            printf("\n");

            printf("Expected array:\n");
            for (int j = 0; j < n; j++)
                printf("%d ", expected_result[j]);
            printf("\n");

            free(rr_pb);
            return;
        }
    }

    printf("Test key, first max, was successed.\n");
    free(rr_pb);
}

void test_key_first_min()
{
    int initial[] = { 1, 2, 3, 4, 5 };
    int n = 3;
    int *rr_pb, *rr_pe;
    int expected_result[] = { 2, 3, 4 };

    key(&initial[0], &initial[sizeof(initial) / sizeof(initial[0])], &rr_pb, &rr_pe);
    for (int i = 0; i < n; i++)
    {
        if (rr_pb[i] != expected_result[i])
        {
            printf("Test key, first min, was failed.\n");

            printf("Initial array:\n");
            for (int j = 0; j < sizeof(initial) / sizeof(initial[0]); j++)
                printf("%d ", initial[j]);
            printf("\n");

            printf("Received array:\n");
            for (int j = 0; j < n; j++)
                printf("%d ", rr_pb[j]);
            printf("\n");

            printf("Expected array:\n");
            for (int j = 0; j < n; j++)
                printf("%d ", expected_result[j]);
            printf("\n");

            free(rr_pb);
            return;
        }
    }

    printf("Test key, first min, was successed.\n");
    free(rr_pb);
}

void test_key_many_extremas()
{
    int initial[] = { 1, 1, 3, 5, 5 };
    int n = 2;
    int *rr_pb, *rr_pe;
    int expected_result[] = { 1, 3 };

    key(&initial[0], &initial[sizeof(initial) / sizeof(initial[0])], &rr_pb, &rr_pe);
    for (int i = 0; i < n; i++)
    {
        if (rr_pb[i] != expected_result[i])
        {
            printf("Test key, many extremas, was failed.\n");

            printf("Initial array:\n");
            for (int j = 0; j < sizeof(initial) / sizeof(initial[0]); j++)
                printf("%d ", initial[j]);
            printf("\n");

            printf("Received array:\n");
            for (int j = 0; j < n; j++)
                printf("%d ", rr_pb[j]);
            printf("\n");

            printf("Expected array:\n");
            for (int j = 0; j < n; j++)
                printf("%d ", expected_result[j]);
            printf("\n");

            free(rr_pb);
            return;
        }
    }

    printf("Test key, many extremas, was successed.\n");
    free(rr_pb);
}
