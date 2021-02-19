#include <stdio.h>
#include <conio.h>
const int n = 8;
double h(int mas[n])
{
	int max, index, i;
	max = mas[0];
	for (i = 1; i<n; i++)
		if (mas[i]>max)  {
			max = mas[i];
			index = i;
		}
			return(index);
		
}
void main(void){

	const int n = 8;
	int  i, mas[n], s;

	printf("Vvedite 8 chisel\n");

	for (i = 0; i < n; i++)
	{
		printf("chislo %d: ", i + 1);
		scanf_s("%d", &mas[i]);
	}
	
	
	


	for (s = 0, i = 0; i < n; i++)
		if ((mas[i]>0) && (h(mas)>i))
			s += mas[i];


	printf("s=%d ", s);
	_getch();
}
