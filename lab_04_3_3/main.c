#include <stdio.h>
#include <stdlib.h>

#define RETURN_SUCCESS_ 0
#define RETURN_INPUT_ERROR_ -2

#define EXIT_SUCCESS_ 0
#define EXIT_EOF_ -1
#define EXIT_FAILURE_ -2

#define MAX_ARRAY_LEN 10

void print_int_array(const int * const array, int array_len);
void insert_int_array(int* const array, int number, int pos, int array_len);
int request_for_number(const char* const request_message, int* num);
int array_filling(int* const array, int array_len, \
                  const char* const array_name);
int reverse_int_number(int number);
int get_number_len(int number);
int get_dig_by_pos(int number, int pos);
void insert_rev_numbers(int * const array, int * array_len);
void print_input_exit_error(int input_exit_code);

int main(void)
{
    int array[MAX_ARRAY_LEN] = {};
    int array_len;
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

    insert_rev_numbers(array, &array_len);

    printf("\nUpdated array:\n");
    print_int_array(array, array_len);

    return RETURN_SUCCESS_;
}

void print_int_array(const int * const array, int array_len)
{
    for(int i = 0; i < array_len; i++)
        printf("%d ", array[i]);
    printf("\n");
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

int reverse_int_number(int number)
{
    int reversed_number = 0;
    int number_len = get_number_len(number);

    for (int i = number_len-1, k = 1; i >= 0; i--, k *= 10)
    {
        reversed_number += get_dig_by_pos(number, i)*k;
    }

    return reversed_number;
}

void insert_int_array(int* const array, int number, int pos, int array_len)
{
    for(int i = pos+1, temp = array[pos]; i < array_len+1; i++)
    {
        array[i] ^= temp;
        temp ^= array[i];
        array[i] ^= temp;
    }

    array[pos] = number;
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

int get_dig_by_pos(int number, int pos)
{
    int d = 1;

    for (int i = 0; i < pos; i++)
        d *= 10;

    return (number/d)%10;
}

void insert_rev_numbers(int * const array, int * array_len)
{
    for(int i = 0; i < *array_len; i++)
    {
        if (array[i] > 0)
        {
            insert_int_array(array,
                             reverse_int_number(array[i]),
                             i+1,
                             *array_len);
            i++;
            *array_len += 1;
        }
    }
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
