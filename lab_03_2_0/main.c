#include <stdio.h>
#include <errno.h>
#include <string.h>

#define RETURN_SUCCESS_ 0
#define RETURN_DATA_ERROR_ -1
#define RETURN_INPUT_ERROR_ -2
#define RETURN_USAGE_ERROR_ -3
#define RETURN_OPEN_ERROR_ -4
#define RETURN_CLOSE_ERROR_ -5
#define RETURN_SEEK_ERROR_ -6
#define EXIT_SUCCESS_ 0
#define EXIT_DATA_ERROR_ -1
#define EXIT_INPUT_ERROR_ -2

int get_arithmetic_mean(FILE * file, double * arithmetic_mean);
int get_closest_to(FILE * file, double compared_num, double * closest_to);
double double_abs(double num);
void show_example();

int main(int argc, char ** argv)
{
    FILE * file;
    double arithmetic_mean;
    double closest_to_am;
    int procces_rc;
    int return_code = RETURN_SUCCESS_;

    if (argc != 2)
    {
        return_code = RETURN_USAGE_ERROR_;
        show_example();
        fprintf(stderr, "Error. Wrong amount of arguments.");
        return return_code;
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        return_code = RETURN_OPEN_ERROR_;
        fprintf(stderr, "Error. Could not open `%s`:\n%s.",
                argv[1],
                strerror(errno));
        return return_code;
    }

    procces_rc = get_arithmetic_mean(file, &arithmetic_mean);
    if (procces_rc == EXIT_DATA_ERROR_)
    {
        return_code = RETURN_DATA_ERROR_;
        fprintf(stderr, "Error. No data.");
        return return_code;
    }
    else if (procces_rc == EXIT_INPUT_ERROR_)
    {
        return_code = RETURN_INPUT_ERROR_;
        fprintf(stderr, "Error. Wrong input data.");
        return return_code;
    }

    if (fseek(file, 0, SEEK_SET) != 0)
    {
        fprintf(stderr, "File reading error");
        return_code = RETURN_SEEK_ERROR_;
        return return_code;
    }

    procces_rc = get_closest_to(file,
                                arithmetic_mean,
                                &closest_to_am);
    if (procces_rc == EXIT_DATA_ERROR_)
    {
        return_code = RETURN_DATA_ERROR_;
        fprintf(stderr, "Error. No data.");
        return return_code;
    }
    else if (procces_rc == EXIT_INPUT_ERROR_)
    {
        return_code = RETURN_INPUT_ERROR_;
        fprintf(stderr, "Error. Wrong input data.");
        return return_code;
    }

    fprintf(stdout,
            "The closest to arithmetic "
            "mean of got sequence is %g.\n",
            closest_to_am);


    if (fclose(file) != 0)
    {
        fprintf(stderr, "File closing error");
        return_code = RETURN_CLOSE_ERROR_;
        return return_code;
    }

    return return_code;
}

void show_example()
{
    printf("\nexample.exe <source_file>\n");
}

double double_abs(double num)
{
    if (num < 0)
        return -num;
    return num;
}

int get_arithmetic_mean(FILE * file, double * arithmetic_mean)
{
    int return_code = EXIT_SUCCESS_;
    int scan_rc;
    int n = 0;
    double sum = 0;
    double num;

    if ((scan_rc = fscanf(file, "%lf", &num)) == EOF)
    {
        return_code = EXIT_DATA_ERROR_;
        return return_code;
    }
    else if (scan_rc != 1)
    {
        return_code = EXIT_INPUT_ERROR_;
        return return_code;
    }

    n++;
    sum += num;

    while ((scan_rc = fscanf(file, "%lf", &num)) == 1)
    {
        sum += num;
        n++;
    }

    if (scan_rc != EOF)
        return_code = EXIT_INPUT_ERROR_;
    else
        *arithmetic_mean = sum/n;

    return return_code;
}

int get_closest_to(FILE * file, double compared_num, double * closest_to)
{
    int return_code = EXIT_SUCCESS_;
    int scan_rc;
    double num;

    if ((scan_rc = fscanf(file, "%lf", &num)) == EOF)
    {
        return_code = EXIT_DATA_ERROR_;
        return return_code;
    }
    else if (scan_rc != 1)
    {
        return_code = EXIT_INPUT_ERROR_;
        return return_code;
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
        return_code = EXIT_INPUT_ERROR_;

    return return_code;
}