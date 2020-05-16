#pragma once
#include <iostream>
#include "Grafo.h"
#include"Vertice.h"
using namespace std;

void mostrarMenu() 
{
   Grafo<int>* grafo = new Grafo<int>();
   int origen, destino;

   int op;
	do
	{
		cout << "---MENU---"<<endl;
		cout << "1. Insertar arista"<<endl;
		cout << "2. Mostrar Todo"<<endl;
		cout << "3. Busqueda en Amplitud"<<endl;
		cout << "4. Busqueda en Profundidad"<<endl;
		cout << "5. Mostra Camino Destino al Origen"<<endl;
		cout << "6. Leer archivo de txt"<<endl;
		cout << "7. busquedaAmplitudParaTodosVertices"<<endl;
		cout << "0. Salir"<<endl;
		cin >> op;
		
		switch (op)
		{
		case 1:
			cout << "Ingrese el origen: "<<endl;
			cin >> origen; //origen 
			cout << "Ingrese el destino: "<<endl;
			cin >> destino; // destino 
			grafo->insertar(origen, destino);
			break;
		case 2:
			grafo->mostrarTodo();
			break;
		case 3:
			cout << "Ingrese el origen: "<<endl;
			cin >> origen;
			cout << "Ingrese el destino: "<<endl;
			cin >> destino;
			grafo->inicializar();
			if (grafo->busquedaAmplitud(origen, destino))
				cout << "Camino Encontrado" << endl;
			else
				cout << "Camino no existe" << endl;
			break;
		case 4:
			cout << "Ingrese el origen: "<<endl;
			cin >> origen;
			cout << "Ingrese el destino: "<<endl;
			cin >> destino;
			grafo->inicializar();
			if (grafo->busquedaProfundidad(origen, destino))
				cout << "Camino encontrado"<<endl;
			else
				cout << "Camino no encontrado"<<endl;
			break;
		case 5:
			cout << "Ingrese el origen: "<<endl;
			cin >> origen;
			cout << "Ingrese el destino: "<<endl;
			cin >> destino;
			grafo->mostrarCamino(origen, destino);
			break;
		case 6:
			// if (grafo->leerArchivo("PRUEBA Min Cut.txt"))
			// 	cout << "Archivo leido correctamente" << endl;
			break;
		case 7:
			cout << "Ingrese el origen: "<<endl;
			cin >> origen;
			grafo->busquedaAmplitudParaTodosVertices2(origen);
			break;
		}
	} while (op != 0);
}

int main(){

    mostrarMenu();


}   