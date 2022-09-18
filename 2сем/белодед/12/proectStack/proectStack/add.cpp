#include "add.h"
using namespace std;
void insert(int a, Node** t)  //���������� �������� a 
{
	if ((*t) == NULL)              //���� ������ ���, �� ��������� �������
	{
		(*t) = new Node;
		(*t)->data = a;
		(*t)->left = (*t)->right = NULL;
		return;
	}
	if (a > (*t)->data)  //������ ����, ���� � ������ ��������
		insert(a, &(*t)->right);  //�� ������� ���������� ������
	else
		insert(a, &(*t)->left);   //����� - �����
}
