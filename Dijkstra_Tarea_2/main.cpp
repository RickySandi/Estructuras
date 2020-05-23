#pragma once
#include <iostream>
#include "Grafo.h"
#include"Vertice.h"
#include <map>
#include <vector>
#include <queue>
#include <list>
#include <cstring>

using namespace std;

void mostrarMenu() 
{
//    Grafo<int>* grafo = new Grafo<int>(); //char 
//    int origen, destino;
//    int arista;
//    fstream archEntrada; 
    map <string,vector < pair <string,int> > > grafo;
	Grafo<int>* grafo2 = new Grafo<int>(); 
    map <string,int> distancias;
    int conex;
    string ori,dest;
	char origen2, destino2; 

   int op;
	do
	{
		cout << "---MENU---"<<endl;
		cout << "1. Insertar Arista"<<endl;
		cout << "2. Eliminar Arista - (FALTA)"<<endl;
		cout << "3. Mostrar Lista Adyacencia"<<endl;
		cout << "4. Dijkstra"<<endl;
		cout << "5. Mostrar camino - (FALTA)"<<endl;  //Para mostrar el camino, primero se lo debe buscar!!
		cout << "6.Salir"<<endl;

		cout << "7. Inicializar Padre y Marca"<<endl;
		cout << "8. Mostrar Grafo"<<endl;
		cout << "9. Insertar archivo"<<endl;
		cout<<  "10. Dijkstra"<<endl; 
		
		
		cout<<"Ingresa una opcion"<<endl; 
		cin >> op;
		
		switch (op)
		{
		
		case 1:
		cout<<"Introduce el numero de aristas ";
    	cin>>conex;
    	grafo2->llenarGrafo(grafo,distancias,conex);
			break;
		// case 2:
		// 	cout<<"Ingresa la arista a eliminar"<<endl;
		// 	cin>>arista;
		// 	grafo->eliminarArista(arista);
		// 	break;
		case 3:
			grafo2->MostrarGrafo(grafo, distancias);
			break;
		case 4:
  			cout<<"Introduce el nodo ORIGEN ";
    		cin>>ori;
    		grafo2->Dikjstra(grafo,distancias,ori);
			break;
		case 5:
			cout<<"Ingresa el origen y destino"<<endl; 
			cin>>ori>>dest; 
			grafo2->mostrarCamino(origen2,destino2);
			break;
		
		// case 9:
        //      archEntrada.open("grafo.txt");
        //     while (!archEntrada.eof() && archEntrada >> origen >> destino)
        //     {  //grafo->inicializarVector(vecRepeticiones); 
        //        grafo->insertarArista(origen, destino);
        //     }
        //     archEntrada.close();
		}
		
	} while (op != 6);
}

int main(){

       mostrarMenu();


    // map <string,vector < pair <string,int> > > grafo;
	// Grafo<int>* grafo2 = new Grafo<int>(); 
    // map <string,int> distancias;
    // int conex;
    // string ori;

    // cout<<"Introduce el numero de aristas ";
    // cin>>conex;
    // grafo2->llenarGrafo(grafo,distancias,conex);

    // cout<<"Introduce el nodo ORIGEN ";
    // cin>>ori;
    // grafo2->Dikjstra(grafo,distancias,ori);

    // cout<<"el proceso devuelve "<<endl;
    // grafo2->MostrarGrafo(grafo, distancias);




}
