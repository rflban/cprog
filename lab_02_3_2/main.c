#include <stdio.h>
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
        return 0;
    }

    input_state = double_input(&b, "Enter b: ", INPUT_ERROR_M);
    if (input_state == EOF)
    {
        printf(EOF_ERROR_M);
        return 0;
    }

    input_state = double_input(&c, "Enter c: ", INPUT_ERROR_M);
    if (input_state == EOF)
    {
        printf(EOF_ERROR_M);
        return 0;
    }

    input_state = double_input(&x, "Enter x: ", INPUT_ERROR_M);
    if (input_state == EOF)
    {
        printf(EOF_ERROR_M);
        return 0;
    }

    input_state = double_input(&y, "Enter y: ", INPUT_ERROR_M);
    if (input_state == EOF)
    {
        printf(EOF_ERROR_M);
        return 0;
    }

    result = get_pos(a, b, c, x, y);

    if ( (d_abs(result) >= 0 ) &&  (d_abs(result) <= 0 + EPS))
        printf("Point belongs to straight");
    else if (result > 0)
        printf("Point is upper than straight");
    else
        printf("Point is lower than straight");

    return 0;
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

double get_pos(double a, double b, double c, double x, double y)
{
    return a*x + b*y + c;
}
