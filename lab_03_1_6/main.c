#include <stdio.h>

#define _RETURN_SUCCESS_ 0
#define _RETURN_FAILURE_ -1

#define _EXIT_SUCCESS_ 0
#define _EXIT_NO_DATA_ -1

int get_lenOfMaxMonotoneSeq(FILE * file, int * len);

int main(void)
{
    int lenOfMaxMonotoneSeq;
    int procces_rc;
	int return_code = _RETURN_SUCCESS_;

    procces_rc = get_lenOfMaxMonotoneSeq(stdin, &lenOfMaxMonotoneSeq);
    if (procces_rc == _EXIT_SUCCESS_)
        fprintf(stdout,
                "Lenght of max monotone sequence is %d.\n",
                lenOfMaxMonotoneSeq);
    else if (procces_rc == _EXIT_NO_DATA_)
	{
		return_code = _RETURN_FAILURE_;
        fprintf(stderr,
                "Error. Not enougth data.");
	}
				
    return return_code;
}

int get_lenOfMaxMonotoneSeq(FILE * file, int * max_len)
{
    int return_code = _EXIT_SUCCESS_;
    int num;
    int p_num;
    int len;

    if (fscanf(file, "%d", &num) != 1)
        return_code = _EXIT_NO_DATA_;
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
