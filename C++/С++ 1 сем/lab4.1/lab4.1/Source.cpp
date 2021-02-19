#include <conio.h>
#include <stdio.h>
#include <math.h>
double sum( double x, double h)
{
	double y;
		y = x*atan(x) - log(sqrt(1 + pow(x, 2)));
	return y;
}
double sum2(double x, double n)
{
	double  m,  s;
	int k, f, v, l;

		s = 0;
		k = 1;

		while (k <= n){

			f = 2 * k;
			v = (2 * (k*(2 * k - 1)));
			l = k + 1;
			m = -1;


			s += (pow(x, f) / v)*pow(m, l);

			k = k + 1;
		}


		return s;


}

void main(void)
	{

		double a, b, h, n, g, c, t, x;
		
		printf("vvedite a:");
		scanf_s("%lf", &a);
		printf("vvedite b:");
		scanf_s("%lf", &b);
		printf("vvedite h:");
		scanf_s("%lf", &h);
		printf("vvedite n:");
		scanf_s("%lf", &n);

		
		
		for (x = a; x <= b; x = x + h)
		{
			c = sum(x, h);
			t = sum2(x, n);
			g = fabs(c - t);
			printf("\n|c=%lf|t=%lf|g=%lf|\n", c, t, g);
		}
		_getch();

	