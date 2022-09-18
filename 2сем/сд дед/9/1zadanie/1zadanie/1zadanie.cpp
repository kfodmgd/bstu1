#include <iostream>
using namespace std;

int main()
{
	//Массив значений в котором пойдет поиск
	int MyArray[]{ 1, 2, 123, 6, 1000, 89, 4, 231, 7, 1235 };

	int x = 0; //Текущая позиция массива, с которым сравнивается искомое
	int a = 0; //Левая граница области, где ведется поиск
	int b = 9; //Правая граница области, где ведется поиск

	int WhatFind = 123; //Значение, которое нужно найти
	bool found; //Переменка-флаг, принимающая True если искомое найдено

	/************ Начало интерполяции *******************************/

	//Цикл поиска по массиву, пока искомое не найдено 
	//или пределы поиска еще существуют
	for (found = false; (MyArray[a] < WhatFind) && (MyArray[b] > WhatFind) && !found; )
	{
		//Вычисление интерполяцией следующего элемента, который будет сравниваться с искомым
		x = a + ((WhatFind - MyArray[a]) * (b - a)) / (MyArray[b] - MyArray[a]);
		//Получение новых границ области, если искомое не найдено
		if (MyArray[x] < WhatFind)
			a = x + 1;
		else if (MyArray[x] > WhatFind)
			b = x - 1;
		else
			found = true;
	}

	/************** Конец интерполяции ***************************/

	//Если искомое найдено на границах области поиска, показать на какой границе оно
	if (MyArray[a] == WhatFind)
		cout << WhatFind << " founded in element " << a << endl;
	else if (MyArray[b] == WhatFind)
		cout << WhatFind << " founded in element " << b << endl;
	else
		cout << "Sorry. Not found" << endl;

	return 0;
}
