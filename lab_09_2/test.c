#include <stdio.h>
#include <stdlib.h>

#include "my_str.h"

#define PRINT_ERR_SRCH_RES(initial, expected, received, search) printf("Initial:\n%s\nExpected:\n%s\nReceived:\n%s\nSearch:\n%s\n", initial, expected, received, search)

void test_str_replace_no_match(int *err_cnt);
void test_str_replace_one_match(int *err_cnt);
void test_str_replace_two_matches(int *err_cnt);

int main(void)
{
    int err_cnt = 0;

    test_str_replace_no_match(&err_cnt);
    test_str_replace_one_match(&err_cnt);
    test_str_replace_two_matches(&err_cnt);
    
    return ((err_cnt == 0) ? EXIT_SUCCESS : EXIT_FAILURE);
}

void test_str_replace_no_match(int *err_cnt)
{
    char *initial = "Aleksander Stepanov"; /*Если что, я Фарис*/
    char *expected = "Aleksander Stepanov";
    char *search = "Kupry";
    char *replace = "Loh";
    char *received;
    int expected_len;
    int received_len;

    printf("Test str_replace. No match case. ");

    received = str_replace(initial, search, replace);

    for (expected_len = 0; expected[expected_len] != '\0'; expected_len++);
    for (received_len = 0; received[received_len] != '\0'; received_len++);

    if (expected_len == received_len)
    {
        int i;

        for (i = 0; i < received_len; i++)
        {
            if (expected[i] != received[i])
                break;
        }

        if (i == received_len)
        {
            printf("Success.\n");
            free(received);
            return;
        }
    }

    printf("Failure.\n");

    PRINT_ERR_SRCH_RES(initial, expected, received, search);
    printf("Replace:\n%s\n", replace);

    free(received);

    *err_cnt += 1;
}

void test_str_replace_one_match(int *err_cnt)
{
    char *initial = "Aleksander Kupry"; /*Если что, я Фарис*/
    char *expected = "Aleksander Kuprin";
    char *search = "Kupry";
    char *replace = "Kuprin";
    char *received;
    int expected_len;
    int received_len;

    printf("Test str_replace. One match case. ");

    received = str_replace(initial, search, replace);

    for (expected_len = 0; expected[expected_len] != '\0'; expected_len++);
    for (received_len = 0; received[received_len] != '\0'; received_len++);

    if (expected_len == received_len)
    {
        int i;

        for (i = 0; i < received_len; i++)
        {
            if (expected[i] != received[i])
                break;
        }

        if (i == received_len)
        {
            printf("Success.\n");
            free(received);
            return;
        }
    }

    printf("Failure.\n");

    PRINT_ERR_SRCH_RES(initial, expected, received, search);
    printf("Replace:\n%s\n", replace);

    free(received);

    *err_cnt += 1;
}

void test_str_replace_two_matches(int *err_cnt)
{
    char *initial = "Aleksander Aleksanderovich Kupry"; /*Если что, я Фарис*/
    char *expected = "Ivan Ivanovich Kupry";
    char *search = "Aleksander";
    char *replace = "Ivan";
    char *received;
    int expected_len;
    int received_len;

    printf("Test str_replace. Two matches case. ");

    received = str_replace(initial, search, replace);

    for (expected_len = 0; expected[expected_len] != '\0'; expected_len++);
    for (received_len = 0; received[received_len] != '\0'; received_len++);

    if (expected_len == received_len)
    {
        int i;

        for (i = 0; i < received_len; i++)
        {
            if (expected[i] != received[i])
                break;
        }

        if (i == received_len)
        {
            printf("Success.\n");
            free(received);
            return;
        }
    }

    printf("Failure.\n");

    PRINT_ERR_SRCH_RES(initial, expected, received, search);
    printf("Replace:\n%s\n", replace);

    free(received);

    *err_cnt += 1;
}