#include <stdio.h>
#define DATA_ERROR_CODE -1
#define INPUT_ERROR_CODE -2

int get_arithmetic_mean(FILE * file, double * arithmetic_mean);
int get_closest_to_am(FILE * file, double * closest_to_am, double am);
double double_abs(double num);

int main(int argc, char ** argv)
{
    FILE * file;
    double arithmetic_mean;
    double closest_to_am;
    int procces_rc;

    if (argc != 2)
        fprintf(stdout, "Error. Wrong amount of arguments.");
    else
    {
        file = fopen(argv[1], "r");
        if (!file)
            fprintf(stdout, "Error. No file with data.");
        else
        {
            procces_rc = get_arithmetic_mean(file, &arithmetic_mean);
            if (procces_rc == DATA_ERROR_CODE)
                fprintf(stdout, "Error. No data.");
            else if (procces_rc == INPUT_ERROR_CODE)
                fprintf(stdout, "Error. Wrong input data.");
            else
            {
                rewind(file);
                procces_rc = get_closest_to_am(file,
                                               &closest_to_am,
                                               arithmetic_mean);
                if (procces_rc == DATA_ERROR_CODE)
                    fprintf(stdout, "Error. No data.");
                else if (procces_rc == INPUT_ERROR_CODE)
                    fprintf(stdout, "Error. Wrong input data.");
                else
                {
                    fprintf(stdout,
                            "The closest to arithmetic "
                            "mean of got sequence is %g.\n",
                            closest_to_am);
                }
            }
        }
        fclose(file);
    }

    return 0;
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

    if ((scan_rc = fscanf(file, "%lf", &num)) != 1)
        return_code = DATA_ERROR_CODE;
    else
    {
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
    }

    return return_code;
}

int get_closest_to_am(FILE * file, double * closest_to_am, double am)
{
    int return_code = 0;
    int scan_rc;
    double num;

    if ((scan_rc = fscanf(file, "%lf", &num)) != 1)
        return_code = DATA_ERROR_CODE;
    else
    {
        *closest_to_am = num;
        while ((scan_rc = fscanf(file, "%lf", &num)) == 1)
        {
            if (double_abs(*closest_to_am - am) > double_abs(num - am))
                *closest_to_am = num;
        }

        if (scan_rc != EOF)
            return_code = INPUT_ERROR_CODE;
    }

    return return_code;
}
