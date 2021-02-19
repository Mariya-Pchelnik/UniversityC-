#include <stdio.h>
#include <conio.h>
#include <math.h>
int main()
{
	double a, b, x, s , y , n, h, m, g;
	int k, f, v, l;

	printf("vvedite a:");
	scanf_s("%lf", &a);
	printf("/nvvedite b:");
	scanf_s("%lf", &b);
	printf("/nvvedite h:");
	scanf_s("%lf", &h);
	printf("/nvvedite n:");
	scanf_s("%lf", &n);

	

	for (y = 0, x = a; x <= b; x = x + h)
	{
		for (s = 0, k = 1; k <= n; k = k + 1)
		{
			f = 2 * k;
			v = (2 * (k*(2 * k - 1)));
			l = k + 1;
			m = -1;
			s += (pow(x, f) / v)*pow(m, l);
		}
		y = x*atan(x) - log(sqrt(1 + pow(x, 2)));
		g = fabs(y - s);

		printf("\n|x=%lf|y=%lf|s=%lf|g=%lf|\n", x, y, s, g);
	}
	
	_getch();
}
