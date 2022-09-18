#include <iostream> 
//#include <string>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	unsigned int a;
	char ach[32];
	string l;
	char al;
	int bl;
	cout << "Введите число ";
	cin >> a;
	_itoa_s(a, ach, 2);
	cout << endl << ach;
	l = ach;
	cout <<endl<< l<<endl;
	al = l[l.size() - 1];
	bl = al - '0';
	if (bl==0) {//если посл бит =0 то это чётн, иначе нечётн
		cout << "Число кратно 2";
	}
	else {
		cout << "Число не кратно 2";
	}
	return 0;
}