#include <iostream> //в числе А n битов вправо от позиции p, заменить ими n битов числа В, начиная с позиции q.
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	unsigned int a;
	unsigned int b;
	unsigned int x;
	unsigned int y;
	char a1[32];
	char b1[32];
	char x1[32];
	char y1[32];
	char k[32];
	char k1;
	int n, p, m, q,f;
	string l, c,l1,c1,c2;
	cout << "Введите число a";
	cin >> a;
	x = a;
	cout << "Введите число b";
	cin >> b;
	y = b;
	cout << "Введите от какой позиции и сколько символов в числе а надо сдвинуть и откуда ";
	cin >> p >> n;
	cout << "Введите с какой позиции заменить числа в b ";
	cin >> q;
	_itoa_s(a, a1, 2);
	cout <<"число а в двоичной сисме счисл"<< a1 << endl;
	_itoa_s(b, b1, 2);
	cout << "число b в двоичной сисме счисл" << b1 << endl;
	l = a1;
	l1 = b1;
	//_itoa_s((15<<1), buffer, 2);//у числа 15 перевод в двоичную сисму счисл и загон в buffer

	_itoa_s(a, x1, 2);
	cout <<endl<<"Число с введённой позиции на n знаков " << l.substr(p - 1, n) << endl;//вывод строки с позиции p-1 n символов
	k1 = *l.c_str();//сссылка k1 на l чтобы поменять тип данных
	_itoa_s(k1, k, 2);
	//cout <<endl<<endl<< k1<<"qwetty"<<k;//в k двоичный код числа как у l

	f = pow(2, q);//вычисление части которую мы по сути убираем
	
	f=f^k1;//объединение убранной части с той, что сдвинули на n знаков
	c1 = f;//принимаем значение f в виде двоичного кода
	y = y >> q;//нахождение части которая осталась после сдвига
	c2 = y;//принимаем значение y в виде двоичного кода
	_itoa_s(f, y1, 2);
	cout <<endl<<y1;
	_itoa_s(y, y1, 2);
	cout << y1;
	return 0;
}