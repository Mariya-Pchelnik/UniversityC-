#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


struct Sved {
	char Fam[20];
	int mark[3];
	float S_Bal;
} zap;
char Spis[] = "d:\\work\\Sp.dat";
FILE *F_zap;
void main()
{
	
	int i, kodR, size = sizeof(Sved);
	float s;
	while (1)   {
		puts("  Создание	- 1");
		puts("  Просмотр   	- 2");
		puts("  Добавление 	- 3");
		puts("  Выход   		- 0");
		scanf_s("%d", &kodR);
		switch (kodR)   {
		case 1:
		case 3: if (kodR == 1) F_zap = fopen(Spis, "w+b");
				else F_zap = fopen(Spis, "a+b");
				while (2) {
					puts(" Фамилия (Завершение ввода - 0)");
					scanf("%s", zap.Fam);
					if ((zap.Fam[0]) == '0')  break;
					puts(" Marks (3) ");
					for (s = 0, i = 0; i<3; i++)
					{
						scanf("%d", &zap.mark[i]);
						s += zap.mark[i];
					}
					zap.S_Bal = s / 3.;
					fwrite(&zap, size, 1, F_zap);
				}
				fclose(F_zap);
				break;
		case 2:   F_zap = fopen(Spis, "r+b");
			while (2)
			{
				if (!fread(&zap, size, 1, F_zap)) break;
				printf(" %20s %2d %2d %2d %5.2f\n",
					zap.Fam, zap.mark[0], zap.mark[1], zap.mark[2], zap.S_Bal);
			}
			fclose(F_zap);
			break;
		case 0:   return;
		}      	//	Конец Switch   
	}		//	Конец While(1)
}		//	Конец программы

