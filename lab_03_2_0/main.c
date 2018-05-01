#include <stdio.h>
#include <stdlib.h>
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
#define EXIT_USAGE_ERROR_ -3
#define EXIT_OPEN_ERROR_ -4
#define EXIT_CLOSE_ERROR_ -5
#define EXIT_SEEK_ERROR_ -6

int get_arithmetic_mean(FILE * file, double * arithmetic_mean);
int get_closest_to(FILE * file, double compared_num, double * closest_to);
double double_abs(double num);
void show_example();
void print_procces_error(int exit_code, FILE * err_output);

int main(int argc, char ** argv)
{
    FILE * file;
    double arithmetic_mean;
    double closest_to_am;
    int procces_rc;

    if (argc != 2)
    {
        procces_rc = EXIT_USAGE_ERROR_;
        print_procces_error(procces_rc, stderr);
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        procces_rc = EXIT_OPEN_ERROR_;
        print_procces_error(procces_rc, stderr);
    }

    procces_rc = get_arithmetic_mean(file, &arithmetic_mean);
    print_procces_error(procces_rc, stderr);

    if (fseek(file, 0, SEEK_SET) != 0)
    {
        procces_rc = EXIT_SEEK_ERROR_;
        print_procces_error(procces_rc, stderr);
    }

    procces_rc = get_closest_to(file,
                                arithmetic_mean,
                                &closest_to_am);
    print_procces_error(procces_rc, stderr);

    fprintf(stdout,
            "The closest to arithmetic "
            "mean of got sequence is %g.\n",
            closest_to_am);


    if (fclose(file) != 0)
    {
        procces_rc = EXIT_CLOSE_ERROR_;
        print_procces_error(procces_rc, stderr);
    }

    return RETURN_SUCCESS_;
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

void print_procces_error(int exit_code, FILE * err_output)
{
    switch (exit_code)
    {        
        case EXIT_DATA_ERROR_:
            fprintf(err_output,
                    "Error. Not enough data.");
            exit(RETURN_DATA_ERROR_);
            break;
            
        case EXIT_INPUT_ERROR_:
            fprintf(err_output, "Error. Wrong input data.");
            exit(RETURN_INPUT_ERROR_);
            break;
            
        case EXIT_USAGE_ERROR_: 
            show_example();
            fprintf(err_output, "Error. Wrong amount of arguments.");
            exit(RETURN_USAGE_ERROR_);
            break;
            
        case EXIT_OPEN_ERROR_:
            fprintf(err_output, "Error. Could not open file:\n%s.",
                    strerror(errno));
            exit(RETURN_OPEN_ERROR_);
            break;
            
        case EXIT_CLOSE_ERROR_:
            fprintf(err_output, "File closing error");
            exit(RETURN_CLOSE_ERROR_);
            break;
            
        case EXIT_SEEK_ERROR_:
            fprintf(err_output, "File reading error");
            exit(RETURN_SEEK_ERROR_);
            break;
    }
}