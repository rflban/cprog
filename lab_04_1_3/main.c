#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define RETURN_SUCCESS_ 0
#define RETURN_INPUT_ERROR_ -2

#define EXIT_SUCCESS_ 0
#define EXIT_EOF_ -1
#define EXIT_FAILURE_ -2

#define MAX_ARRAY_LEN 10

int request_for_number(const char* const request_message, int* num);
int array_filling(int* const array, int array_len, \
                  const char* const array_name);
int geom_mean_of_int_array(const int* const array, \
                           int array_len, double* geom_mean);
void print_input_exit_error(int input_exit_code);


int main(void)
{
    int array[MAX_ARRAY_LEN] = {};
    int array_len;
    double geom_mean;
    int process_rc;

    process_rc = request_for_number("Enter array length: ", &array_len);
    print_input_exit_error(process_rc);

    if (array_len > MAX_ARRAY_LEN)
    {
        printf("Array length overflow.\n"
               "Array length was cutted to %d\n", MAX_ARRAY_LEN);
        array_len = MAX_ARRAY_LEN;
    }

    process_rc = array_filling(array, array_len, "Array");
    print_input_exit_error(process_rc);

    process_rc = geom_mean_of_int_array(array, array_len, &geom_mean);
    if (process_rc == EXIT_SUCCESS_)
        printf("Gemetric mean of this array  is %.2lf\n", geom_mean);
    else
        printf("Positive numbers were not found.\n");

    return RETURN_SUCCESS_;
}

int request_for_number(const char* const request_message, int* num)
{
    int rc;
    int exit_code = EXIT_SUCCESS_;

    printf("%s", request_message);
    rc = scanf("%d", num);

    if (rc == EOF)
        exit_code = EXIT_EOF_;
    else if (rc != 1)
        exit_code = EXIT_FAILURE_;

    return exit_code;
}

int array_filling(int* const array, int array_len, \
                  const char* const array_name)
{
    int rc;
    int exit_code = EXIT_SUCCESS_;

    for(int i = 0; (i < array_len) && (EXIT_SUCCESS_ == exit_code); i++)
    {
        printf("%s[%d]: ", array_name, i);
        rc = scanf("%d", &array[i]);

        if (rc == 0)
            exit_code = EXIT_FAILURE_;
        else if (rc == EOF)
            exit_code = EXIT_EOF_;
    }

    return exit_code;
}

int geom_mean_of_int_array(const int* const array, \
                           int array_len, double* geom_mean)
{
    int exit_code = EXIT_SUCCESS_;
    int n = 0;
    double mult = 1;

    for(int i = 0; i < array_len; i++)
        if (array[i] > 0)
        {
            mult *= array[i];
            n++;
        }

    if (n != 0)
        *geom_mean = exp(log(mult) * 1.0/n);//pow(mult, 1.0/n);
    else
        exit_code = EXIT_FAILURE_;

    return exit_code;
}

void print_input_exit_error(int input_exit_code)
{
    switch (input_exit_code)
    {
        case EXIT_EOF_:
            printf("\nUnexpected EOF.\n\n");
            exit(EOF);
            break;

        case EXIT_FAILURE_:
            printf("\nInput Error.\n\n");
            exit(RETURN_INPUT_ERROR_);
            break;
    }
}
