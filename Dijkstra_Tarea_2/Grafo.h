#pragma once
#include"Vertice.h"
#include"Lista_8.h"
#include"Terna.h"
#include<fstream>
#include<vector>
#include <queue>
#include <map>
#include <list>
#include <cstring>
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
// Algoritmo para introducir datos en el GRAFO y distancias
void llenarGrafo(map<string,vector<pair<string,int> > > &grafo, map<string,int> &dis,int conex)
{
    pair  <string,int> aux;
    string nodo1,nodo2;
    int peso;

    for(int c=0;c<conex;c++)
    {   cout<<"Introduce dos nodos y el peso de la arista que los conecta: ";
        cin>>nodo1>>nodo2>>peso;
        aux.first=nodo2;
        aux.second=peso;
        grafo[nodo1].push_back(aux);
        grafo[nodo2]; //para crear el vertice en la LISTA
        dis[nodo1]=999999;
        dis[nodo2]=999999;
        // Si fuera vector de enteros memset(distancias,999999,sizeof(distancias));
    }
}

// Algoritmo para Mostrar el GRAFO y las Distancias
void MostrarGrafo(map<string,vector<pair<string,int> > > grafo,map<string,int> dis)
{
    map <string,vector < pair <string,int> > >::iterator iter;
    map <string,int> ::iterator itd;
    //Muestra grafo
	cout<<"Mostrado Grafo"<<endl; 
    for(iter=grafo.begin();iter!=grafo.end();iter++)
    {
         cout<<endl<<(*iter).first<<" : "<<endl;
         for(int c=0;c<(*iter).second.size();c++)
            cout<<" " << (*iter).second[c].first<<"/" <<(*iter).second[c].second<<", ";
    }
    //Muestra distancias
	cout<<"Mostrado Distancias"<<endl;
    for(itd=dis.begin();itd!=dis.end();itd++)
           cout<<(*itd).first<<" = "<<(*itd).second<<endl;
}


// Dikjstra Entrada: GRAFO y Salida: distancias
void Dikjstra(map<string,vector<pair<string,int> > > grafo,map<string,int> &distancias, string ori)
{
    queue <string> cola;
    cola.push(ori);
    distancias[ori]=0;
    while(!cola.empty())
    {   string origen=cola.front();
        for(int c=0;c<grafo[origen].size();c++)
        {
            string destino=grafo[origen][c].first;
            if(distancias[origen] + grafo[origen][c].second<distancias[destino])
            {
                distancias[destino]=distancias[origen] + grafo[origen][c].second;
                cola.push(destino);
            }
        }
        cola.pop();
    }
}
void mostrarCamino(char origen, char destino)    
{
	char aux = destino;
	int pos =aux-65; 
	while (aux != origen)
	{
		cout << aux << " <- ";
		aux = vec[pos]->getPadre();
	}
	cout << origen << endl;
}
		
void eliminarArista(T v){
	for (int i = 0; i < TAM; i++){
		if (vec[i]->getNombre() == v){
			vec[i]->eliminarArista(v); 
	} 
 }
}








};