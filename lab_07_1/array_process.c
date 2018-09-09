#include <stdio.h>
#include <stdlib.h>

#include "array_process.h"
#include "exit_control.h"


int read_array_len(FILE* source, int* const len)
{
    int rc;
    numb buf;
    *len = 0;

    while (EOF != (rc = fscanf(source, NUM_FORMAT, &buf)))
    {
        if (rc == 1)
            *len += 1;
        else
            return EXIT_INPUT_ERROR_;
    }

    return EXIT_SUCCESS_;
}

int read_array(FILE* source, numb* const pb_src, numb* const pe_src)
{
    int rc;

    for (numb* pc = pb_src; pc <= pe_src; pc++)
    {
        rc = fscanf(source, NUM_FORMAT, pc);
        if (rc != 1)
            return EXIT_INPUT_ERROR_;
    }

    return EXIT_SUCCESS_;
}

void  print_array(FILE* destination, numb* const pb_dst, numb* const pe_dst)
{
    for (numb* pc = pb_dst; pc <= pe_dst; pc++)
    {
        fprintf(destination, NUM_FORMAT, *pc);
        fprintf(destination, (pc != pe_dst ? " " : ""));
    }
}
