#include <stdio.h>
#define BWATER_COST 45
#define BOTTLE_COST 20

/*
 * Вариант 0.
 *
 * Бутылка воды стоит 45 копеек.
 * Пустые бутылки сдаются по 20 копеек,
 * и на полученные деньги опять покупается вода.
 * Какое наибольшее количество бутылок воды можно купить,
 * имея некоторую сумму денег S копеек.
*/

int main()
{
    int s, cnt = 0;

    printf("S = ");
    scanf("%d", &s);

    while(s >= BWATER_COST)
    {
        cnt += s/BWATER_COST;
        s = s%BWATER_COST + (s/BWATER_COST)*BOTTLE_COST;
    }

    printf("\n%d", cnt);

    return 0;
}
