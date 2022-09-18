#include <iostream>//Дан указатель p1 на корень непустого дерева и число k. Написать функцию вывода количества вершин дерева, значение которых равно k.
#include<conio.h>  	
using namespace std;
int m = 0;
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

Node* search(Node* t, int k) {
	Node *rc = t;
	if (t != NULL) {
		if (k < t->data) {
			if (k == t->data) {
				m++;
			}
			rc = search(t->left, k);
		}
		else {
			if (k == t->data) {
				m++;
				rc = search(t->left, k);
			}
			rc = search(t->right, k);
		}

	}
	else {
		cout << "Количество найденных лементов равных введённому значению:" << m<<endl;
	}
	return rc;
}

void main()
{
	setlocale(LC_CTYPE, "Russian");
	int count, temp,k;
	Node *rc;
	cout << "Введите количество элементов  "; cin >> count;
	for (int i = 0; i < count; ++i)
	{
		cout << "Введите число  ";	cin >> temp;
		insert(temp, &tree);
	}
	cout << "ваше дерево\n";
	print(tree, 0);
	cout << endl << "Введите значение которое нужно подсчитать в дереве ";
	cin >> k;
	rc = search(tree, k);
	_getch();
}
