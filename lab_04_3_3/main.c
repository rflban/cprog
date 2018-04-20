#include <stdio.h>

#define _RETURN_SUCCESS_ 0
#define _RETURN_NO_DATA_ -1

#define _EXIT_SUCCESS_ 0
#define _EXIT_FAILURE_ -1

#define MAX_ARRAY_LEN 20
#define MAX_INPUT_QUAN 10

void print_int_array(int * array, int array_len);
void insert_int_array(int *array, int number, int pos, int array_len);
int array_filling(int * array, int * array_len,
                  int max_array_len, char * array_name);
int reverse_int_number(int number);
int get_number_len(int number);
int get_dig_by_pos(int number, int pos);


int main(void)
{
    int return_code = _RETURN_SUCCESS_;
    int array[MAX_ARRAY_LEN] = {};
    int array_len;
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
        if (array[i] > 0)
        {
            insert_int_array(array,
                             reverse_int_number(array[i]),
                             i+1,
                             array_len);
            i++;
            array_len++;
        }
    }

    printf("\nUpdated array:\n");
    print_int_array(array, array_len);

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

void insert_int_array(int *array, int number, int pos, int array_len)
{
    for(int i = pos+1, temp = array[pos]; i < array_len+1; i++)
    {
        array[i] ^= temp;
        temp ^= array[i];
        array[i] ^= temp;
        /*int buf = array[i];
        array[i] = temp;
        temp = buf;*/
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
