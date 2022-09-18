#include <iostream>//Написать функцию, которая в предложении подсчитывает количество символов в слове максимальной длины (слова разделяются пробелами). Опробовать работу  функции на нескольких предложениях. 
using namespace std;

int minZN(char *a, int m){
	int min = 0;
	int dl = 0;
	int i = 0;
	for (i = 0; i < m; i++) {
		if (a[i] == ' ' && dl > min) {
			min = dl;
			dl = 0;
		}
		if (a[i] != ' ') {
			dl++;
		}
		if (a[i] == ' ') {
			dl = 0;
		}
	}
	return min;
}


int main()
{
	setlocale(LC_CTYPE, "Russian");
	int i, j, len, k,min,m,dl;
	char a[100];
	cout << "Введите предложение ";
	cin.getline(a, 100);
	m = strlen(a);
	i = 0;
	len = 0;
	k = 0;
	j = 0;
	min = 0;
	dl = 0;
	cout << minZN(a, m);
	return 0;
}