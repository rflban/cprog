#include <stdio.h>
#include <math.h>
#define INPUT_ERROR_M "Input error. Try again: "
#define EOF_ERROR_M "Error. End of file was reached too early."

double d_abs(double num);
double aproximate_atan(double x, double eps);

int double_input(double * number, char start_message[], char error_message[]);

int main(void)
{
    double x;
    double eps;
    double apr_f, f;
    int input_state;

    input_state = double_input(&x, "Enter x: ", INPUT_ERROR_M);
    if (input_state == EOF)
    {
        printf(EOF_ERROR_M);
        return 0;
    }

    input_state = double_input(&eps, "Enter Epsilon: ", INPUT_ERROR_M);
    if (input_state == EOF)
    {
        printf(EOF_ERROR_M);
        return 0;
    }

    apr_f = aproximate_atan(x, eps);
    f = atan(x);

    printf("%.4lf\n", apr_f);
    printf("%.4lf\n", f);
    printf("%.4lf\n", d_abs(apr_f-f));
    printf("%.4lf\n", d_abs((apr_f-f)/f));

    return 0;
}

int double_input(double * number, char start_message[], char error_message[])
{
    int rc;
    char buf;

    printf(start_message);
    while(( ( rc = scanf("%lf%c", number, &buf) ) != 2 || buf != '\n') && rc != EOF)
    {
        printf(error_message);

        do
        {
            rc = scanf("%c", &buf);
        }
        while(rc != EOF && buf != '\n');
    }

    if (rc == EOF)
        return EOF;
    return 0;
}

double d_abs(double num)
{
    return num > 0 ? num : -num;
}

double aproximate_atan(double x, double eps)
{
    double s = 0;
    double d = 1;
    double numenator = x;
    double denominator = 1.0;
    double koef = 1.0;
    while(d_abs(d) >= eps)
    {
        d = koef * numenator/denominator;
        s += d;
        koef *= -1;
        numenator *= x*x;
        denominator += 2;
    }

    return s;
}
