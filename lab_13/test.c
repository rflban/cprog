#include <stdio.h>
#include <stdlib.h>

#include "mylib.h"

void test_fnd_mx_tmprtr_nullptr(int *error_counter);
void test_fnd_mx_tmprtr_alltime(int *error_counter);
void test_fnd_mx_tmprtr_oneyear(int *error_counter);

void test_fnd_mn_tmprtr_nullptr(int *error_counter);
void test_fnd_mn_tmprtr_alltime(int *error_counter);
void test_fnd_mn_tmprtr_oneyear(int *error_counter);

struct list_head *head;

int main(int argc, char **argv)
{
    int error_counter = 0;
    FILE *inputs;

    head = (struct list_head*)malloc(sizeof(struct list_head));
    INIT_LIST_HEAD(head);

    inputs = fopen("SPB.csv", "r");

    read_data(inputs, head);

    fclose(inputs);

    test_fnd_mx_tmprtr_nullptr(&error_counter);
    test_fnd_mx_tmprtr_alltime(&error_counter);
    test_fnd_mx_tmprtr_oneyear(&error_counter);
    printf("\n");

    test_fnd_mn_tmprtr_nullptr(&error_counter);
    test_fnd_mn_tmprtr_alltime(&error_counter);
    test_fnd_mn_tmprtr_oneyear(&error_counter);
    printf("\n");

    free_data(head);
    free(head);

    return (error_counter == 0 ? EXIT_SUCCESS : EXIT_FAILURE);
}

void test_fnd_mx_tmprtr_nullptr(int *error_counter)
{
    printf("Test find_max_temperature. Null pointer request case. ");

    find_max_temperature(NULL, 0);

    printf("Success.\n");
}

void test_fnd_mx_tmprtr_alltime(int *error_counter)
{
    printf("Test find_max_temperature. Null pointer request case. ");

    int received;
    int expected = 371;

    received = find_max_temperature(head, 0);

    if (expected != received)
    {
        *error_counter += 1;

        printf("Faliure.\n");

        printf("Expected: %d\n", expected);
        printf("Received: %d\n", received);
    }
    else
    {
        printf("Success.\n");
    }
}

void test_fnd_mx_tmprtr_oneyear(int *error_counter)
{
    printf("Test find_max_temperature. Null pointer request case. ");

    int year = 2000;
    int received;
    int expected = 302;

    received = find_max_temperature(head, year);

    if (expected != received)
    {
        *error_counter += 1;

        printf("Faliure.\n");

        printf("Year: %d\n", year);
        printf("Expected: %d\n", expected);
        printf("Received: %d\n", received);
    }
    else
    {
        printf("Success.\n");
    }
}


void test_fnd_mn_tmprtr_nullptr(int *error_counter)
{
    printf("Test find_min_temperature. Null pointer request case. ");

    find_min_temperature(NULL, 0);

    printf("Success.\n");
}

void test_fnd_mn_tmprtr_alltime(int *error_counter)
{
    printf("Test find_max_temperature. Null pointer request case. ");

    int received;
    int expected = -356;

    received = find_min_temperature(head, 0);

    if (expected != received)
    {
        *error_counter += 1;

        printf("Faliure.\n");

        printf("Expected: %d\n", expected);
        printf("Received: %d\n", received);
    }
    else
    {
        printf("Success.\n");
    }
}

void test_fnd_mn_tmprtr_oneyear(int *error_counter)
{
    printf("Test find_max_temperature. Null pointer request case. ");

    int year = 2000;
    int received;
    int expected = -198;

    received = find_min_temperature(head, year);

    if (expected != received)
    {
        *error_counter += 1;

        printf("Faliure.\n");

        printf("Year: %d\n", year);
        printf("Expected: %d\n", expected);
        printf("Received: %d\n", received);
    }
    else
    {
        printf("Success.\n");
    }
}
