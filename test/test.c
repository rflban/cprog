#include <stdio.h> // Подключение заголовочного файла
#include <math.h>
#define ZERO 0

/*
		Ниже
		Находится
		Функция
		main
*/

int main(void)
{
	float a, b, c;
	
	scanf("%f %f %f", &a, &b, &c);
	
	printf("S = %f", ( (a+b)/2.0 * (b-a)/2.0 * tan(c) ));
	
	return ZERO;
}