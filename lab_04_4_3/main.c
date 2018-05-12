#include <stdio.h>
#include <stdlib.h>

#define RETURN_SUCCESS_ 0
#define RETURN_INPUT_ERROR_ -2

#define EXIT_SUCCESS_ 0
#define EXIT_EOF_ -1
#define EXIT_FAILURE_ -2

#define MAX_ARRAY_LEN 10

void gnome_sort(int * const array, const int n);
void print_int_array(const int * const array, const int array_len);
int request_for_number(const char* const request_message, int* const num);
int array_filling(int* const array, const int array_len, \
                  const char* const array_name);
void print_input_exit_error(int const input_exit_code);


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

    gnome_sort(array, array_len);

    printf("Sorted array:\n");
    print_int_array(array, array_len);

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

void gnome_sort(int * const array, const int n)
{
    for(int i = 0; i < n; i++)
    {
        if (i != 0 && array[i-1] > array[i])
        {
            array[i-1] ^= array[i];
            array[i] ^= array[i-1];
            array[i-1] ^= array[i];

            i -= 1 + 1;
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
