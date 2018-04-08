#include <stdio.h>
#include <math.h>

/*
 * Вариант 0
 *
 * Даны основания и высота равнобедренной трапеции.
 * Найти периметр трапеции.
 *
 * a - малое основание
 * b - большее основание
 * h - высота
 * p - периметр
*/

int main(void)
{
    double a, b, h;
    double p;

    printf("a < b\nEnter a, b, h:\n");
    scanf("%lf%lf%lf", &a, &b, &h);

    p = a + b + 2*sqrt(h*h + (b-a)*(b-a)/4);
    printf("\nP = %.2lf", p);

    return 0;
}
