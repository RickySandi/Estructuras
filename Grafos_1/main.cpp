#pragma once
#include <iostream>
#include "Grafo.h"
#include"Vertice.h"
using namespace std;

void mostrarMenu() 
{
   Grafo<int>* grafo = new Grafo<int>();
   int origen, destino;
   int arista; 

   int op;
	do
	{
		cout << "---MENU---"<<endl;
		cout << "1. Busqueda Amplitud - BFS"<<endl;
		cout << "2. Busqueda Profundidad - DFS"<<endl;
		cout << "3. Insertar Arista"<<endl;
		cout << "4. Eliminar Arista"<<endl;
		cout << "5. Definir numero de Vertices"<<endl;
		cout << "6. Mostrar camino"<<endl;  //Para mostrar el camino, primero se lo debe buscar!!
		cout << "7. Inicializar Padre y Marca"<<endl;
		cout << "8. Salir"<<endl;
		
		cout<<"Ingresa una opcion"<<endl; 
		cin >> op;
		
		switch (op)
		{
		case 1:
			cout << "Ingrese el origen: "<<endl;
			cin >> origen;
			cout << "Ingrese el destino: "<<endl;
			cin >> destino;
			grafo->inicializar();
			if (grafo->BFS(origen, destino))
				cout << "Camino Encontrado" << endl;
			else
				cout << "Camino no existe" << endl;
			break;
		case 2:
			cout << "Ingrese el origen: "<<endl; // optimizar en una funcion 
			cin >> origen;
			cout << "Ingrese el destino: "<<endl;
			cin >> destino;
			grafo->inicializar();
			if (grafo->DFS(origen, destino))
				cout << "Camino encontrado"<<endl;
			else
				cout << "Camino no encontrado"<<endl;
			break;
		case 3:
			cout << "Ingrese el origen: "<<endl;
			cin >> origen; //origen 
			cout << "Ingrese el destino: "<<endl;
			cin >> destino; // destino 
			grafo->insertarArista(origen, destino);
			break;
		case 4:
			cout<<"Ingresa la arista a eliminar"<<endl;
			cin>>arista;
			grafo->eliminarArista(arista);
			break;
		case 5:
			cout << "El grafo tiene "<<grafo->numeroVertices()<<"vertices"<<endl;
			break;
		case 6:
			cout << "Ingrese el origen: "<<endl;
			cin >> origen; //origen 
			cout << "Ingrese el destino: "<<endl;
			cin >> destino; // destino 
			grafo->mostrarCamino(origen, destino); 
			break;
		case 7:
			grafo->inicializar();
			cout<<"Padre y Marca inicializados"<<endl; 
			break;
		}
		
	} while (op != 8);
}

int main(){

    mostrarMenu();


}   
