#include <stdio.h>
#define KOEF_OF_BORNGARDT_INDEX 1.0/240.0
#define CENTIMETERS_OF_METER 100.0

/*
 * Вариант 0.
 *
 * Определить нормальный вес человека (a1) и
 * индекс массы его тела (a2) по формулам:
 * h * t / 240
 * m / (h*h)
 * где h – рост человека (измеряемый в сантиметрах
 * в первой формуле и в метрах - во второй)
 * t – длина окружности грудной клетки (в сантиметрах)
 * m – вес (в килограммах)
*/

int main()
{
    double m, h, t;
    double a1, a2;

    printf("Enter m, h (by centimeters), t:\n");
    scanf("%lf%lf%lf", &m, &h, &t);

    a1 = h*t * KOEF_OF_BORNGARDT_INDEX;
    h /= CENTIMETERS_OF_METER;
    a2 = m/(h*h);
    printf("\n%.4lf %.4lf", a1, a2);

    return 0;
}
