#include <stdio.h>
#include <conio.h>
#include <limits.h>
#include <iostream>
using namespace std;
 const int n = 6;
 void Sort_Lin(int *, int);
void main(void)
{
	int i,  *a;
	a = new int[n];
		
		for (i = 0; i < n; i++)
		{
			printf("chislo %d: ", i + 1);
			scanf_s("%d", &a[i]);
		}

		printf(" metod sortirovki: 1- lineinyi vybor, ");
		
		switch (_getch())
		{
		case '1': Sort_Lin(a, n);
			break;
			
		}

	
	for (i = 0; i < 6; i++)
		printf(" %d",a[i]);
	_getch();
	delete[]a;
	}
//сортировка простым линейным выбором
void Sort_Lin(int*a,int n)
{
	int i, j, amin, imin, *p;
	p = new int[];
	for (j = 0; j < n; j++){
		for (amin = INT_MAX, i = 0; i < n; i++)
		{
			if (a[i] < amin)
				a[i] = amin;
			imin = i;
		}
		p[j] = amin;
		a[imin] = INT_MAX;

	}
	for (j = 0; j < n; j++)
	{
		a[j] = p[j];
		
	}// Отсортированный массив на место исходного
	delete[]p;
}
