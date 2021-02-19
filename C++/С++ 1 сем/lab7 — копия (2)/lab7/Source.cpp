#include<conio.h>
#include<stdio.h>
#include<string.h>
void main(void){
	int L, i;
	char s[90];
	printf("Vvedite stroku:");
	gets_s(s);
	L = strlen(s);
	if (L % 2 == 1)
		printf("dlina nechetnaja");
	else
	{
		for (int i = 0; i < L; i++)
		{
			s[i] = s[i + 2];
		}
		for (int i = L - 2; i < L; i++)
		{
			s[i - 2] = s[i];
		}
		puts(s);
	}
	_getch();
}
