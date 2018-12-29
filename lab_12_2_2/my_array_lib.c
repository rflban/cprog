#include "my_array_lib.h"

void fill_fiboncci(int *array, int array_len)
{
    int present_number = 0;
    int ensuing_number = 1;

    for (int i = 0; i < array_len; i++)
    {
        array[i] = present_number;

        present_number ^= ensuing_number;
        ensuing_number ^= present_number;
        present_number ^= ensuing_number;

        ensuing_number += present_number;
    }
}

void copy_first_entries(int *array1, int array1_len, int *array2, int array2_len)
{
    int flag_repeat;

    for (int i = 0, j = 0; (i < array1_len) && (j < array2_len); i++)
    {
        flag_repeat = 0;

        for (int k = 0; k < j; k++)
        {
            if (array1[i] == array2[k])
            {
                flag_repeat = 1;
            }
        }

        if (!flag_repeat)
        {
            array2[j] = array1[i];
            j++;
        }
    }
}