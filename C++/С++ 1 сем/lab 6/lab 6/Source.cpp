#include <stdio.h>
#include <conio.h>
int const n = 3;
int const m = 3
;
void main(void)
{
	int i, j;
	double b[n][m];
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
		{
			printf("Vvedite element [%d][%d]\n", i + 1, j + 1);
			scanf_s("%lf", &b[i][j]);
		}
	

	for (i = 0; i < n; i++){
		for (j = 0; j < m; j++)

		
			printf("%lf ", b[i][j]);
		

		printf("\n");
	}
	
	double s = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) if (i<j)
			s += b[i][j];
			printf("Summa elementov matrici = %f\n", s);
			double p = 1;
			for (i = 0; i < n; i++)
				for (j = 0; j < m; j++) if (i<j)
					p*= b[i][j];
			printf("Proizvedenie elementov matrici = %f\n", p);

	_getch();
}
