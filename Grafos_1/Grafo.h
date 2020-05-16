#pragma once
#include"Vertice.h"
#include"Lista_8.h"
#include"Terna.h"
#include<fstream>
#include<vector>
#define TAM 300
template<class T>
class Grafo
{
private:
	//vector<Vertice<T>*> vec; 
	Vertice<T>*  vec[300]; 
	Lista_8<T> cola;
	fstream archivo;
public:
Grafo(){
     for (int i=0 ; i < TAM ; i++) {
         vec[i] = new Vertice<T>();
     }
}

~Grafo(){
}

	void inicializar(){
		cout<<" no entra"<<endl;
		for (int i = 0; i < TAM; i++){
			cout<<"entra"<<endl;
		vec[i]->setMarca(false); 
		cout<<"entra"<<endl;
		vec[i]->setPadre(-1);
	}
	}
	
	void insertarArista(T vertice1, T vertice2){
	//if (vec[vertice1].getExiste()==false)
	//{
		vec[vertice1]->setNombre(vertice1);
		vec[vertice1]->setExiste(true);
		vec[vertice1]->insertarFinalLista8(vertice2);
	//}
	//if (vec[vertice2].getExiste() == false)
	//{
		vec[vertice2]->setNombre(vertice2);
		vec[vertice2]->setExiste(true);
		vec[vertice2]->insertarFinalLista8(vertice1);
	//}
	}
	void mostrarTodo(){
		for (int i = 0; i < TAM; i++){
			if (vec[i]->getExiste() != false){
				cout << "Vertice: "<<vec[i]->getNombre() << endl;
				cout << "Adyacentes:" << endl;
				vec[i]->mostrarLista8();
				}
		}
	}
	
bool busquedaAmplitud(T origen, T destino)
{
	bool encontre=false;
	vec[origen]->setMarca(true);
	cola.insertBack(origen);
	while (cola.getExiste() != false && encontre == false)
	{
		int i_esimo = 1;
		Terna<T>*adyacente=new Terna<T>;
		T vertice = cola.getPrimero()->getValue();
		cola.deleteFirst();
		adyacente = vec[vertice]->sacarSiguienteAdyacente(i_esimo);
		while (adyacente != NULL && encontre == false)
		{
			if (vec[adyacente->getValue()]->getMarca() == false)
			{
				vec[adyacente->getValue()]->setPadre(vertice);
				if (adyacente->getValue() == destino)
					encontre = true;
				else{
					vec[adyacente->getValue()]->setMarca(true);
					cola.insertBack(adyacente->getValue());
				}
			}
			i_esimo++;
			adyacente=vec[vertice]->sacarSiguienteAdyacente(i_esimo);
		}
	}
	return encontre;
}

bool busquedaProfundidad(T origen, T destino)
{
	bool encontre = false;
	vec[origen]->setMarca(true);
	int i_esimo = 1;
	Terna<T>*adyacente=vec[origen]->sacarSiguienteAdyacente(i_esimo);
	while (adyacente != NULL)
	{
		if (encontre == false && vec[adyacente->getValue()]->getMarca() == false)
		{
			vec[adyacente->getValue()]->setPadre(origen);
			if (adyacente->getValue() == destino)
				encontre = true;
			else
				encontre=busquedaProfundidad(adyacente->getValue(), destino);

		}
		i_esimo++;
		adyacente= vec[origen]->sacarSiguienteAdyacente(i_esimo);
	}
	return encontre;
}

void mostrarCamino(int origen, int destino)
{
	int aux = destino;
	while (aux != origen)
	{
		cout << aux << " <- ";
		aux = vec[aux]->getPadre();
	}
	cout << origen << endl;
}

void busquedaAmplitudParaTodosVertices2(T origen)
{
	for (int i = 0; i < TAM; i++)
	{
		if (vec[i]->getExiste() == true)
		{
			busquedaAmplitud(origen, i);
			mostrarCamino(origen, i);
		}
	}
}
int numeroVertices(){
	int cont = 0; 
	for (int i = 0; i < TAM; i++){
		if (vec[i]->getExiste() != false){
				cont++;
	}
 }
	return cont; 
}		
void eliminarArista(T v){
	for (int i = 0; i < TAM; i++){
		if (vec[i]->getNombre() == v){
			vec[i]->eliminarArista(v); 
	}
 }
}
};