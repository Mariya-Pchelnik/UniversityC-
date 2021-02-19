
		
#include <stdio.h>
#include <conio.h>
#include <iostream>
struct Tree {
	int info;
	Tree *Left, *Right;
} *Root; // Root – указатель на корень
void Make(int);
void Print(Tree*, int);
void Del(int);
void Del_All(Tree*);
Tree* List(int b);
void Add_List(Tree *Root, int m);
void PoiskInfo(Tree *Root, int key);
int Store_Tree(Tree *p, int pos, int *a);
int KolElementTree(Tree* tree);
void make_blns(Tree **p, int n, int k, int *a);
int poiskMax(Tree *t);
int poiskMin(Tree *t);
int Average(Tree *t);
void PoiskAverage(Tree *t, int Sr, int &difference, int &number);
void main() {
	int b, found, key, m, number, difference = 100, Sr;;
	bool flag = true;
	setlocale(LC_ALL, "rus");
	
	// b – для ввода ключей, found – код поиска, key – удаляемый ключ
	while (flag) {
		puts(" \nCreat - 1\n View - 2\n Find - 3 \nDel Key - 4\nсреднее значение-5\n ,balance-6 \nEXIT - 0");
		switch (_getch()) {
		case '1': if (Root == NULL) {
			int b;
			printf( "Введите корень дерева:");
			
			scanf_s("%d", &b);
			
			Root = List(b);
			
		}
				  else {
					  printf("Введите лист дерева:");
					  scanf_s("%d", &m);
					  Add_List(Root,m);
					  

				  }
				  break;
		case '2': if (Root == NULL) puts("\t END TREE !");
				  else Print(Root, 0);
				  break;
		case '3': printf("Введите информацию в ключе, которого пытаетесь найти:");
			int k;
			scanf_s("%d", &k);
			PoiskInfo(Root, k);
			break;
		case '4': puts("\n Input Del Info "); scanf_s("%d", &key);
			Del(key);
			break;
		case '5':
			if (Root == NULL) {
				printf("Дерево пусто!");
			}
			else {
				Sr = Average(Root);
				difference = Root->info;
				PoiskAverage(Root, Sr, difference, number);
				printf("Ближайшее значение к среднему:");
				printf ("%d",number);
			}
			break;
		case '6':{ if (Root == NULL) { 
			printf("Создайте дерево");
			break; }

				 else {

					 printf("Баллансировка дерева");
					 Tree *t;
					 int k;
					 t = Root;
					 k = KolElementTree(t);
					 int *a = new int[k];
					 int pos = 0;
					 Store_Tree(Root, pos, a);
					 make_blns(&Root, 0, k, a);
					 delete[]a;
					 printf("Дерево сбалансировано!");
					 break;
				 }}
				 break;
		
		case '0': Del_All(Root);
			puts("\n Tree Delete!"); 
				return;
		} // End switch
	} // End of while(flag)
}
//============ Создание дерева ==========================

