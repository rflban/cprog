#include <stdio.h>

double get_pos(double a, double b, double c, double x, double y);

int main(void)
{
    double a, b, c;
    double x, y;
    double result;
    int rc;
    char buf;

    printf("Equation of straight kind of a*x +b*y + c = 0\n");

    printf("Enter a: ");
    while(((rc = scanf("%lf%c", &a, &buf)) != 2 && rc != EOF) || buf != '\n')
    {
        printf("Input error. Try again: ");

        do
        {
            rc = scanf("%c", &buf);
        }
        while(rc != EOF && buf != '\n');
    }

    buf = '3';
    printf("Enter b: ");
    while(((rc = scanf("%lf%c", &b, &buf)) != 2 && rc != EOF) || buf != '\n')
    {
        printf("Input error. Try again: ");

        do
        {
            rc = scanf("%c", &buf);
        }
        while(rc != EOF && buf != '\n');
    }

    buf = '3';
    printf("Enter c: ");
    while(((rc = scanf("%lf%c", &c, &buf)) != 2 && rc != EOF) || buf != '\n')
    {
        printf("Input error. Try again: ");

        do
        {
            rc = scanf("%c", &buf);
        }
        while(rc != EOF && buf != '\n');
    }

    buf = '3';
    printf("Enter x of point: ");
    while(((rc = scanf("%lf%c", &x, &buf)) != 2 && rc != EOF) || buf != '\n')
    {
        printf("Input error. Try again: ");

        do
        {
            rc = scanf("%c", &buf);
        }
        while(rc != EOF && buf != '\n');
    }

    buf = '3';
    printf("Enter y of point: ");
    while(((rc = scanf("%lf%c", &y, &buf)) != 2 && rc != EOF) || buf != '\n')
    {
        printf("Input error. Try again: ");

        do
        {
            rc = scanf("%c", &buf);
        }
        while(rc != EOF && buf != '\n');
    }

    result = get_pos(a, b, c, x, y);

    if (result == 0)
        printf("Point belongs to straight");
    else if (result > 0)
        printf("Point is upper than straight");
    else
        printf("Point is lower than straight");

    return 0;
}

double get_pos(double a, double b, double c, double x, double y)
{
    return a*x + b*y + c;
}
