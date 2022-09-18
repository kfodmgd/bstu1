#include <iostream>
#include <windows.h>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int a,itog;
	char per, per1;
	cout << "1 – определение разницы значений кодов в Windows-1251 буквы латинского алфавита в прописном и строчном написании;";
	cout << "2 – определение разницы значений кодов в Windows - 1251 буквы русского алфавита в прописном и строчном написании;";
	cout<<"3 – вывод в консоль кода символа, соответствующего введенной цифре;4 – выход из программы"<<endl;
	cin >> a;
	switch (a) {
	case 1:
		cout << "Введите прописную и строчную буквы ";
	    cin >> per>>per1;
		itog = (int)per1 - (int)per;
		cout << endl << "разница в значениях кода прописной и строчной букв " << itog;
		break;
	case 2:
		cout << "Введите прописную и строчную буквы ";
		cin >> per >> per1;
		itog = (int)per1 - (int)per;
		cout << endl << "разница в значениях кода прописной и строчной букв" << itog;
		break;
	case 3:
		cout << "Введите прописную и строчную буквы ";
		cin >> per >> per1;
		itog = (int)per;
		cout << "Код первого символа " << itog;
		itog = (int)per1;
		cout << "Код второго символа " << itog;
		break;
	case 4:
		break;
	}
	return 0;
}