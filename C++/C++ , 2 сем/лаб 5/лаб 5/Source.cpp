#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;
// ���������� ����������
long double fact(int N)
{
	if (N < 0)
		return 0;
	if (N == 0)
		return 1;
	else
		return N * fact(N - 1);
}
int Sum(int i, int A[], int n)
{
	/*if (i == n - 1)
		return A[i];
	else
		return A[i] + Sum(i + 1, A, n);*/
	if( i < n)
		return A[i] + Sum(i + 1, A, n);
	else return 0;
	

}
int MaxDiv(int r, int k)
{
	if (r == k)
		return r;
	else
		if (r>k)
			return MaxDiv(r - k, k);
		else
			return MaxDiv(r, k- r);
}
void main(void)
{
	int N,t,n,i,r,k;
	
	
	setlocale(0, "");
	for (t = 0; t < 3;t++)
	{
		printf("/n �������� ����������:1-���������, 2-����� ��������� �������, ������������ ��������");
		switch (_getch())
		{
		case'1':
		{	cout << "������� ����� ��� ���������� ����������: ";
			cin >> N;
			cout << "��������� ��� ����� " << N << " = " << fact(N) << endl << endl;
			break;
		}
		case'2':{int A[] = { 1, 2, 3, 4 };
				int n = 4;
				int i = 0;
				int sum;
				sum = Sum(0, A, 4);
				cout << "C���� ��������� �������=" << sum << endl;
				break; }
		case '3':{ int r = 48;
			int k = 64;
			int div = MaxDiv(r, k);
			cout << "���������� ����� ��������=" << div;
			break; }
		}
		
	}
}