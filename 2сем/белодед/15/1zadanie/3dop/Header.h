#pragma once
#include "Lists.h"
namespace hashTC
{
	struct Object                                                                       //Ñòðóêòóðà "îáúåêò"
	{
		int sizeO;                                                                      //Ðàçìåð îáúåêòà
		int(*FunKey)(void*);
		listx::Object* Hash;
		Object(int size, int(*f)(void*))                                                //Ìåòîä ñîçäàíèÿ íîâîãî îáúåêòà (ðàçìåð, óêàçàòåëü)
		{
			sizeO = size;                                                               //Ðàçìåð íîâîãî îáúåêòà                           
			FunKey = f;                                                                 //Óêàçàòåëü íà ïåðâûé ñïèñîê-ýëåìåíò òàáëèöû
			Hash = new listx::Object[size];
		};
		int hashFunction(void* data);
		bool insert(void* data);
		listx::Element* search(void* data);
		bool deleteByData(void* data);
		void Scan();
		void Scan1(void* data);
	};
	Object create(int size, int(*f)(void*));
}