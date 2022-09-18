#include "List.h"
#include "Hash_Twin_Chain.h"
#include <iostream>

struct AAA
{
	int key;
	const char* mas;
	AAA(int k, char* z)
	{
		key = k;
		mas = z;
	}
};

namespace hashTC
{
	Object create(int size, int(*f)(void*))															//Ôóíêöèÿ ñîçäàíèÿ íîâîãî îáúåêòà - òàáëèöû
	{
		return *(new Object(size, f));															    //Íîâûé îáúåêò(ðàçìåð îáúåêòà, óêàçàòåëü)
	}
	int Object::hashFunction(void* data)		// óíèâåðñàëüíîå õåøèðîâàíèå
	{
		int h = 0, a = 314445, b = 37542;
		h = (a * h + FunKey(data)) % sizeO;
		return (h < 0) ? (h + sizeO) : h;

	};
	bool Object::insert(void* data)
	{
		return (Hash[hashFunction(data)].insert(data));
	};
	bool Object::deleteByData(void* data)
	{
		return (Hash[hashFunction(data)].deleteByData(data));
	};
	listx::Element* Object::search(void* data)
	{
		return Hash[hashFunction(data)].search(data);
	};
	void Object::Scan()
	{
		for (int i = 0; i < sizeO; i++)
		{
			std::cout << i << ". ";
			Hash[i].scan();
			std::cout << '\n';
		}
	};
}