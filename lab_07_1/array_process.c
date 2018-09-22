#include <stdio.h>
#include <stdlib.h>

#include "array_process.h"
#include "exit_control.h"


void memory_check(numb* target, const int exit_code)
{
    if (exit_code != EXIT_SUCCESS_)
        free(target);
}

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
    _Bool input_flag = 0;

    for (numb* pc = pb_src; pc <= pe_src; pc++)
    {
        rc = fscanf(source, NUM_FORMAT, pc);
        if (rc != 1)
            return EXIT_INPUT_ERROR_;
        else
            input_flag = 1;
    }
    if (!input_flag)
        return EXIT_EMPTY_INPUT_;

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

int comparator(const void* a, const void* b)
{
    return (*((numb*)a) - *((numb*)b));
}

void mysort(void* base, size_t nitems, size_t size, \
            int (*compar)(const void*, const void*))
{
    char* pb = base;
    char* pe = pb + (nitems - 1)*size;

    while (pb != pe)
    {
        _Bool flag = 0;
        for (char* pc = pb; pc < pe; pc += size)
        {
            if (compar(pc, pc+size) > 0)
            {
                flag = 1;
                for (char* sub_pc = pc; sub_pc < pc+size; sub_pc++)
                {
                    char buf = *sub_pc;
                    *sub_pc = *(sub_pc+size);
                    *(sub_pc+size) = buf;
                }
            }
        }
        if (!flag)
            break;
        pe -= size;
    }
}

int key(const numb* pb_src, const numb* pe_src, numb** pb_dst, numb** pe_dst)
{
    int len;
    const numb* max_pos = (numb*)pb_src;
    const numb* min_pos = (numb*)pb_src;
    
    if (pb_src - pe_src >= 0)
        return EXIT_EMPTY_ARRAY_;
    if (pb_src == NULL || pe_src == NULL)
        return EXIT_NULL_POINTER_REQ_;

    for (const numb* pc = pb_src; pc <= pe_src; pc++)
    {
        if (*pc > *max_pos)
            max_pos = pc;

        if (*pc < *min_pos)
            min_pos = pc;
    }

    if (max_pos - min_pos < 0)
    {
        const numb* tmp = max_pos;
        max_pos = min_pos;
        min_pos = tmp;
    }

    len = max_pos - min_pos - 1;
    if (len <= 0)
        return EXIT_EMPTY_ARRAY_;
    *pb_dst = malloc(len*sizeof(numb));
    if (*pb_dst == NULL)
            return EXIT_NULL_POINTER_REQ_;
    *pe_dst = *pb_dst + len - 1;

    numb* pc_dst = *pb_dst;
    for (const numb *pc_src = min_pos+1; \
         pc_src < max_pos; pc_src++, pc_dst++)
    {
        *pc_dst = *pc_src;
    }

    return EXIT_SUCCESS_;
}
