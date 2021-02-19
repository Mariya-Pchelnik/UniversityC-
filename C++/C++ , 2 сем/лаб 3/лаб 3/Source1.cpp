#include <iostream.h>
#include <conio.h>
#include <limits.h>
// Файл с декларацией max(min) целого: INT_MAX (INT_MIN)202
void Sort_Lin(int *, int);
void main(void)
{
	int *a, n, i;
	cout << " \n Input N: ";
	cin >> n;
	a = new int[n]; // Захватываем память для основного массива
	cout << " \n Array ? " << endl;
	// Формируем исходный массив
	for (i = 0; i<n; i++)
	{
		cout << "a[" << i << "]="; cin >> a[i];
	}
	Sort_Lin(a, n); // Вызвали сортировку
	// и распечатали отсортированный массив
	cout << " \n Sort Array : ";
	for (i = 0; i<n; i++) cout << a[i] << " ";
	cout << endl;
	delete[]a;
	getch();
}
//----Функция, реализующая простой линейный выбор ------
void Sort_Lin(int *a, int n)
{
	int i, j, imn, amin, *p;
	p = new int[n]; // Захватываем память для рабочего массива
	for (j = 0; j<n; j++) // Внешний цикл по j
	{
		for (amin = INT_MAX, i = 0; i<n; i++) // Внутренний цикл по i
			if (a[i] < amin)
			{
				imin = i;
				amin = a[i];
			}
		p[j] = amin; // Найденный текущий min в рабочий массив
		a[imin] = INT_MAX; // а на его место max_допустимое целое
	}
	for (j = 0; j<n; j++)
		a[j] = p[j]; // Отсортированный массив на место исходного
	delete[]p;
}