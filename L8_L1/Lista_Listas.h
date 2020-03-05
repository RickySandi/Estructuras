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

	void insertBack(string estname,T criterio)
	{
		Cuarteto <T>* aux;
		Cuarteto <T>* aux1;
		if (first == NULL)
		{
			first = new Cuarteto <T>();
			first->setValue(criterio);
			last = first;
		    //cout << "se queda aca" << endl; 
			Lista_1* a;
			a = first->getList();
			a->insertarFinal(estname);
			aux1 = new Cuarteto <T>();
			aux1->getList();
		}
		else
		{
			Cuarteto<T>* aux = first;
			Cuarteto<T>* nuevo = NULL;
			while (aux->getValue() != criterio && aux != last) {
				aux = aux->getNext();
			}
			if (aux->getValue() == criterio) {
				aux->getList()->insertarFinal(estname);
			}
			else {
				nuevo = new Cuarteto<T>;
				nuevo->setValue(criterio);
				nuevo->getList()->insertarFinal(estname);
				last->setNext(nuevo);
				nuevo->setPrevious(last);
				last = nuevo;
			}
		}
	}

	void deleteBack()
	{
		Cuarteto <T>* aux;
		Cuarteto <T>* aux1;
		if (first == NULL)
		{
			cout << "Lista Vacia" << endl;
		}
		else
		{
			if (first->getNext() == NULL)
			{
				delete first->getList();
				delete first;
				first = NULL;
				last = NULL;

			}
			else
			{
				aux = last;
				last = last->getPrevious();
				delete aux->getList();
				delete aux;
				last->setNext(NULL);
			}
		}
	}

	Cuarteto<T>* getFirst()
	{
		return first;
	}
	void mostrar()
	{
		Cuarteto <T>* aux;
		aux = first;
		if(aux == NULL){
			cout<<"Lista Vacia"<<endl;
		}
		while (aux != NULL)
		{
			cout << aux->getValue() << endl;
			aux->getList()->imprimirArray();
			aux = aux->getNext();
			//cout<<endl;
		}
		
	}
	bool buscarDocente(T v)
	{
		Cuarteto<T>* aux;
		aux = first;
		bool found = false;
		if (first == NULL)
		{
			cout << "Lista vacia" << endl;
			return false; 
		}
			while (aux != NULL){
				if (v == aux->getValue()){
				cout << "el valor se encuentra en la lista" << endl;
				found = true;
				return found; 
				break;
			}
			aux = aux->getNext();
		}
		if (!found)
		{
			cout<< "el valor no se encuentra en la lista" << endl;
			return found;
		}
	}

	void buscarEstudiante(string est){
		buscarEstudiante1(est,first);
	}

	void buscarEstudiante1(string est, Cuarteto<T>* auxiliar) {
		if (auxiliar!=NULL) {
			if (auxiliar->getList()->buscar(est)) {

				cout << "el estudiante esta Registrado" << endl;
			}
			else {
				buscarEstudiante1(est, auxiliar->getNext());
			}
		}else{
			cout << "el estudiante no se encuentra en la lista" << endl;
		}
	}

	void intercambiarEstudiantes(string doc1, string doc2)
	{
		Cuarteto<T>* aux;
		Cuarteto<T>* aux1;
		Cuarteto<T>* aux2;
		
		aux = first;
		aux1 = NULL;
		aux2 = NULL;
		bool found = false;
		if (first == NULL)
		{
			cout << "Lista vacia" << endl;
		}
		while (aux != NULL) {
			if (doc1 == aux->getValue()) {
				aux1 = aux;
			}
			if (doc2 == aux->getValue()) {
				aux2 = aux;
			}
			aux = aux->getNext();
		}
		Lista_1* aux3 = aux1->getList();
		aux1->setList(aux2->getList());
		aux2->setList(aux3);
		

	}

	// void intercambiarEstudiantes(Cuarteto<T>* docente1, Cuarteto<T>* docente2){

	// 	if( buscarDocente(docente1->getValue()) &&  buscarDocente(docente2->getValue())){
	// 		Lista_1* aux = docente1->getList(); 
	// 		docente1->setList(docente2->getList());
	// 		docente2->setList(aux); 
	// 	}
	// 	else{
	// 		cout<<"Docente inexistente"<<endl; 
	// 	}
	// }


	~Lista_Listas() {

	}

};

