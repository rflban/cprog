#include <stdio.h>
#include <math.h>

double absolute(double num);

int main()
{
    double x;
    double eps;
    double s, d, f;
    double numenator, denominator, koef;
    int rc;
    char buf;

    printf("Enter x: ");
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
    printf("Enter eps: ");
    while(((rc = scanf("%lf%c", &eps, &buf)) != 2 && rc != EOF) || buf != '\n')
    {
        printf("Input error. Try again: ");

        do
        {
            rc = scanf("%c", &buf);
        }
        while(rc != EOF && buf != '\n');
    }

    s = 0;
    d = 1;
    numenator = x;
    denominator = 1.0;
    koef = 1.0;
    while(absolute(d) > eps)
    {
        d = koef * numenator/denominator;
        s += d;
        koef *= -1;
        numenator *= x*x;
        denominator += 2;
    }

    f = atan(x);

    printf("%.4lf\n", s);
    printf("%.4lf\n", f);
    printf("%.4lf\n", absolute(s-f));
    printf("%.4lf\n", absolute((s-f)/f));

}


double absolute(double num)
{
    return num > 0 ? num : -num;
}