//============= Удаление элемента по ключу (не корень) ===============
void Del(int key) {
	Tree *Del, *Priooev_Del, *R, *Prev_R, *Prev_Del;
	// Del, Prev_Del - удаляемый элемент и его предок;
	// R, Prev_R - элемент, на который заменяется удаленный и его предок;
	Del = Root; Prev_Del = NULL;
	//-------- Поиск удаляемого элемента и его предка по ключу key---------------------
	while (Del != NULL && Del->info != key) {
		Prev_Del = Del;
		if (Del->info >key) Del = Del->Left;
		else Del = Del->Right; 
	}
	if (Del == NULL){ // В дереве такого ключа нет
		puts("\n NO Key!");
		return;
	}
	//--------------------- Поиск элемента для замены R ----------------------------------------
	//----------1. Если удаляемый элемент имеет одного потомка, или ЛИСТ -----------
	if (Del->Right == NULL) R = Del->Left;
	else
		if (Del->Left == NULL) R = Del->Right;
		else {
			//----------------Иначе, ищем самый правый узел в левом поддереве------------------
			Prev_R = Del;
			R = Del->Left;
			while (R->Right != NULL) {
				Prev_R = R;
				R = R->Right;
			}
			//------------------2. Если удаляемый элемент имеет одного потомка------------------
			if (Prev_R == Del) R->Right = Del->Right;
			else {
				//------------------3. Если удаляемый элемент имеет двух потомков ------------------
				R->Right = Del->Right;
				Prev_R->Right = R->Left;
				R->Left = Prev_R;
			}
		}
		// Устанавливаем связь с предком удаляемого (Prev_Del) и заменой (R):
		if (Prev_Del == NULL) { Root = Prev_Del = R; }
		else
			if (Del->info < Prev_Del->info) Prev_Del->Left = R;
			else Prev_Del->Right = R;
			printf("\n Delete %d element ", Del->info);
			delete Del;
}
//============= Формирование (создание) элемента - листа =============
Tree* List(int b) {
	Tree *t = new Tree; // Захват памяти
	t->info = b;
	t->Left = t->Right = NULL;
	return t;
}
void Add_List(Tree *root, int m) {
	Tree *prev, *t;			// prev – указатель предка нового ли-ста
	bool find = true;
	t = root;
	prev = t;
	while (t && find) {
		prev = t;
		if (m== t->info) {
			find = false;	 	// Ключ должен быть уникален 
			printf("Ключ должен быть уникален!" );
		}
		else
			if (m< t->info) t = t->Left;
			else   t = t->Right;
	}
	if (find) {					// Нашли нужное место
		t = List(m);			// Создаем новый лист
		if (m < prev->info) prev->Left = t;
		else    prev->Right = t;
	}
}
//=============Поиск==========================/
void PoiskInfo(Tree *t, int k) {
	Tree *c;
	c = NULL;
	while (t != NULL && t->info != k) {

		c= t;
		if (t->info > k)  t = t->Left;
		else t = t->Right;
	}
	if (t == NULL) {	
		// Элемент не найден
		printf("Элемент не найден");
	}
	else {
		printf("По ключу:%d, найдено следующее:%d ", k, t->info);
		
	}

}
//=============Баллансировка==========================/
int KolElementTree(Tree* tree) {//подсчет количества элеиентов в дереве
	if (tree->Left == NULL && tree->Right == NULL) return 1;
	int Left, Right;
	if (tree->Left != NULL) {
		Left = KolElementTree(tree->Left);
	}
	else Left = 0;
	if (tree->Right != NULL) {
		Right = KolElementTree(tree->Right);
	}
	else Right = 0;
	return Left + Right + 1;
}
int Store_Tree(Tree *p, int pos, int *a) {//занесение данных в массив
	if (p) {
		pos = Store_Tree(p->Left, pos, a);
		a[pos++] = p->info;
		pos = Store_Tree(p->Right, pos, a);
	}
	return pos;
}
void make_blns(Tree **p, int n, int k, int *a) {

	if (n == k) {

		*p = NULL;//при обращении n=0,k=размер массива

		return;

	}

	else {

		int m = (n + k) / 2;

		*p = new Tree;

		(*p)->info = a[m];

		make_blns(&(*p)->Left, n, m, a);

		make_blns(&(*p)->Right, m + 1, k, a);

	}

}
//=========== Функция вывода на экран ========================
void Print(Tree *p, int level) {
	if (p) {
		
			Print(p->Right, level + 1); // Вывод левого поддерева
		for (int i = 0; i<level; i++) printf(" ");
		printf("%d \n", p->info);
		Print(p->Left, level + 1); // Вывод правого поддерева
	}
}
//=====================Найти ключ ближайший к среднему значению==================
int poiskMax(Tree *t) {
	int MaxElement;
	while (t->Right != NULL) {
		t = t->Right;
	}
	MaxElement = t->info;
	return MaxElement;
}
int poiskMin(Tree *t) {
	int MinElement;
	while (t->Left != NULL) {
		t = t->Left;
	}
	MinElement = t->info;
	return MinElement;
}
int Average(Tree *t) {
	int  Average;
	Average = (poiskMax(Root) + poiskMin(Root)) / 2;
	printf("Среднее значение минимального и максимального элемента:%d", Average);
	return Average;
}
void PoiskAverage(Tree *t, int  Sr, int &difference, int &number) {
	//sr - среднее значение
	//difference - разница между средним зачением и ключем
	//number - само значение
	int TempRoot;
	if (t != NULL) {
		TempRoot = t->info;
		TempRoot = abs(t->info - Sr);
		if (TempRoot < difference) {
			difference = TempRoot;
			number = t->info;
		}
		PoiskAverage(t->Left, Sr, difference, number);
		PoiskAverage(t->Right, Sr, difference, number);
	}
}

//===================== Освобождение памяти ==================
void Del_All(Tree *t) {
	if (t != NULL) {
		Del_All(t->Left);
		Del_All(t->Right);
		delete t;
	}
}