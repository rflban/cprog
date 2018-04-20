#include <stdio.h>

#define _RETURN_SUCCESS_ 0
#define _RETURN_NO_DATA_ -1

#define _EXIT_SUCCESS_ 0
#define _EXIT_FAILURE_ -1

#define MAX_ARRAY_LEN 10
#define MAX_INPUT_QUAN 10

void gnome_sort(int * array, int n, int (* comp)(int , int));
void print_int_array(int * array, int array_len);
int array_filling(int * array, int * array_len,
                  int max_array_len, char * array_name);
int comparator(int num1, int num2);


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

    gnome_sort(array, array_len, comparator);

    printf("\nSorted array:\n");
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

int comparator(int num1, int num2)
{
    return num1 > num2;
}

void gnome_sort(int * array, int n, int (*comp)(int, int))
{
    for(int i = 0; i < n; i++)
    {
        if (i != 0 && (*comp)(array[i-1], array[i]))
        {
            array[i-1] ^= array[i];
            array[i] ^= array[i-1];
            array[i-1] ^= array[i];

            i -= 1 + 1;
        }
    }
}
