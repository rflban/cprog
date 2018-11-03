#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_str.h"

void test_my_strspn_acpt(int *err_cnt);
void test_my_strspn_no_acpt(int *err_cnt);
void test_my_strspn_empty_str(int *err_cnt);
void test_my_strspn_empty_acpt(int *err_cnt);


int main()
{
    int err_cnt = 0;

    test_my_strspn_acpt(&err_cnt);
    test_my_strspn_no_acpt(&err_cnt);
    test_my_strspn_empty_str(&err_cnt);
    test_my_strspn_empty_acpt(&err_cnt);

    return ((err_cnt == 0) ? EXIT_SUCCESS : EXIT_FAILURE);
}

void test_my_strspn_acpt(int *err_cnt)
{
    int recieved_value;
    int expected_value = 1;
    const char str[] = "rocket";
    const char accept[] = "raketa";

    printf("Test my_strspn. String with accept value. ");

    expected_value = strspn(str, accept);
    recieved_value = my_strspn(str, accept);
    
    if (expected_value == recieved_value)
    {
        printf("Success.\n");
        return;
    }

    (*err_cnt)++;
    printf("Failure.\n");

    printf("Initial string:\n%s\n", str);
    printf("accept string:\n%s\n", accept);
    printf("Expected value:\n%d\n", expected_value);
    printf("Recieved value:\n%d\n", recieved_value);
}


void test_my_strspn_no_acpt(int *err_cnt)
{
    int recieved_value;
    int expected_value = 0;
    const char str[] = "blue";
    const char accept[] = "siny";

    printf("Test my_strspn. String without accept value. ");

    expected_value = strspn(str, accept);
    recieved_value = my_strspn(str, accept);
    
    if (expected_value == recieved_value)
    {
        printf("Success.\n");
        return;
    }

    (*err_cnt)++;
    printf("Failure.\n");

    printf("Initial string:\n%s\n", str);
    printf("accept string:\n%s\n", accept);
    printf("Expected value:\n%d\n", expected_value);
    printf("Recieved value:\n%d\n", recieved_value);
}

void test_my_strspn_empty_str(int *err_cnt)
{
    int recieved_value;
    int expected_value = 0;
    const char str[] = "";
    const char accept[] = "empty";

    printf("Test my_strspn. Empty initial string. ");

    expected_value = strspn(str, accept);
    recieved_value = my_strspn(str, accept);
    
    if (expected_value == recieved_value)
    {
        printf("Success.\n");
        return;
    }

    (*err_cnt)++;
    printf("Failure.\n");

    printf("Initial string:\n%s\n", str);
    printf("accept string:\n%s\n", accept);
    printf("Expected value:\n%d\n", expected_value);
    printf("Recieved value:\n%d\n", recieved_value);
}

void test_my_strspn_empty_acpt(int *err_cnt)
{
    int recieved_value;
    int expected_value = 0;
    const char str[] = "empty";
    const char accept[] = "";

    printf("Test my_strspn. Empty accept string. ");

    expected_value = strspn(str, accept);
    recieved_value = my_strspn(str, accept);

    if (expected_value == recieved_value)
    {
        printf("Success.\n");
        return;
    }

    (*err_cnt)++;
    printf("Failure.\n");

    printf("Initial string:\n%s\n", str);
    printf("accept string:\n%s\n", accept);
    printf("Expected value:\n%d\n", expected_value);
    printf("Recieved value:\n%d\n", recieved_value);
}