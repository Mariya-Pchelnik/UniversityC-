#include <stdio.h>
#include <conio.h>
struct Spis { // Описание структуры
	int info;
	Spis *Prev, *Next;
} *begin, *end;
void View(void);
void Del_Spis(void);
void sort(void);
void main(void) {
	Spis *t, *key, *m;
	
	int i, k;
	while (1) {
		printf("\n Creat - 1\n View - 2\n Find - 3\ \n Del - 4\n Ins - 5\n EXIT - 0\nSort-6\n");
		switch (_getch()) {
			
		case '1': i = 0;
			t = new Spis;
			printf(" Input info 1 : "); scanf_s("%d", &t->info);
			t->Next = t->Prev = NULL;
			begin = end = t;
			while (2) {
				t = new Spis;
				printf(" Input info : "); scanf_s("%d", &t->info);
				t->Next = NULL;
				t->Prev = end;
				end->Next = t;
				end = t;
				printf("\n Repeat - y ");
				if (_getch() != 'y') break; // Продолжение - 'y', иначе - выход
			}
			break;

			
		case '2': View(); break;
		case '6':sort(); break;
			
		case '3': t = begin;
			printf("\n Find Info : "); scanf_s("%d", &i);
			k = 1;
			while (t != NULL) {
				if (t->info == i) {
					printf("\n Element = %d - number = %d", t->info, k);
					_getch(); break;
				}
				t = t->Next;
				k++;
			}
			if (t == NULL) {
				puts("\n Not Found !");
				_getch();
			}
			break;
			
		case '4': t = begin;
			key = NULL;
			m = NULL;
			k = 1;

			while (t != NULL) {

				if (t->info <0) {
					printf("\n Delete element = %d - number = %d", t->info, k);
					_getch();
					key = t; // Запомнили адрес удаляемого элемента
					if (key == begin) {

						begin = begin->Next;
						begin->Prev = NULL;
						key = m;
						delete m;
					}
					else if (key == end) {
						end = end->Prev;
						end->Next = NULL;
						key = m;
						delete m;
					}
					else {
						(key->Prev)->Next = key->Next;
						(key->Next)->Prev = key->Prev;
						delete key;
					}

				}
				t = t->Next;
			}
			if (key == NULL) {
				puts("\n NO Element !");
				_getch();
				break;
				if (t == NULL) {
					puts("\n NO Element !");
					_getch();
					break;
				}
			}
			break;
		

		case '0': Del_Spis(); return;
		} // switch()
	} // while(1)
} // main()


	void sort()
	{
		struct Spis*t=begin;
		struct Spis*a;
		int f = 0;
		bool flag = 1;
		while (flag == 1)
		{
			
			a = t->Next;
			flag = 0;
			while (a != NULL)
			{
				if (t->info > a->info)
				{
					f = t->info;
					t->info = a->info;
					a->info = f;
					flag = 1;
				}
				t = t->Next;
				a = a->Next;
			}
		}
	}


void View() {
	int k = 1;
	Spis *t = begin;
	
	if (t == NULL) {
		printf("\n NO elements !"); return;
	}
	while (t != NULL) {
		printf("\n %d element - %d", k, t->info);
		t = t->Next;
		k++;
	}
}


void Del_Spis(void) {
	Spis *t = begin;
	while (t != NULL) {
		begin = begin->Next;
		delete t;
		t = begin;
	}
	puts(" Delete!");
}
