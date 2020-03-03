#pragma once
#include "Cuarteto.h"
using namespace std;

template <class T>

class Lista_Listas
{
private:
	Cuarteto<T>* first;
	Cuarteto<T>* last;
public:
	Lista_Listas() {
		first = NULL;
		last = NULL;
	}
	Cuarteto<T>* getFirst()
	{
		return first;
	}

	~Lista_Listas() {

	}

	void insertFirst(T v)
	{
		Cuarteto <T>* aux; 
		if (first == NULL)
		{
			first = new Cuarteto <T>();
			first->setValue(v);
			last = first;
		}
		else
		{
			aux = new Cuarteto <T> (); 
			aux->setValue(v);
			aux->setNext(first); 
			first->setPrevious(aux); 
			first = aux; 
		}
			
	}

	void insertBack(T v)
	{
		Cuarteto <T>* aux;
		if (first == NULL)
		{
			first = new Cuarteto <T>();
			first->setValue(v);
			last = first;
		}
		else
		{
			aux = new Cuarteto <T>();
			aux->setValue(v);
			aux->setPrevious(last);
			last->setNext(aux);
			last = aux;
		}
	}

	void deleteFirst()
	{
		Cuarteto <T>* aux;
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
		Cuarteto <T>* aux;
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
		Cuarteto <T>* aux;
		aux = first;
		if (aux == NULL)
		{
			cout << "Lista Vacia";
		}
		while (aux != NULL)
		{
			cout << aux->getValue() << " "; //Docente 
		//	aux->getLista()->mostrarArray(); // Estudiantes
			aux = aux->getNext();
			 
		}
		cout << endl;
	}

	void buscar(T v)
	{
		Cuarteto <T>* aux; 
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
	string buscarDocenteRecursivo(T v, Cuarteto<T>* p)
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
				res = buscarDocenteRecursivo(v, p->getNext());
			}
		}
		return res;
	}

	string buscarEstudianteRecursivo(T v, Cuarteto<T>* p)
	{
		cout<<"Entra a buscar estudiante"<<endl;
		string res;
		bool found; 
		if (p == NULL){
			res = "Estudiante no encontrado";
		}
		else
		{
			//cout<<"Entra al else"<<endl;
			found = p->getLista()->buscar(v);
			//cout<<"sigue"<<endl;
			if(found){
				res = "Estudiante encontrado";
			} 
			
			else{
				res = buscarEstudianteRecursivo(v, p->getNext());
			}
		}
		return res;
	}
	
	void insertarEnSuLugar(T v){
		
		Cuarteto <T> * t = new Cuarteto <T>();
		t->setValue(v); 


		if(t->getValue() <= first->getValue()){
			insertFirst(v);
		}

		else if( t->getValue() >= last->getValue()){
			insertBack(v);
		}
		
		else {

		Cuarteto <T> *aux = first;

		while(aux->getValue() < t->getValue()){
			aux = aux->getNext(); 
		 } 

		Cuarteto <T> *ant = aux->getPrevious();

		ant->setNext(t);
		aux->setPrevious(t);
		t->setNext(aux);
		}
		
	}
		
	void eliminarElemento(T v){
		
	    Cuarteto<T>* t = new Cuarteto <T>();
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
			Cuarteto <T>* aux = first;  

				while(aux && aux->getValue() != v){
				aux = aux->getNext(); 
				}

			if (aux) {

			Cuarteto <T>* ant = aux->getPrevious();
			Cuarteto <T>* sig = aux->getNext();

			if(ant != NULL){ ant->setNext(sig); } 
			if(sig != NULL){ sig->setPrevious(ant); } 
			}	
		}
	}

	void invertir()  {  

  	  Cuarteto <T> *aux = NULL;  
      Cuarteto <T> *actual = first; 
    
    	while (actual != NULL){
        aux = actual->getPrevious();  
        actual->setPrevious(actual->getNext());  
        actual->setNext(aux);              
        actual = actual->getPrevious();  
    	}  

		swap(first, last);

	}

	T buscarIPos(int pos){

		Cuarteto <T>* aux = first;  
		while(pos > 0){
			aux = aux->getNext();
			pos--; 	
		}
		if(pos < 0){aux = NULL;}
		return aux->getValue(); 
	}


	void deleteList(){

	Cuarteto <T>* actual = first;  
	Cuarteto <T>* next;  
  
	while (actual != NULL){  
   	 next = actual->getNext();  
   	 free(actual);  
     actual = next;  
	}  
	first  = NULL;  
} 

Lista_Listas <T>* fusionarListas(Cuarteto<T>* primeroLista2){
		
		Lista_Listas <int>* lista3 = new Lista_Listas <int>();
		Cuarteto<T>* a = first;
		Cuarteto<T>* b = primeroLista2;  

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

