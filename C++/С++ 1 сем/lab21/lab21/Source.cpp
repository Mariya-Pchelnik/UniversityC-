#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void main(void)  {
	double x, y, z;
	puts("vvedite z");
	scanf_s("%lf", &z);
	if (z > 0)   { 
		x = -3 * z;
		y = x*(sin(x) + exp(-x - 3));
		puts("y=(x*(sin(x)+exp(-x-3)), z>0");
	}
	else     {
		x =( pow(z, 2));
		y = (x*sin(x) + exp(-x - 3));
		puts("y = (x*(sin(x)+exp(-x-3)),z<=0;");
	}
	printf("otvet: y = %lf ", y);
	_getch();
}

