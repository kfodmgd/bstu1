#include "List.h"
#include <iostream>
struct AAA        //ýëåìåíò òàáëèöû
{
	int key;
	char* mas;
};
namespace listx
{
	bool Object::insert(void* data)
	{
		bool rc = NULL;
		if (head == NULL)                                                           //Ãîëîâà ñïèñêà ïóñòàÿ?
			head = new Element(NULL, data, head);                                   //Ñîçäàíèå íîâîãî ñïèñêà 
		else
			head = (head->prev = new Element(NULL, data, head));                    //Âñòàâêà ýëåìåíòà ñ äàííûìè â ïðåäûäóùóþ ïîçèöèþ, ñäâèãàÿ ãîëîâó âïåð¸ä
		return rc;
	}
	//-------------------------------
	Element* Object::search(void* data)
	{
		Element* rc = head;
		while ((rc != NULL) && ((((AAA*)rc->data)->key) != ((AAA*)data)->key))
			rc = rc->next;
		return rc;
	}
	//-------------------------------
	bool Object::deleteByElement(Element* e)
	{
		bool rc = NULL;
		if (rc = (e != NULL))
		{
			if (e->next != NULL)
				e->next->prev = e->prev;
			if (e->prev != NULL)
				e->prev->next = e->next;
			else
				head = e->next;
			delete e;
		}
		std::cout << "Ýëåìåíò óäàëåí" << std::endl;
		return rc;
	}
	//-------------------------------
	bool Object::deleteByData(void* data)
	{
		return deleteByElement(search(data));
	}
	//-------------------------------
	Element* Object::getLast()
	{
		listx::Element* e = this->getFirst(), * rc = this->getFirst();
		while (e != NULL)
		{
			rc = e;
			e = e->getNext();
		};
		return rc;
	}
	Object create()
	{
		return *(new Object());
	};
	//-------------------------------
	void Object::scan()
	{
		listx::Element* e = this->getFirst();                                                 //å - ýòî óêàçàòåëü íà ãîëîâó îòäåëüíîãî ýëåìåíòà-ñïèñêà òàáëèöû
		bool k = 0;
		while (e != NULL)
		{
			std::cout << "Íîìåð øêîëû: " << ((AAA*)e->data)->key << "; " << "ôàìèëèÿ äèðåêòîðà: " << ((AAA*)e->data)->mas << "; ";        //Ïîî÷åð¸äíûé âûâîä ýëåìåíòîâ ñïèñêà. Ñïèñîê - ýòî îòäåëüíûé ýëåìåíò òàáëèöû
			e = e->getNext();                                                                 //Ïîëó÷åíèå àäðåñà ñëåäóþùåãî ýëåìåíòà ñïèñêà
			k = 1;
		};
		if (!k)
		{
			std::cout << "Ïóñòàÿ ÿ÷åéêà";
		}
	}
}