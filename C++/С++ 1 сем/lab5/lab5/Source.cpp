#include <stdio.h>
#include <conio.h>

void main(void){

	const int n = 8;
	int  i, mas[n],s,index;

	printf("Vvedite 8 chisel\n");

	for (i = 0; i < n; i++)
	{
		printf("chislo %d: ", i + 1);
		scanf_s("%d", &mas[i]);
	}
	int max = mas[0];
	for (i = 1; i<n; i++)	
		if (mas[i]>max)  {
			max = mas[i];
			index = i;
		}
	

	for (s = 0, i = 0; i < n; i++)
		if ((mas[i]>0)&&(index>i)) s += mas[i];


		printf("s=%d ", s);
	_getch();
}
	

	