/* Задача 2. Вариант 5.
Найти разницу между максимальным и минимальным числом
последовательности. Пример: 1 2 3 4 5 -> 5 - 1 -> 4

Конец ввода обозначается символом конца файла или
любым другим нецифровым, кроме пробела или переноса строки.
*/

#include <stdio.h>

#define _EXIT_SUCCES_ 0

int get_max(int num1, int num2);
int get_min(int num1, int num2);

int main(void)
{
    int max_num, min_num;
    int f_max = 0, f_min = 0;
    int cur_num;

    printf("Enter sequence: ");
    while(scanf("%d", &cur_num) == 1)
    {
        if (0 == f_max)
        {
            f_max = 1;
            max_num = cur_num;
        }
        else
            max_num = get_max(cur_num, max_num);

        if (0 == f_min)
        {
            f_min = 1;
            min_num = cur_num;
        }
        else
            min_num = get_min(cur_num, min_num);
    }

    if (f_max == 1 && f_min == 1)
        printf("%d", (max_num-min_num));

    return _EXIT_SUCCES_;
}

int get_max(int num1, int num2)
{
    if (num1 > num2)
        return num1;
    return num2;
}

int get_min(int num1, int num2)
{
    if (num1 < num2)
        return num1;
    return num2;
}
