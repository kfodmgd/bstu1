#include "Header.h"
#include "Lists.h"
#include <iostream>
#include "Lists.h"
struct AAA
{
	int key;
	char mas[50];
	AAA(int k, char* z)
	{
		key = k;
		strcpy_s(mas, 50, z);
	}
};
namespace hashTC
{
	Object create(int size, int(*f)(void*))															//Ôóíêöèÿ ñîçäàíèÿ íîâîãî îáúåêòà - òàáëèöû
	{
		return *(new Object(size, f));															    //Íîâûé îáúåêò(ðàçìåð îáúåêòà, óêàçàòåëü)
	}
	int Object::hashFunction(void* data)
	{
		return (FunKey(data) % sizeO);
	};
	bool Object::insert(void* data)
	{
		return (Hash[hashFunction(data)].insert(data));
	};
	bool Object::deleteByData(void* data)
	{
		for (int i = 0; i < sizeO; i++)
		{
			listx::Element* e = Hash[i].getFirst();                                                 //å - ýòî óêàçàòåëü íà ãîëîâó îòäåëüíîãî ýëåìåíòà-ñïèñêà òàáëèöû
			bool k = 0;
			while (e != NULL)
			{
				if (*(((AAA*)data)->mas) == *(((AAA*)e->data)->mas))
				{
					return(Hash[i].deleteByElement(e));
				}
				e = e->getNext();
			};
		}
	};
	listx::Element* Object::search(void* data)
	{
		return Hash[hashFunction(data)].search(data);
	};
	void Object::Scan()
	{
		for (int i = 0; i < sizeO; i++)
		{
			std::cout << i + 1 << ". ";
			Hash[i].scan();
			std::cout << '\n';
		}
	};
	void Object::Scan1(void* data)
	{
		std::cout << "Íàéäåííûå çàïèñè: " << std::endl;
		for (int i = 0; i < sizeO; i++)
		{
			Hash[i].scan1(data);
		}
	};
}