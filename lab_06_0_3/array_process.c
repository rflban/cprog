#include <stdio.h>

#include "array_process.h"
#include "exit_control.h"


int read_array(FILE * target, int * fa, int * len)
{
    int return_code = EXIT_SUCCESS_;
    int proccess_rc;
    int * pa;

    for(pa = fa; (proccess_rc = fscanf(target, "%d", pa)) != EOF; pa++)
    {
        if (proccess_rc != 1)
        {
            return_code = EXIT_INPUT_ERROR_;
            return return_code;
        }

        if (pa - fa > MAX_ARRAY_LEN)
        {
            return_code = EXIT_ARRAY_OVERFLOW_;
            *len = MAX_ARRAY_LEN;
            return return_code;
        }
    }

    *len = pa - fa;

    return return_code;
}

void get_mentioned_max(int * fa, int * la, int * m_max)
{
    int flag = 0;

    for(int * pa1 = fa, * pa2 = la; pa2 - pa1 > 0; pa1++, pa2--)
    {
        if (!flag || (*m_max < *pa1 + *pa2))
        {
            flag = 1;
            *m_max = *pa1 + *pa2;
        }
    }
}
