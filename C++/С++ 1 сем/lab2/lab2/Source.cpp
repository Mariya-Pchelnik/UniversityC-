#include <stdio.h>
#include <conio.h>
#include <math.h>
void main(void) {
	double z1, z2, k, n, a;
	printf("\n enter a: ");
	scanf_s("%lf", &a);
	printf("a=%lf", &a);
	k = sin(2 * a) + sin(5 * a) - sin(3 * a);
	n = cos(a) - cos(3 * a) + cos(5 * a);
	z1 = k / n;
	z2 = tan(3 * a);
	printf("\n answer: z1=%lf, z2=%lf, Press any key...", z1, z2);
	_getch();
}