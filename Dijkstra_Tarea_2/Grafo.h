#pragma once
#include"Vertice.h"
#include"Lista_8.h"
#include"Terna.h"
#include<fstream>
#include<vector>
#include <queue>
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
		for (int i = 0; i < TAM; i++){
		vec[i]->setMarca(false); 
		vec[i]->setPadre(-1);
		vec[i]->setDistancia(999999);
	}
	}
	
	void insertarArista(T vertice1, T vertice2){ //vector<int>vecRepeticiones
	
		vec[vertice1]->setNombre(vertice1);
		vec[vertice1]->setExiste(true);
		vec[vertice1]->insertarFinalLista8(vertice2);

		vec[vertice2]->setNombre(vertice2);
		vec[vertice2]->setExiste(true);
		vec[vertice2]->insertarFinalLista8(vertice1);

		//contando
		//vecRepeticiones[vertice2] += 1; 	
	
	}

	
bool BFS(T origen, T destino)
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

bool DFS(T origen, T destino)
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
				encontre=DFS(adyacente->getValue(), destino);

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
//Defensa Mostrar y nodo que mas veces es destino 
void mostrarGrafo()
{
	for (int i = 0; i < TAM; i++)
	{
		if (vec[i]->getExiste() != false)
		{
			cout << "Vertice: "<<vec[i]->getNombre() << endl;
			cout << "Adyacentes:" << endl;
			vec[i]->mostrarLista8();
		}
	}
}
// void Dijkstra(int origen)
// {
// 	int vertice, distancia;
// 	Terna<int> *Ady;
// 	 priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 
// 	vec[origen]->setDistancia(0);
	
// 	i.first = vec[origen].getDistancia();
// 	pq.second.first = origen;
// 	cola.push(pq);
// 	while (!cola.empty())
// 	{
// 		pq = cola.top();
// 		cola.pop();
// 		vertice = pq.second.first;
// 		if (vec[vertice].getMarca() == false)
// 		{
// 			vec[vertice].setMarca(true);
// 			Ady = vec[vertice].getList()->getPrimero();
// 			while (Ady != NULL)
// 			{
// 				if (vec[Ady->getValue()].getMarca() == false && Ady->getPeso()>0)
// 				{
// 					if (vec	[vertice].getDistancia() + Ady->getPeso()<vec[Ady->getValue()].getDistancia())
// 					{
// 						vec[Ady->getValue()].setDistancia(vec[vertice].getDistancia() + Ady->getPeso());
// 						vec[Ady->getValue()].setPadre(vertice);
// 						pq.first = vec[Ady->getValue()].getDistancia();
// 						pq.second.first = Ady->getValue();
// 						pq.second.second = 0;
// 						cola.push(pq);
// 					}
// 				}
// 				Ady = Ady->getNext();
// 			}
// 		}

// 	}
// }

};