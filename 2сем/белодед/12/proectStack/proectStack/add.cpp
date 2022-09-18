#include "add.h"
using namespace std;
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
