#include "add.h"
using namespace std;
void print(Node* t, int u)
{
	if (t == NULL)  return;
	else
	{
		print(t->left, ++u);     //כוגמו ןמההונוגמ
		for (int i = 0; i < u; ++i)
			cout << "|";
		cout << t->data << endl;
		u--;
	}
	print(t->right, ++u);          // ןנאגמו ןמההונוגמ

}