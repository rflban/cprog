#include <stdio.h>

#define _RETURN_SUCCESS_ 0
#define _RETURN_NO_DATA_ -1

#define _EXIT_SUCCESS_ 0
#define _EXIT_FAILURE_ -1

#define MAX_ARRAY_LEN 10
#define MAX_INPUT_QUAN 10

void print_int_array(int * array, int array_len);
int array_filling(int * array, int * array_len,
                  int max_array_len, char * array_name);
int is_armstrong(int number);
int get_number_len(int number);
int get_dig_by_pos(int number, int pos);
int int_power(int base, int exponent);


int main(void)
{
    int return_code = _RETURN_SUCCESS_;
    int array[MAX_ARRAY_LEN] = {};
    int array_len;
    int new_array[MAX_ARRAY_LEN] = {};
    int new_array_len = 0;
    int proccess_rc;

    proccess_rc = array_filling(array, &array_len, MAX_INPUT_QUAN, "Array");
    if (proccess_rc == _EXIT_FAILURE_)
    {
        printf("\nArray is empty.");
        return_code = _RETURN_NO_DATA_;
        goto END;
    }

    printf("\nReceived array:\n");
    print_int_array(array, array_len);

    for(int i = 0; i < array_len; i++)
    {
        if (array[i] > 0 && is_armstrong(array[i]))
        {
            new_array[new_array_len] = array[i];
            new_array_len++;
        }
    }

    if (new_array_len == 0)
    {
        printf("\nNo armstrong numbers.");
    }
    else
    {
        printf("\nNew array:\n");
        print_int_array(new_array, new_array_len);
    }

    END: return return_code;
}

void print_int_array(int * array, int array_len)
{
    for(int i = 0; i < array_len; i++)
        printf("%d ", array[i]);
}

int array_filling(int * array, int * array_len,
                  int max_array_len, char * array_name)
{
    int rc = 0;
    int exit_code = _EXIT_FAILURE_;

    if (max_array_len != 0)
        rc = 1;

    *array_len = 0;
    for(int i = 0; (i < max_array_len) && rc == 1; i++)
    {
        printf("%s[%d]: ", array_name, i);
        rc = scanf("%d", &array[i]);

        if (rc == 1)
        {
            exit_code = _EXIT_SUCCESS_;
            *array_len += 1;
        }
    }

    return exit_code;
}

int int_power(int base, int exponent)
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

int get_dig_by_pos(int number, int pos)
{
    int d = 1;

    for (int i = 0; i < pos; i++)
        d *= 10;

    return (number/d)%10;
}

int is_armstrong(int number)
{
    int number_len = get_number_len(number);
    int check_number = 0;

    for(int i = 0; i < number_len; i++)
        check_number += int_power(get_dig_by_pos(number, i), number_len);

    return number == check_number;
}
