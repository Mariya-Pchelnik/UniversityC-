#include <iostream.h>
#include <conio.h>
#include <limits.h>
// ���� � ����������� max(min) ������: INT_MAX (INT_MIN)202
void Sort_Lin(int *, int);
void main(void)
{
	int *a, n, i;
	cout << " \n Input N: ";
	cin >> n;
	a = new int[n]; // ����������� ������ ��� ��������� �������
	cout << " \n Array ? " << endl;
	// ��������� �������� ������
	for (i = 0; i<n; i++)
	{
		cout << "a[" << i << "]="; cin >> a[i];
	}
	Sort_Lin(a, n); // ������� ����������
	// � ����������� ��������������� ������
	cout << " \n Sort Array : ";
	for (i = 0; i<n; i++) cout << a[i] << " ";
	cout << endl;
	delete[]a;
	getch();
}
//----�������, ����������� ������� �������� ����� ------
void Sort_Lin(int *a, int n)
{
	int i, j, imn, amin, *p;
	p = new int[n]; // ����������� ������ ��� �������� �������
	for (j = 0; j<n; j++) // ������� ���� �� j
	{
		for (amin = INT_MAX, i = 0; i<n; i++) // ���������� ���� �� i
			if (a[i] < amin)
			{
				imin = i;
				amin = a[i];
			}
		p[j] = amin; // ��������� ������� min � ������� ������
		a[imin] = INT_MAX; // � �� ��� ����� max_���������� �����
	}
	for (j = 0; j<n; j++)
		a[j] = p[j]; // ��������������� ������ �� ����� ���������
	delete[]p;
}