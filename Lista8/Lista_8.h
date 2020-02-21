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
			last = first;
		}
		else
		{
			aux = new Terna <T> (); 
			aux->setValue(v);
			aux->setNext(first); 
			first->setPrevious(aux); 
			first = aux; 
		}
			
	}

	void insertBack(T v)
	{
		Terna <T>* aux;
		if (first == NULL)
		{
			first = new Terna <T>();
			first->setValue(v);
			last = first;
		}
		else
		{
			aux = new Terna <T>();
			aux->setValue(v);
			aux->setPrevious(last);
			last->setNext(aux);
			last = aux;
		}
	}

	void deleteFirst()
	{
		Terna <T>* aux;
		if (first == NULL)
		{
			cout<<"Lista Vacia"<<endl; 
		}
		else{
			if(first->getNext()== NULL){ // solo un elemento

			 	delete first;
				first = NULL;
				last = NULL;

			}
			else{
				aux = first;
				first = first->getNext(); 
				delete aux; 
				first->setPrevious(NULL); 
			}
		}
	}

	void deleteBack()
	{
		Terna <T>* aux;
		if (first == NULL)
		{
			cout<<"Lista Vacia"<<endl; 
		}
		else{
			if(first->getNext()== NULL){ // solo un elemento

			 	delete last;
				first = NULL;
				last = NULL;
				
			}
			else{
				aux = last;
				last = last->getPrevious(); 
				delete aux; 
				last->setNext(NULL); 
			}
		}
	}

	

	void mostrar()
	{
		Terna <T>* aux;
		aux = first;
		if (aux == NULL)
		{
			cout << "Lista Vacia";
		}
		while (aux != NULL)
		{
			cout << aux->getValue() << " ";
			aux = aux->getNext();
		}
		cout << endl;
	}

	void buscar(T v)
	{
		Terna <T>* aux; 
		aux = first;
		bool found = false; 
		if (first == NULL)
		{
			cout << "Lista Vacia";
		}
		while (aux != NULL)
		{
			if (v ==aux->getValue())
			{
				cout << "el valor se encuentra en la lista  "<<endl;
				found = true; 
				break;
			}
			aux = aux->getNext();

		}
		if(!found){
		cout << "el valor no se encuentra en la lista"<<endl;
		}
	}
	string buscarRecursivo(T v, Terna<T>* p)
	{
		string res;
		if (p == NULL)
		{
			res = "no";
		}
		else
		{
			if (p->getValue() == v)
			{
				res = "si";
			}
			else
			{
				res = buscarRecursivo(v, p->getNext());
			}
		}
		return res + "\n";
	}
	


	

};

