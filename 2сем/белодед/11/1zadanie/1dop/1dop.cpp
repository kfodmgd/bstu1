#include <iostream>//Вершина бинарного дерева содержит ключ,  три целых числа и два указателя на потомков. Написать функцию удаления вершины с минимальной суммой трех целых значений узла.
#include<conio.h>  
#include <limits>
using namespace std;

int sum1 = 0, sum2 = 0;


struct Node
{
	int data;             //Информационное поле
	Node* left, * right;   //Указатели на левую и правую ветви дерева
};
Node* tree = nullptr;

void insert(int a, Node** t)  //Добавление элемента a 
{
	if ((*t) == NULL)              //если дерева нет, то создается элемент
	{
		(*t) = new Node;
		(*t)->data = a;
		(*t)->left = (*t)->right = NULL;
		return;
	}
	if (a > (*t)->data)  //дерево есть, если а больше текущего
		insert(a, &(*t)->right);  //то элемент помещается вправо
	else
		insert(a, &(*t)->left);   //иначе - влево
}

void print(Node* t, int u)    //Вывод на экран
{
	if (t == NULL)  return;
	else
	{
		print(t->left, ++u);     //левое поддерево
		for (int i = 0; i < u; ++i)
			cout << "|";
		cout << t->data << endl;
		u--;
	}
	print(t->right, ++u);          // правое поддерево
}

Node* delet(Node* Root, int sum)  //Удаление элемента по ключу
{	// Del, Prev_Del - удаляемый элемент и его предыдущий ;
	// R, Prev_R - элемент, на который заменяется удаленный, и его родитель; 
	Node* Del, * Prev_Del, * R, * Prev_R;
	Del = Root;
	Prev_Del = NULL;
	while (Del != NULL && Del->data != sum)//поиск элемента и его родителя 
	{
		Prev_Del = Del;
		if (Del->data > sum)
			Del = Del->left;
		else
			Del = Del->right;
	}
	if (Del == NULL)              // элемент не найден
	{
		puts("\nНет такого ключа");
		return Root;
	}
	if (Del->right == NULL) // поиск элемента R для замены
		R = Del->left;
	else
		if (Del->left == NULL)
			R = Del->right;
		else
		{
			Prev_R = Del; //поиск самого правого элемента в левом поддереве
			R = Del->left;
			while (R->right != NULL)
			{
				Prev_R = R;
				R = R->right;
			}
			if (Prev_R == Del) // найден элемент для замены R и его родителя Prev_R 
				R->right = Del->right;
			else
			{
				R->right = Del->right;
				Prev_R->right = R->left;
				R->left = Prev_R;
			}
		}
	if (Del == Root) Root = R;	//удаление корня и замена его на R
	else
		// поддерево R присоединяется к родителю удаляемого узла
		if (Del->data < Prev_Del->data)
			Prev_Del->left = R; // на левую ветвь 
		else
			Prev_Del->right = R;	// на правую ветвь
	int tmp = Del->data;
	cout << "\nУдален элемент со значением " << tmp << endl;
	delete Del;
	return Root;
}



void main()
{
	setlocale(LC_CTYPE, "Russian");
	int count, temp[3],sum,min=INT_MAX;
	cout << "Введите количество элементов  "; cin >> count;
	for (int i = 0; i < count; ++i)
	{
		cout << "Введите числa  ";
		sum = 0;
		for (int j = 0; j < 3; j++) {
		cin >> temp[j];
		sum += temp[j];
		}
		//реализация минимум с использованием макс значения инта
		if (sum < min) {
			min = sum;
		}
		insert(sum, &tree);
	}
	cout << "ваше дерево\n";
	print(tree, 0);
	cout << "Минимальная сумма:" << min;
	tree=delet(tree, min);
	print(tree, 0);
	_getch();
}

