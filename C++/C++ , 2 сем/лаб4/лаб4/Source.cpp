#include <stdio.h>
#include <conio.h>
#include <limits.h>
#include <iostream>
int const n=4;
using namespace std;


void Sort_Lin(int *, int);
void Sort_Bubble(int *a, int n);
void Sort_Chelnochnaya( int *a, int n);
void main(void)
{
	setlocale(LC_ALL, "Russian");
	int i, *a, t;
	
	a = new int[n];

	for (i = 0; i< n; i++)
	{
		printf("число %d: ", i + 1);
		scanf_s("%d", &a[i]);
	}
	for (t = 0; t < 3; t++)
	{printf("\nвыберете метод сортировки: 1-линейный выбор,2- метод пузырька,3-челночная сортировка\n");
	     switch (_getch())

		{
		case '1':Sort_Lin(a, n);
			break;
		case '2':Sort_Bubble(a, n);
			break;
		case '3': Sort_Chelnochnaya(a, n);
		}


		for (i = 0; i < n; i++)
			printf(" %d", a[i]);
		_getch();
	}
	delete[]a;
}
//сортировка простым линейным выбором
void Sort_Lin(int *a, int n)
{
	int i, j, imin, amin, *p;
	p = new int[n]; 
	for (j = 0; j<n; j++) 
	{
		for (amin = INT_MAX, i = 0; i<n; i++) 
			if (a[i] < amin)
			{
				imin = i;
				amin = a[i];
			}
		p[j] = amin; 
		a[imin] = INT_MAX; 
	}
	for (j = 0; j<n; j++)
		a[j] = p[j]; // Отсортированный массив на место исходного
	delete[]p;
}
//сортировка пузырьком
void Sort_Bubble(int *a, int n)
{ int i, j, r;
for (i = 0; i < n; i++)
	for (j = 0; j < (n - 1) - i; j++)
		if (a[j] < a[j + 1])
		{
			r = a[j];
			a[j] = a[j + 1];
			a[j + 1] = r;
		} }
//челночная сортировка
void Sort_Chelnochnaya(int *a, int n)
{
	int r, i, j,  max, i_max;
	for (i = 0; i < n; i++)
	{
		max = a[i];
		i_max = i;
		for (j = i + 1; j < n;j++)
			if (max<a[j])
			{
				max = a[j];
				i_max = j;
			}
		r = a[i];
		a[i] = max;
		a[i_max] = r;
	}
}