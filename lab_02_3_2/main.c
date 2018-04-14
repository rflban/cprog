#include <stdio.h>

#define _RETURN_SUCCESS_ 0
#define _RETURN_FAILURE_ -1

#define _EXIT_SUCCESS_ 0

#define EPS 0.0001
#define INPUT_ERROR_M "Input error. Try again: "
#define EOF_ERROR_M "Error. End of file was reached too early."

double d_abs(double number);
double get_pos(double a, double b, double c, double x, double y);
int double_input(double * number, char start_message[], char error_message[]);

int main(void)
{
    double a, b, c;
    double x, y;
    double result;
    int input_state;

    printf("Equation of straight kind of a*x +b*y + c = 0\n\n");

    input_state = double_input(&a, "Enter a: ", INPUT_ERROR_M);
    if (input_state == EOF)
    {
        printf(EOF_ERROR_M);
        return _RETURN_FAILURE_;
    }

    input_state = double_input(&b, "Enter b: ", INPUT_ERROR_M);
    if (input_state == EOF)
    {
        printf(EOF_ERROR_M);
        return _RETURN_FAILURE_;
    }

    input_state = double_input(&c, "Enter c: ", INPUT_ERROR_M);
    if (input_state == EOF)
    {
        printf(EOF_ERROR_M);
        return _RETURN_FAILURE_;
    }

    input_state = double_input(&x, "Enter x: ", INPUT_ERROR_M);
    if (input_state == EOF)
    {
        printf(EOF_ERROR_M);
        return _RETURN_FAILURE_;
    }

    input_state = double_input(&y, "Enter y: ", INPUT_ERROR_M);
    if (input_state == EOF)
    {
        printf(EOF_ERROR_M);
        return _RETURN_FAILURE_;
    }

    result = get_pos(a, b, c, x, y);

    if ( (d_abs(result) >= 0 ) &&  (d_abs(result) <= 0 + EPS))
        printf("Point belongs to straight");
    else if (result > 0)
        printf("Point is upper than straight");
    else
        printf("Point is lower than straight");

    return _RETURN_SUCCESS_;
}

double d_abs(double number)
{
    if (number < 0)
        return -number;
    return number;
}

int double_input(double * number, char start_message[], char error_message[])
{
    int rc;
    char buf;

    printf("%s", start_message);
    while(( ( rc = scanf("%lf%c", number, &buf) ) != 2 || buf != '\n') && rc != EOF)
    {
        printf("%s", error_message);

        do
        {
            rc = scanf("%c", &buf);
        }
        while(rc != EOF && buf != '\n');
    }

    if (rc != EOF)
        return _EXIT_SUCCESS_;
    return rc;
}

double get_pos(double a, double b, double c, double x, double y)
{
    return a*x + b*y + c;
}
