#include <iostream>//Написать программу, преобразующую строку, состоящую только из прописных букв, в строку, состоящую из прописных и 
//строчных букв, при этом первая буква после точки  и пробела - прописная, остальные - строчные.
using namespace std;
int st(char*a,int h){
	for (int i = 0; i < h+1; i++) {
	    if (a[i - 1] == ' ' || a[i - 1] == '.') {
		    a[i] = (int)a[i] - 32;
	    }
	}
	for (int i = 0; i < h + 1; i++) {
		return a[i];
	}
}


int main() {
	setlocale(LC_CTYPE, "Russian");
	char* a, b[100];
	int  h;

	cout << "Введите строку с пробелами и точками, но полностью строчные буквы ";
	cin.getline(b, 100);
	h = strlen(b);
	a = new char[h + 1];
	a = b;

	*a = st(a, h);
	for (int i = 0; i < h + 1; i++) {
		cout << a[i];
	}
	return 0;
}