#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;
void F(int n)
{
	cout <<' '<< n;

	if (n > 0)
	{
		
		F(n - 8);
		F(n / 2);
		
	}
}
	

void main(void)
{
	int n = 6;
	F(n);
	_getch();
}