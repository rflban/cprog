#include <stdio.h>

#define DATA_ERROR_CODE -1
#define INPUT_ERROR_CODE -2

int get_arithmetic_mean(FILE * file, double * arithmetic_mean);
int get_closest_to(FILE * file, double compared_num, double * closest_to);
double double_abs(double num);

int main(int argc, char ** argv)
{
    FILE * file;
    double arithmetic_mean;
    double closest_to_am;
    int procces_rc;

    if (argc != 2)
    {
        fprintf(stdout, "Error. Wrong amount of arguments.");
        goto END;
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stdout, "Error. File does not exist.");
        goto END;
    }

    procces_rc = get_arithmetic_mean(file, &arithmetic_mean);
    if (procces_rc == DATA_ERROR_CODE)
    {
        fprintf(stdout, "Error. No data.");
        goto FILE_CLOSING;
    }
    else if (procces_rc == INPUT_ERROR_CODE)
    {
        fprintf(stdout, "Error. Wrong input data.");
        goto FILE_CLOSING;
    }

    (void)fseek(file, 0, SEEK_SET); //rewind(file);

    procces_rc = get_closest_to(file,
                                arithmetic_mean,
                                &closest_to_am);
    if (procces_rc == DATA_ERROR_CODE)
    {
        fprintf(stdout, "Error. No data.");
        goto FILE_CLOSING;
    }
    else if (procces_rc == INPUT_ERROR_CODE)
    {
        fprintf(stdout, "Error. Wrong input data.");
        goto FILE_CLOSING;
    }

    fprintf(stdout,
            "The closest to arithmetic "
            "mean of got sequence is %g.\n",
            closest_to_am);

    FILE_CLOSING:
    fclose(file);

    END: return 0;
}

double double_abs(double num)
{
    if (num < 0)
        return -num;
    return num;
}

int get_arithmetic_mean(FILE * file, double * arithmetic_mean)
{
    int return_code = 0;
    int scan_rc;
    int n = 0;
    double sum = 0;
    double num;

    if ((scan_rc = fscanf(file, "%lf", &num)) == EOF)
    {
        return_code = DATA_ERROR_CODE;
        goto END;
    }
    else if (scan_rc != 1)
    {
        return_code = INPUT_ERROR_CODE;
        goto END;
    }

    n++;
    sum += num;

    while ((scan_rc = fscanf(file, "%lf", &num)) == 1)
    {
        sum += num;
        n++;
    }

    if (scan_rc != EOF)
        return_code = INPUT_ERROR_CODE;
    else
        *arithmetic_mean = sum/n;

    END: return return_code;
}

int get_closest_to(FILE * file, double compared_num, double * closest_to)
{
    int return_code = 0;
    int scan_rc;
    double num;

    if ((scan_rc = fscanf(file, "%lf", &num)) == EOF)
    {
        return_code = DATA_ERROR_CODE;
        goto END;
    }
    else if (scan_rc != 1)
    {
        return_code = INPUT_ERROR_CODE;
        goto END;
    }

    *closest_to = num;

    while ((scan_rc = fscanf(file, "%lf", &num)) == 1)
    {
        if (
                double_abs(*closest_to - compared_num) >
                double_abs(num - compared_num)
           )
            *closest_to = num;
    }

    if (scan_rc != EOF)
        return_code = INPUT_ERROR_CODE;

    END: return return_code;
}
