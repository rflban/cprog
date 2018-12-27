#include <stdio.h>
#include <stdlib.h>

#include "myio.h"

void test_my_snprintf_nullptreq(int *error_counter);
void test_my_snprintf_nonformat(int *error_counter);
void test_my_snprintf_onlyspecs(int *error_counter);
void test_my_snprintf_reachnums(int *error_counter);
void test_my_snprintf_reachstrs(int *error_counter);
void test_my_snprintf_numandstr(int *error_counter);
void test_my_snprintf_invspecs1(int *error_counter);
void test_my_snprintf_invspecs2(int *error_counter);


int main(int argc, char **argv)
{
    // int rc1;
    // int rc2;
    // char str1[10] = {0};
    // char str2[10] = {0};

    // rc1 = my_snprintf(str1, 10, "123%hs%d", "13", 3);
    // rc2 = snprintf(str2, 10, "123%hs%d", "13", 3);

    // printf("%d\n%s\n", rc1, str1);
    // printf("%d\n%s\n", rc2, str2);

    return EXIT_SUCCESS;
}
