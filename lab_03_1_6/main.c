#include <stdio.h>
#define NO_DATA_CODE -1

int get_lenOfMaxMonotoneSeq(FILE * file, int * len);

int main(void)
{
    int lenOfMaxMonotoneSeq;
    int procces_rc;

    procces_rc = get_lenOfMaxMonotoneSeq(stdin, &lenOfMaxMonotoneSeq);
    if (procces_rc == 0)
        fprintf(stdout,
                "Lenght of max monotone sequence is %d.\n",
                lenOfMaxMonotoneSeq);
    else if (procces_rc == NO_DATA_CODE)
        fprintf(stdout,
                "Error. Not enougth data.");

    return 0;
}

int get_lenOfMaxMonotoneSeq(FILE * file, int * max_len)
{
    int return_code = 0;
    int num;
    int p_num;
    int len;

    if (fscanf(file, "%d", &num) != 1)
        return_code = NO_DATA_CODE;
    else
    {
        len = 0;
        *max_len = len;

        p_num = num;
        while(fscanf(file, "%d", &num) == 1)
        {
            if (num - p_num <= 0)
            {
                len = 0;
            }
            else
                len += 1;

            p_num = num;
            *max_len = *max_len < len ? len : *max_len;
        }
    }

    return return_code;
}
