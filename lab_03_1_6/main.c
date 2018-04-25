#include <stdio.h>

#define RETURN_SUCCESS_ 0
#define RETURN_FAILURE_ -1
#define EXIT_SUCCESS_ 0
#define EXIT_NO_DATA_ -1

int get_len_of_max_monotone_seq(FILE * file, int * len);

int main(void)
{
    int len_of_max_monotone_seq;
    int procces_rc;
    int return_code = RETURN_SUCCESS_;

    procces_rc = get_len_of_max_monotone_seq(stdin, &len_of_max_monotone_seq);
    if (procces_rc == EXIT_SUCCESS_)
        fprintf(stdout,
                "Lenght of max monotone sequence is %d.\n",
                len_of_max_monotone_seq);
    else if (procces_rc == EXIT_NO_DATA_)
    {
        return_code = RETURN_FAILURE_;
        fprintf(stderr,
                "Error. Not enougth data.");
    }
                
    return return_code;
}

int get_len_of_max_monotone_seq(FILE * file, int * max_len)
{
    int return_code = EXIT_SUCCESS_;
    int num;
    int p_num;
    int len;

    if (fscanf(file, "%d", &num) != 1)
        return_code = EXIT_NO_DATA_;
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
