#include <windows.h>
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	char c, p = ' ';
	cout << "Введите 1 символ : ";
	cin >> c;
	cout << setw(12) << setfill(p) << p << setw(7) << setfill(c) << c << endl;
	cout << setw(8) << setfill(p) << p << setw(15) << setfill(c) << c << endl;
	cout << setw(5) << setfill(p) << p << setw(21) << setfill(c) << c << endl;
	cout << setw(3) << setfill(p) << p << setw(25) << setfill(c) << c << endl;
	cout << setw(2) << setfill(p) << p << setw(27) << setfill(c) << c << endl;
	cout << setw(2) << setfill(p) << p << setw(27) << setfill(c) << c << endl;
	cout << setw(1) << setfill(p) << p << setw(29) << setfill(c) << c << endl;
	cout << setw(1) << setfill(p) << p << setw(29) << setfill(c) << c << endl;
	cout << setw(31) << setfill(c) << c << endl;
	cout << setw(31) << setfill(c) << c << endl;
	cout << setw(31) << setfill(c) << c << endl;
	cout << setw(1) << setfill(p) << p << setw(29) << setfill(c) << c << endl;
	cout << setw(1) << setfill(p) << p << setw(29) << setfill(c) << c << endl;
	cout << setw(2) << setfill(p) << p << setw(27) << setfill(c) << c << endl;
	cout << setw(2) << setfill(p) << p << setw(27) << setfill(c) << c << endl;
	cout << setw(3) << setfill(p) << p << setw(25) << setfill(c) << c << endl;
	cout << setw(5) << setfill(p) << p << setw(21) << setfill(c) << c << endl;
	cout << setw(8) << setfill(p) << p << setw(15) << setfill(c) << c << endl;
	cout << setw(12) << setfill(p) << p << setw(7) << setfill(c) << c << endl;

	//2 пункт
	int n, k;
	cout << "Введите кол-во школьников и яблок ";
	cin >> n >> k;
	cout<<n/k;
	return 0;
}