#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

#include <conio.h>
int const n = 2;

struct Sved {
	int numb;
	char Fam[7];
	int chas;
	int tar;
	double zarp;
};
FILE *file2_ptr;
void main()
{
	setlocale(LC_ALL, "Russian");
	int  kodR,i,z;
	Sved s[n];
	while (1)
	{
		puts("  ��������	- 1");
		puts("  ��������   	- 2");
		puts("  ��������� 	- 3");
		puts("  �����   		- 0");
		

		scanf_s("%d", &kodR);
		switch (kodR)   {
		case 1:

		case 3:	if (kodR == 1)
		{

			file2_ptr = fopen("d:\\C++\\File.txt", "w+b");
			if (file2_ptr != NULL)
			{
				printf("���� d:\\C++\\File.txt ������� ������ \n");

			}
			else
			{
				printf("�� ������� ������� ��� ������� ���� d:\\C++\\File.txt");

			}
		}
				else

				{
					file2_ptr = fopen("d:\\C++\\File.txt", "a+b");
				}
				
				while (2) {
					for (i = 0; i < n; i++)
					{
						printf("������� �����");
						scanf("%d", &s[i].numb);
						printf("������� �������:");
						scanf("%s", &s[i].Fam);
						printf("������� �����:");
						scanf("%d", &s[i].chas);
						printf("������� �����:");
						scanf("%d", &s[i].tar);
						if (s[i].chas>144)
							z = 144 * s[i].tar + ( s[i].chas-144)*2*s[i].tar;
						
						else z =  s[i].chas*s[i].tar;
						s[i].zarp = z - 0.12*z;
					}  
					fwrite(&s, sizeof(Sved), n, file2_ptr);
					
					break;
				}

				fclose(file2_ptr);
				break;

		case 2:
			file2_ptr = fopen("d:\\C++\\File.txt", "r+b");

			{    	while (2)

				if (!fread(&s, sizeof(Sved), n, file2_ptr)) break;
			for (i = 0; i < n; i++)
			printf("%d. %s | %d | %d ,��������=%lf\n", s[i].numb, s[i].Fam, s[i].chas, s[i].tar,s[i].zarp);
			}
			fclose(file2_ptr);
			break;

		case 0:   return;
    }
	}
}