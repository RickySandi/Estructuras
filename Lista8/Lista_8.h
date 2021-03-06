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
		if (p == NULL){
			res = "no";
		}
		else
		{
			if (p->getValue() == v){
				res = "si";
			}
			else{
				res = buscarRecursivo(v, p->getNext());
			}
		}
		return res;
	}
	
	void insertarEnSuLugar(T v){
		
		Terna <T> * t = new Terna <T>();
		t->setValue(v); 


		if(t->getValue() <= first->getValue()){
			insertFirst(v);
		}

		else if( t->getValue() >= last->getValue()){
			insertBack(v);
		}
		
		else {

		Terna <T> *aux = first;

		while(aux->getValue() < t->getValue()){
			aux = aux->getNext(); 
		 } 

		Terna <T> *ant = aux->getPrevious();

		ant->setNext(t);
		aux->setPrevious(t);
		t->setNext(aux);
		}
		
	}
		
	void eliminarElemento(T v){
		
	    Terna<T>* t = new Terna <T>();
		t->setValue(v); 
		if (first == NULL){
			cout << "Lista Vacia";
			return ; 
		}

		else if (v == last->getValue()){
			deleteBack();
		}
		
		else if (v == first->getValue()){
				deleteFirst();
		}
		else{
			Terna <T>* aux = first;  

				while(aux && aux->getValue() != v){
				aux = aux->getNext(); 
				}

			if (aux) {

			Terna <T>* ant = aux->getPrevious();
			Terna <T>* sig = aux->getNext();

			if(ant != NULL){ ant->setNext(sig); } 
			if(sig != NULL){ sig->setPrevious(ant); } 
			}	
		}
	}

	void invertir()  {  

  	  Terna <T> *aux = NULL;  
      Terna <T> *actual = first; 
    
    	while (actual != NULL){
        aux = actual->getPrevious();  
        actual->setPrevious(actual->getNext());  
        actual->setNext(aux);              
        actual = actual->getPrevious();  
    	}  

		swap(first, last);

	}

	T buscarIPos(int pos){

		Terna <T>* aux = first;  
		while(pos > 0){
			aux = aux->getNext();
			pos--; 	
		}
		if(pos < 0){aux = NULL;}
		return aux->getValue(); 
	}


	void deleteList(){

	Terna <T>* actual = first;  
	Terna <T>* next;  
  
	while (actual != NULL){  
   	 next = actual->getNext();  
   	 free(actual);  
     actual = next;  
	}  
	first  = NULL;  
} 

Lista_8 <T>* fusionarListas(Terna<T>* primeroLista2){
		
		Lista_8 <int>* lista3 = new Lista_8 <int>();
		Terna<T>* a = first;
		Terna<T>* b = primeroLista2;  

		while(a != NULL || b != NULL){

			if(a && b){

				if(a->getValue() < b->getValue()){
					
					lista3->insertBack(a->getValue());
					a = a->getNext(); 
				}
				else {
					lista3->insertBack(b->getValue());
					b = b->getNext(); 
				}
			}
			else{
				if(a){
					lista3->insertBack(a->getValue());
					a = a->getNext(); 
				}
				else{
					lista3->insertBack(b->getValue());
					b = b->getNext(); 
				}
			}
		}
		return lista3;			
	}
};

