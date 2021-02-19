#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void main(void)  {
	double x, y, f;
	puts("Введите значения x и y");
	scanf_s("%lf %lf", &x, &y);
	if ((x>0) && (y<0))  {
		f = (x + tan(3 * y)) / (5 - 2 * x);
		puts("F=(x+tg3y)/(5-2x)");
	}
	else if ((x<0) && (y>0))   {
		f = (pow(x, 2. / 3) > cos(y*y)) ? pow(x, 2. / 3) : cos(y*y);       	  		
		puts("F=max(pow(x,2/3),cos(y*y))");
	}
	else if ((x>0) && (y>0))    {
		f = (0.5*x - 2 * pow(sin(y), 2) < exp(y)) ? 0.5*x - 2 * pow(sin(y), 2) : exp(y);  	  	puts("F=min(0.5x-2*pow(sin(y),2),exp(y))");
	}
	else  {
		puts("Функция F не определена !");
		exit(1);          	// Принудительное завершение программы
	}
	printf("ОТВЕТ: F = %lf ", f);
}
