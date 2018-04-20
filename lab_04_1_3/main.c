#include <stdio.h>
#include <math.h>

#define _RETURN_SUCCESS_ 0
#define _RETURN_NO_DATA_ -1

#define _EXIT_SUCCESS_ 0
#define _EXIT_FAILURE_ -1

#define MAX_ARRAY_LEN 10
#define MAX_INPUT_QUAN 10

int array_filling(int * array, int * array_len,
                  int max_array_len, char * array_name);
int geom_mean_of_int_array(int * array, int array_len, double * geom_mean);


int main(void)
{
    int array[MAX_ARRAY_LEN] = {};
    int array_len;
    double geom_mean;
    int return_code = _RETURN_SUCCESS_;
    int proccess_rc;

    proccess_rc = array_filling(array, &array_len, MAX_INPUT_QUAN, "Array");
    if (proccess_rc == _EXIT_FAILURE_)
    {
        printf("\nArray is empty.");
        return_code = _RETURN_NO_DATA_;
        goto END;
    }

    proccess_rc = geom_mean_of_int_array(array, array_len, &geom_mean);
    if (proccess_rc == _EXIT_SUCCESS_)
        printf("\nGemetric mean of this array  is %.2lf", geom_mean);
    else
        printf("\nPositive numbers were not found.");

    END: return return_code;
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

int geom_mean_of_int_array(int * array, int array_len, double * geom_mean)
{
    int exit_code = _EXIT_SUCCESS_;
    int n = 0;
    double mult = 1;

    for(int i = 0; i < array_len; i++)
        if (array[i] > 0)
        {
            mult *= array[i];
            n++;
        }

    if (n != 0)
        *geom_mean = pow(mult, 1.0/n);
    else
        exit_code = _EXIT_FAILURE_;

    return exit_code;
}
