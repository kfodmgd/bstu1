#include <windows.h>
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	char c, p = ' ';
	cin >> c;
	cout << setw(35) << setfill(p) << p << setw(2) << setfill(c) << c << endl;
	cout << setw(33) << setfill(p) << p << setw(6) << setfill(c) << c << endl;
	cout << setw(30) << setfill(p) << p << setw(12) << setfill(c) << c << endl;
	cout << setw(28) << setfill(p) << p << setw(16) << setfill(c) << c << endl;
	cout << setw(26) << setfill(p) << p << setw(20) << setfill(c) << c << endl;
	cout << setw(28) << setfill(p) << p << setw(16) << setfill(c) << c << endl;
	cout << setw(30) << setfill(p) << p << setw(12) << setfill(c) << c << endl;
	cout << setw(33) << setfill(p) << p << setw(6) << setfill(c) << c << endl;
	cout << setw(35) << setfill(p) << p << setw(2) << setfill(c) << c << endl;

	//2 пункт
	int a, b, d;
	cout << "кол-во самолётов ";
	cin >> a;
	cout << "Введите кол - во сбитых ракет ";
	cin >> b;
	cout << "Введите кол - во сбитых спутников ";
	cin>> d;
	cout << a * 50 + b * 100 + d * 200; 
	return 0;
}