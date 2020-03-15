#pragma once
#include "Terna.h"
using namespace std;

template <class T>

class Lista_8
{
private:
	Terna<T>* first;
	Terna<T>* last;
public:
	Lista_8() {
		first = NULL;
		last = NULL;
	}
	Terna<T>* getFirst()
	{
		return first;
	}

	~Lista_8() {

	}

	void insertFirst(T v)
	{
		Terna <T>* aux;
		if (first == NULL)
		{
			first = new Terna <T>();
			first->setValue(v);
			first->setTam(convertToASCII(v));
			last = first;
		}
		else
		{
			if (buscar(v) == true)
			{

			}
			else
			{
				aux = new Terna <T>();
				aux->setValue(v);
				aux->setTam(convertToASCII(v));
				aux->setNext(first);
				first->setPrevious(aux);
				first = aux;
			}
		}
	}
	void insertBack(T v)
	{
		Terna <T>* aux;
		if (first == NULL)
		{
			first = new Terna <T>();
			first->setValue(v);
			first->setTam(convertToASCII(v));
			last = first;
		}
		else
		{
			aux = new Terna <T>();
			aux->setValue(v);
			aux->setTam(convertToASCII(v));
			aux->setPrevious(last);
			last->setNext(aux);
			last = aux;
		}
	}
void insertarEnSuLugar(T v){
		
		Terna <T> * t = new Terna <T>();
		t->setValue(v); 


		if( convertToASCII(t->getValue()) <= convertToASCII(first->getValue()) ){
			insertFirst(v);
		}

		else if( convertToASCII(t->getValue()) >= convertToASCII(last->getValue()) ){
			insertBack(v);
		}
		
		else {

		Terna <T> *aux = first;

		while(convertToASCII(aux->getValue()) < convertToASCII(t->getValue())){
			aux = aux->getNext(); 
		 } 

		Terna <T> *ant = aux->getPrevious();

		ant->setNext(t);
		aux->setPrevious(t);
		t->setNext(aux);
		}
		
	}
	int convertToASCII(string s)
	{
		int b, e = 0;
		for (int i = 0; i < s.length(); i++)
		{
			b = (int)s[i];
			e = e + b;

		}
		return e;
	}
	void mostrar()
	{
		ordenarLista();
		Terna <T>* aux;
		aux = first;
		if (aux == NULL)
		{
			cout << "Lista Vacia";
		}
		while (aux != NULL)
		{
			cout << aux->getValue() << " " << aux->getTam() << endl;
			aux = aux->getNext();
		}
		cout << endl;
	}
	bool buscar(T v)
	{
		Terna <T>* aux = first;
		bool found = false;
		if (first == NULL)
		{
			found = false;
		}
		while (aux != NULL)
		{
			if (v == aux->getValue())
			{
				found = true;
				break;
			}
			aux = aux->getNext();

		}
		return found;
	}

	void ordenarLista()
	{
		T aux;
		T aux2;
		Terna<T>* auxPri;
		Terna<T>* auxSeg;
		auxPri = first;
		auxSeg = first;
		if (auxPri == NULL)
		{
			cout << "Lista vacia" << endl;
		}
		else
		{
			while (auxPri->getNext() != NULL)
			{
				while (auxSeg->getNext() != NULL)
				{
					if (convertToASCII(auxSeg->getValue()) >= convertToASCII(auxPri->getValue()))
					{
						aux = auxSeg->getValue();
						auxSeg->setValue(auxPri->getValue());
						auxPri->setValue(aux);
					}
					auxSeg = auxSeg->getNext();
				}
				auxPri = auxPri->getNext();
				auxSeg = first;
			}
		}

	}
};