/* Задача 2. Вариант 5.
Найти разницу между максимальным и минимальным числом 
последовательности. Пример: 1 2 3 4 5 -> 5 - 1 -> 4

Для выхода из программы нужно ввести конец файла
*/

#include <stdio.h>

#define _EXIT_SUCCES_ 0

int main(void)
{
	int max_num, min_num;
	int f_max = 0, f_min = 0;
	int cur_num;
	
	while(scanf("%d", &cur_num) == 1)
	{
		if (0 == f_max || max_num < cur_num)
		{
			f_max = 1;
			max_num = cur_num;
		}
		
		if (0 == f_min || min_num > cur_num)
		{
			f_min = 1;
			min_num = cur_num;
		}
	}
	
	printf("%d", (max_num-min_num));
	
	return _EXIT_SUCCES_;
}