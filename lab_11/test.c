#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "myio.h"

#define STR_SIZE 256

void test_my_snprintf_nullptreq(int *error_counter);
void test_my_snprintf_nonespecs(int *error_counter);
void test_my_snprintf_onlyspecs(int *error_counter);
void test_my_snprintf_rndformat(int *error_counter);


int main(int argc, char **argv)
{
    int error_counter = 0;

    test_my_snprintf_nullptreq(&error_counter);
    test_my_snprintf_nonespecs(&error_counter);
    test_my_snprintf_onlyspecs(&error_counter);

    return EXIT_SUCCESS;
}

void test_my_snprintf_nullptreq(int *error_counter)
{
    printf("Test my_snprintf. Null pointer request case. ");

    my_snprintf(NULL, 0, NULL);

    printf("Success.\n");
}

void test_my_snprintf_nonespecs(int *error_counter)
{
    printf("Test my_snprintf. Format string without specifiers. ");

#ifdef MYFORMAT
#undef MYFORMAT
#endif
#define MYFORMAT "1234"

    int erc;
    int rrc;
    int cmp;
    char expected[STR_SIZE];
    char recieved[STR_SIZE];

    erc = snprintf(expected, STR_SIZE, MYFORMAT);
    rrc = my_snprintf(recieved, STR_SIZE, MYFORMAT);

    cmp = strcmp(expected, recieved);

    if ((erc != rrc) || (cmp != 0))
    {
        printf("Failure.\n");

        printf("Format string:\n%s\n", MYFORMAT);

        printf("snprintf return code: %d\n", erc);
        printf("Expected:\n%s\n", expected);

        printf("my_snprintf return code: %d\n", rrc);
        printf("Recieved:\n%s\n", recieved);
    }
    else
    {
        printf("Success.\n");
    }
}

void test_my_snprintf_onlyspecs(int *error_counter)
{
    printf("Test my_snprintf. Format string with only specifiers. ");

#ifdef MYFORMAT
#undef MYFORMAT
#endif
#define MYFORMAT "%d%hd%i%hi%s"

    int erc;
    int rrc;
    int cmp;
    char expected[STR_SIZE];
    char recieved[STR_SIZE];

    erc = snprintf(expected, STR_SIZE, MYFORMAT, 1, 2, 3, 4, "5");
    rrc = my_snprintf(recieved, STR_SIZE, MYFORMAT, 1, 2, 3, 4, "5");

    cmp = strcmp(expected, recieved);

    if ((erc != rrc) || (cmp != 0))
    {
        printf("Failure.\n");

        printf("Format string:\n%s\n", MYFORMAT);

        printf("snprintf return code: %d\n", erc);
        printf("Expected:\n%s\n", expected);

        printf("my_snprintf return code: %d\n", rrc);
        printf("Recieved:\n%s\n", recieved);
    }
    else
    {
        printf("Success.\n");
    }
}

void test_my_snprintf_rndformat(int *error_counter)
{
    printf("Test my_snprintf. Random format string. ");

#ifdef MYFORMAT
#undef MYFORMAT
#endif
#define MYFORMAT "2412%d42%hdgasga %i 124%hi afsg%s"

    int erc;
    int rrc;
    int cmp;
    char expected[STR_SIZE];
    char recieved[STR_SIZE];

    erc = snprintf(expected, STR_SIZE, MYFORMAT, 1, 2, 3, 4, "5");
    rrc = my_snprintf(recieved, STR_SIZE, MYFORMAT, 1, 2, 3, 4, "5");

    cmp = strcmp(expected, recieved);

    if ((erc != rrc) || (cmp != 0))
    {
        printf("Failure.\n");

        printf("Format string:\n%s\n", MYFORMAT);

        printf("snprintf return code: %d\n", erc);
        printf("Expected:\n%s\n", expected);

        printf("my_snprintf return code: %d\n", rrc);
        printf("Recieved:\n%s\n", recieved);
    }
    else
    {
        printf("Success.\n");
    }
}
