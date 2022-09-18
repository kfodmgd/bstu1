#include <iostream>//Вершина бинарного дерева содержит ключ и два указателя на потомков. Написать функцию вычисления среднего арифметического всех элементов дерева.

#include <iostream>
#include<conio.h>  
using namespace std;
int sum = 0, k = 0;
struct Node
{
	int data;             //Информационное поле
	Node* left, * right;   //Указатели на левую и правую ветви дерева
};
Node* tree = nullptr;

int insert(int a, Node** t)  //Добавление элемента a 
{
	if ((*t) == NULL)              //если дерева нет, то создается элемент
	{
		(*t) = new Node;
		(*t)->data = a;
		(*t)->left = (*t)->right = NULL;
		sum += a;
		k++;
		return sum/k;
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

void main()
{
	int sr;
	setlocale(LC_CTYPE, "Russian");
	int count, temp;
	cout << "Введите количество элементов  "; cin >> count;
	for (int i = 0; i < count; ++i)
	{
		cout << "Введите число  ";	cin >> temp;
		sr=insert(temp, &tree);
	}
	cout << "ваше дерево\n";
	print(tree, 0);
	cout << "Среднее арифметическое:" << sr;
	_getch();
}
