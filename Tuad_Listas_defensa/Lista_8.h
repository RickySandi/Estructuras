#pragma once
#include "Terna.h"
using namespace std;

template <class T>

class Lista_8
{
private:
	Terna<T>* first;
	Terna<T>* last;
	Lista_8 <T>* vec[23];
public:
	Lista_8() {
		first = NULL;
		last = NULL;
	}
	Terna<T>* getFirst(){
		return first;
	}

	~Lista_8() {

	}
	

	void insertFirst(T v){
		Terna <T>* aux;
		if (first == NULL){
			first = new Terna <T>();
			first->setValue(v);
			first->setTam(convertToASCII(v));
			last = first;
		}
		else
		{
			if (buscar(v) == true){

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
	void insertBack(T v){
		Terna <T>* aux;
		if (first == NULL){
			first = new Terna <T>();
			first->setValue(v);
			first->setTam(convertToASCII(v));
			last = first;
		}
		else{
			aux = new Terna <T>();
			aux->setValue(v);
			aux->setTam(convertToASCII(v));
			aux->setPrevious(last);
			last->setNext(aux);
			last = aux;
		}
	}	

	void insertarEnSuLugar(T v) {
		
		if (first == NULL){
			first = new Terna <T>();
			first->setValue(v);
			last = first;
		}
		else if (convertToASCII(v) != convertToASCII(first->getValue())){

			if (convertToASCII(v) < convertToASCII(first->getValue())) {

				insertFirst(v);
			} 
			else if (convertToASCII(v) > convertToASCII(last->getValue())){
				insertBack(v);
			} 
			else {

			Terna <T>* aux;
			aux = first;
			
			while (aux && convertToASCII(v) < convertToASCII(aux->getValue())) {
				aux = aux->getNext();
			}
		

			Terna <T>* bro = new Terna <T>();
			bro->setValue(v);
			bro->setNext(aux);

			if (aux) {
			aux->setPrevious(bro);
			}
			}
		}
}
	
	int convertToASCII(string s){
		int b, e = 0;
		for (int i = 0; i < s.length(); i++){
			b = (int)s[i];
			e = e + b;
		}
		return e;
	}

	void mostrar(){
		Terna <T>* aux;
		aux = first;
		if (aux == NULL){
			cout << "Lista Vacia";
		}
		while (aux != NULL){
			cout << aux->getValue() << " " << convertToASCII(aux->getValue()) << endl;
			aux = aux->getNext();
		}
		cout << endl;
	}

	bool buscar(T v){
		Terna <T>* aux = first;
		bool found = false;
		if (first == NULL){
			found = false;
		}
		while (aux != NULL){
			if (v == aux->getValue()){
				found = true;
				break;
			}
			aux = aux->getNext();
		}
		return found;
	}
	void insertarLista8(T palabra){
		 vec[palabra.length()]->insertarEnSuLugar(palabra);
	}

};