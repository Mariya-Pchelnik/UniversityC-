#include <iostream>
#include <vector>
#include <conio.h>
#include <stdio.h>
using namespace std;
int f1(int&n)
{  return --n - 2;}
int f2(int&n)
{	return n-- -1;}
int test(int n)
{	int result = 0;
	while (n-- > 0)  
	{ if (f1(n) || f2(n))
	result += n;}
	return result;}
int main(int args, char*argv[])
{
	int x[] = { 3, 5, 8 };
	std::cout << *(x = 2);



		
	_getch();
}