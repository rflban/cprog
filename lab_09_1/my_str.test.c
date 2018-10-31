#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_str.h"

void test_my_strcspn_rjct(int *err_cnt);
void test_my_strcspn_no_rjct(int *err_cnt);
void test_my_strcspn_empty_str(int *err_cnt);
void test_my_strcspn_empty_rjct(int *err_cnt);


int main()
{
    int err_cnt = 0;

    test_my_strcspn_rjct(&err_cnt);
    test_my_strcspn_no_rjct(&err_cnt);
    test_my_strcspn_empty_str(&err_cnt);
    test_my_strcspn_empty_rjct(&err_cnt);

    return ((err_cnt == 0) ? EXIT_SUCCESS : EXIT_FAILURE);
}

void test_my_strcspn_rjct(int *err_cnt)
{
    int recieved_value;
    int expected_value = 1;
    const char str[] = "elephant";
    const char reject[] = "slon";

    printf("Test my_strcspn. String with reject value. ");

    expected_value = strcspn(str, reject);
    recieved_value = my_strcspn(str, reject);
    
    if (expected_value == recieved_value)
    {
        printf("Success.\n");
        return;
    }

    (*err_cnt)++;
    printf("Failure.\n");

    printf("Initial string:\n%s\n", str);
    printf("Reject string:\n%s\n", reject);
    printf("Expected value:\n%d\n", expected_value);
    printf("Recieved value:\n%d\n", recieved_value);
}


void test_my_strcspn_no_rjct(int *err_cnt)
{
    int recieved_value;
    int expected_value = 4;
    const char str[] = "blue";
    const char reject[] = "siny";

    printf("Test my_strcspn. String without reject value. ");

    expected_value = strcspn(str, reject);
    recieved_value = my_strcspn(str, reject);
    
    if (expected_value == recieved_value)
    {
        printf("Success.\n");
        return;
    }

    (*err_cnt)++;
    printf("Failure.\n");

    printf("Initial string:\n%s\n", str);
    printf("Reject string:\n%s\n", reject);
    printf("Expected value:\n%d\n", expected_value);
    printf("Recieved value:\n%d\n", recieved_value);
}

void test_my_strcspn_empty_str(int *err_cnt)
{
    int recieved_value;
    int expected_value = 0;
    const char str[] = "";
    const char reject[] = "empty";

    printf("Test my_strcspn. Empty initial string. ");

    expected_value = strcspn(str, reject);
    recieved_value = my_strcspn(str, reject);
    
    if (expected_value == recieved_value)
    {
        printf("Success.\n");
        return;
    }

    (*err_cnt)++;
    printf("Failure.\n");

    printf("Initial string:\n%s\n", str);
    printf("Reject string:\n%s\n", reject);
    printf("Expected value:\n%d\n", expected_value);
    printf("Recieved value:\n%d\n", recieved_value);
}

void test_my_strcspn_empty_rjct(int *err_cnt)
{
    int recieved_value;
    int expected_value = 5;
    const char str[] = "empty";
    const char reject[] = "";

    printf("Test my_strcspn. Empty reject string. ");

    expected_value = strcspn(str, reject);
    recieved_value = my_strcspn(str, reject);

    if (expected_value == recieved_value)
    {
        printf("Success.\n");
        return;
    }

    (*err_cnt)++;
    printf("Failure.\n");

    printf("Initial string:\n%s\n", str);
    printf("Reject string:\n%s\n", reject);
    printf("Expected value:\n%d\n", expected_value);
    printf("Recieved value:\n%d\n", recieved_value);
}