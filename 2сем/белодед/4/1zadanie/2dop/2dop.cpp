#include <iostream>//Ф.И.О., класс (цифра+буква) предметы, оценки, средний балл. Выбор по среднему баллу. 
#include <Windows.h>
using namespace std;

struct Class {
	char f[50];
	char i[50];
	char o[50];
	char form[3];
	char subj[50];
	int mark[50];
	double sr_ball[50];
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int size,i,num;
	double ozhen, j,sr1,sr2;
	j = 0;
	ozhen = 0;
	Class a[50];
	cout << "Введите колво учеников:";
	cin >> size;
	for (i = 0; i < size; i++) {
		cout << "Введите ФИО ученика:";
		cin >> a[i].f >> a[i].i >> a[i].o;
		cout << "Введите класс ученика:";
		cin >> a[i].form;
		cout << "Введите предмет:";
		cin >> a[i].subj;
		cout << "Введите оценки (последней должна быть 0):";
		do {
			cin >> a[i].mark[i];
			j++;
			ozhen += a[i].mark[i];
		} while (a[i].mark[i] != 0);
		j--;
		a[i].sr_ball[i] = ozhen/j;
		cout <<"Средний балл:"<< a[i].sr_ball[i]<<endl<<endl;
	}
	
	cout <<endl<<endl<< "Введите диапазон средних баллов, по которому хотите найти ученика:";
	cin >> sr1 >> sr2;
	cout << "Ученики, имеющие средний балл в указанном диапазоне:" << endl;
	for (i = 0; i < size; i++) {

		if (a[i].sr_ball[i] > sr1 && a[i].sr_ball[i] < sr2) {
			cout << a[i].f << " " << a[i].i << " " << a[i].o;
			cout << ". Учится в " << a[i].form << ". Его средний балл по предмету " << a[i].subj << " равен " << a[i].sr_ball[i] << endl;
		}
	}
	return 0;
}
