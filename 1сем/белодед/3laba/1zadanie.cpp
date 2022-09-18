#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;
void main() {
	setlocale(LC_CTYPE, "Russian");
	int arr[5] = { 1, 2, 3, 3 ,5 }; int i = 0;
	while (i < 4)std::cout << arr[++i];
}
