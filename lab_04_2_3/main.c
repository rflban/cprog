#include <stdio.h>
#include <stdlib.h>

#define RETURN_SUCCESS_ 0
#define RETURN_INPUT_ERROR_ -2

#define EXIT_SUCCESS_ 0
#define EXIT_EOF_ -1
#define EXIT_FAILURE_ -2

#define MAX_ARRAY_LEN 10

void print_int_array(const int * const array, const int array_len);
int request_for_number(const char* const request_message, int* const num);
int array_filling(int* const array, const int array_len, \
                  const char* const array_name);
int is_armstrong(const int number);
int get_number_len(int number);
int get_dig_by_pos(int number, const int pos);
int int_power(const int base, int exponent);
void get_armstrong_numbers(const int * const source_array, const int len, \
                           int * const target_array, int* const t_len);
void print_input_exit_error(int const input_exit_code);


int main(void)
{
    int array[MAX_ARRAY_LEN] = {};
    int array_len;
    int new_array[MAX_ARRAY_LEN] = {};
    int new_array_len;
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

    printf("\nReceived array:\n");
    print_int_array(array, array_len);

    get_armstrong_numbers(array, array_len, new_array, &new_array_len);

    if (new_array_len == 0)
    {
        printf("\nNo armstrong numbers.\n");
    }
    else
    {
        printf("\nNew array:\n");
        print_int_array(new_array, new_array_len);
    }

    return RETURN_SUCCESS_;
}

void print_int_array(const int * const array, const int array_len)
{
    for(int i = 0; i < array_len; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int request_for_number(const char* const request_message, int* const num)
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

int array_filling(int* const array, const int array_len, \
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

int int_power(const int base, int exponent)
{
    int number = 1;

    while (exponent > 0)
    {
        number *= base;
        exponent--;
    }

    return number;
}

int get_number_len(int number)
{
    int n = 0;

    while (number > 0)
    {
        n++;
        number /= 10;
    }

    return n;
}

int get_dig_by_pos(int number, const int pos)
{
    int d = 1;

    for (int i = 0; i < pos; i++)
        d *= 10;

    return (number/d)%10;
}

int is_armstrong(const int number)
{
    int number_len = get_number_len(number);
    int check_number = 0;

    for(int i = 0; i < number_len; i++)
        check_number += int_power(get_dig_by_pos(number, i), number_len);

    return number == check_number;
}

void get_armstrong_numbers(const int * const source_array, const int len, \
                           int * const target_array, int* const t_len)
{
    *t_len = 0;

    for(int i = 0; i < len; i++)
    {
        if (source_array[i] > 0 && is_armstrong(source_array[i]))
        {
            target_array[*t_len] = source_array[i];
            *t_len = *t_len + 1;
        }
    }
}

void print_input_exit_error(int const input_exit_code)
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
