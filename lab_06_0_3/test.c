#include <stdio.h>

#include "array_process.h"

void get_mentioned_max_test_1();
void get_mentioned_max_test_2();
void get_mentioned_max_test_3();

int main(void)
{
    get_mentioned_max_test_1();
    get_mentioned_max_test_2();
    get_mentioned_max_test_3();

    return 0;
}

void get_mentioned_max_test_1()
{
    int A[] = {1, 3, 4, 2, 25, 6, 7, 3, 1, 5, 6, 12};
    int n = sizeof(A)/sizeof(A[0]);
    int result;

    printf("Test 1 (get_mentioned_max).\n");

    printf("Initial array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    get_mentioned_max(A, A + n-1, &result);
    printf("Result: %d\n\n", result);
}

void get_mentioned_max_test_2()
{
    int A[] = {23, 24, -33, -22, -14, -39, -33, -33, -7, -17, -17, -19};
    int n = sizeof(A)/sizeof(A[0]);
    int result;

    printf("Test 2 (get_mentioned_max).\n");

    printf("Initial array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    get_mentioned_max(A, A + n-1, &result);
    printf("Result: %d\n\n", result);
}

void get_mentioned_max_test_3()
{
    int A[] = {-7, 3, -15, 17, 22, -22, -37, -18, -5, -16};
    int n = sizeof(A)/sizeof(A[0]);
    int result;

    printf("Test 3 (get_mentioned_max).\n");

    printf("Initial array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    get_mentioned_max(A, A + n-1, &result);
    printf("Result: %d\n\n", result);
}
