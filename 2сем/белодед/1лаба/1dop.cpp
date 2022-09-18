#include <iostream>//Написать функцию, которая определяет, есть ли в тексте слова, начинающиеся с буквы а, и сколько таких слов. С помощью этой функции проверить несколько строк.
using namespace std;

int as(char *a) {
	int i = 0;
	int k = 0;
	if (a[0] == 'a') {
		k = 1;
	}
	 while(a[i]!='\0') {

		if (a[i] == ' ' && a[i + 1] == 'a') {
			k++;
		}
		i++;
	 }
	return k;
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	char a[100];
	cout<<"Введите слова ";
	cin.getline(a,100);
	cout << as(a);
	return 0;
}