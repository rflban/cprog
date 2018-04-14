/* Задача 1. Вариант 7.
Определить пару рядом стоящих цифр образующих максимальное 
произведение. Пример: 12345 -> 20, 132 -> 6
*/

#include <stdio.h>

#define _EXIT_SUCCES_ 0

int get_num_len(int num);
int get_dig_by_pos(int num, int pos);

int main(void)
{
	int number;
	int number_len;
	int max_mul = -1;
	
	scanf("%d", &number);
	number_len = get_num_len(number);
	
	for(int i = 0; i < number_len-1; i++)
	{
		int cur_mul = get_dig_by_pos(number, i) * get_dig_by_pos(number, i+1);
		
		if (cur_mul > max_mul)
			max_mul = cur_mul;
	}
	
	printf("%d", max_mul);
	
	return _EXIT_SUCCES_;
}

int get_num_len(int num)
{
	int n = 0;
	
	while (num > 0)
	{
		n++;
		num /= 10;
	}
	
	return n;
}

int get_dig_by_pos(int num, int pos)
{
	int d = 1;
	
	for (int i = 0; i < pos; i++)
		d *= 10;
	
	return (num/d)%10;
}