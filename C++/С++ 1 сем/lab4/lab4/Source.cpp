
#include <conio.h>
#include <math.h>
float sum(float y)
{
	float a, b, x, s, n, h, m, g, c, t;
	int k, f, v, l;
	y = 0;
	x = a;
	while (x <= b)
		y = x*atan(x) - log(sqrt(1 + pow(x, 2)));
	x = x + h;
	return y;
}
float sum2(double s)
{
	float a, b, x, y, n, h, m, g, c, t;
	int k, f, v, l;
	while (x <= b)
	{


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
		x = x + h;
		return s;
	}

void main()
{
	
	float a, b, x, s, y, n, h, m, g, c,t;
	int k, f, v, l;
	printf("vvedite a:");
	scanf_s("%f", &a);
	printf("vvedite b:");
	scanf_s("%f", &b);
	printf("vvedite h:");
	scanf_s("%f", &h);
	printf("vvedite n:");
	scanf_s("%f", &n);


	c = sum;
	t = sum2;

	g = fabs(c - t);

	printf("\n|x=%f|c=%f|t=%f|g=%f|\n", x, y, s);
	
}
	
	/*y = 0;
	x = a;
	while(x <= b)
	{
		
	
		s = 0;
		k = 1;
		
		while ( k <= n){
			
			f = 2 * k;
			v = (2 * (k*(2 * k - 1)));
			l = k + 1;
			m = -1;
		

			s += (pow(x, f) / v)*pow(m, l);

			k = k + 1;
		}

	c = sum(y);
	t = sum(s);
		g = fabs(y - s);
		y = x*atan(x) - log(sqrt(1 + pow(x, 2)));
		x = x + h;
		x = x + h;

	}

	_getch();
}*/