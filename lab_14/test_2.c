#include <stdio.h>
#include <stdlib.h>

#include "set_2.h"

void test_set_push_randset(int *error_counter);

void test_set_pop_nonodes(int *error_counter);
void test_set_pop_randset(int *error_counter);

void test_set_is_containg(int *error_counter);

void test_set_is_empty(int *error_counter);

void test_set_is_full(int *error_counter);


int main(int argc, char **argv)
{
    int error_counter = 0;
    
    test_set_push_randset(&error_counter);
    test_set_pop_nonodes(&error_counter);
    test_set_pop_randset(&error_counter);
    test_set_is_containg(&error_counter);
    test_set_is_empty(&error_counter);
    test_set_is_full(&error_counter);

    return (error_counter == 0 ? EXIT_SUCCESS : EXIT_FAILURE);
}

void test_set_push_fullset(int *error_counter)
{
    printf("Test set_push. Full set case. ");

    set_t set = set_create();
    
    set_push(set, 1);

    if (set_push(set, 2) == EXIT_FAILURE)
    {
        printf("Success.\n");

        set_destroy(set);

        return;
    }

    *error_counter += 1;

    set_destroy(set);

    printf("Failure.\n");
}

void test_set_push_randset(int *error_counter)
{
    printf("Test set_push. Random set case. ");

    set_t set = set_create();
    
    set_push(set, 1);

    if (set_push(set, 2) == EXIT_SUCCESS)
    {
        printf("Success.\n");

        set_destroy(set);

        return;
    }

    *error_counter += 1;

    set_destroy(set);

    printf("Failure.\n");
}

void test_set_pop_nonodes(int *error_counter)
{
    printf("Test set_pop. Empty set case. ");

    item_t item;
    set_t set = set_create();

    if (set_pop(set, &item) == EXIT_FAILURE)
    {
        printf("Success.\n");

        set_destroy(set);

        return;
    }

    *error_counter += 1;

    set_destroy(set);

    printf("Failure.\n");
}

void test_set_pop_randset(int *error_counter)
{
    printf("Test set_pop. Random set case. ");

    item_t item;
    set_t set = set_create();

    set_push(set, 1);

    if (set_pop(set, &item) == EXIT_SUCCESS)
    {
        printf("Success.\n");

        set_destroy(set);

        return;
    }

    *error_counter += 1;

    set_destroy(set);

    printf("Failure.\n");
}

void test_set_is_containg(int *error_counter)
{
    printf("Test set_is_containg. Random set case. ");

    set_t set = set_create();
    
    set_push(set, 1);

    if (set_is_containg(set, 1) != NULL)
    {
        printf("Success.\n");

        set_destroy(set);

        return;
    }

    *error_counter += 1;

    set_destroy(set);

    printf("Failure.\n");
}

void test_set_is_empty(int *error_counter)
{
    printf("Test set_is_empty. Random set case. ");

    set_t set = set_create();

    if (set_is_empty(set) == true)
    {
        printf("Success.\n");

        set_destroy(set);

        return;
    }

    *error_counter += 1;

    set_destroy(set);

    printf("Failure.\n");
}

void test_set_is_full(int *error_counter)
{
    printf("Test set_is_full. Random set case. ");

    set_t set = set_create();

    set_push(set, 1);

    if (set_is_full(set) == false)
    {
        printf("Success.\n");

        set_destroy(set);

        return;
    }

    *error_counter += 1;

    set_destroy(set);

    printf("Failure.\n");
}

