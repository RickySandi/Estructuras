#pragma once
#include <iostream>
#include "Grafo.h"
#include"Vertice.h"
#include <map>
#include <vector>
#include <queue>
#include <list>
#include <cstring>
#include <fstream>

using namespace std;

void mostrarMenu() 
{
//    Grafo<int>* grafo = new Grafo<int>(); //char 
//    int origen, destino;
//    int arista;
//    fstream archEntrada; 
    map <string,vector < pair <string,int> > > grafo;
	Grafo<string>* grafo2 = new Grafo<string>(); 
    map <string,int> distancias;
    int conex;
    string ori,dest;
	char origen2, destino2; 
	fstream archEntrada;

   int op;
	do
	{
		cout << "---MENU---"<<endl;
		cout << "1. Llenar Grafo"<<endl;
		cout << "2. Eliminar Arista - (FALTA)"<<endl;
		cout << "3. Mostrar Lista Adyacencia"<<endl;
		cout << "4. Dijkstra"<<endl;
		cout << "5. Mostrar camino - (FALTA)"<<endl;  //Para mostrar el camino, primero se lo debe buscar!!
		cout << "6.Insertar Arista"<<endl;
		cout << "7.Insertar Archivo"<<endl;
		cout << "8.Salir"<<endl;
	
		
		
		cout<<"Ingresa una opcion"<<endl; 
		cin >> op;
		
		switch (op)
		{
		
		case 1:
		cout<<"Introduce el numero de aristas ";
    	cin>>conex;
    	grafo2->llenarGrafo(grafo,distancias,conex);
			break;
		case 2:
			cout<<"origen y el destino"<<endl;
			cin>>ori>>dest;
			grafo2->eliminarArista(ori,dest);
			break;
		case 3:
			grafo2->MostrarGrafo(grafo, distancias);
			break;
		case 4:
  			cout<<"Introduce el nodo ORIGEN ";
    		cin>>ori;
			//grafo2->Dijkstra(ori);
    		//grafo2->Dijkstra(grafo,distancias,ori);
			break;
		case 5:
			cout<<"Ingresa el origen y destino"<<endl; 
			cin>>ori>>dest; 
			grafo2->mostrarCamino(ori,dest);
			break;
		case 6:
		cout<<"Ingresa el origen y destino"<<endl; 
		cin>>ori>>dest; 
		grafo2->insertarArista(ori,dest); 

		case 7:
             archEntrada.open("grafo.txt");
            while (!archEntrada.eof() && archEntrada >> ori >> dest)
            {  //grafo->inicializarVector(vecRepeticiones); 
               grafo2->insertarArista(ori, dest);
            }
            archEntrada.close();
		}
		
	} while (op != 8);
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

// 	string user;
//     int ascChar;

//     getline(cin, user);

//    //cout << user << endl;

//     for (int i=0;i<user.length();i++)
//     {
//         ascChar = user[i];
//         cout << ascChar << endl;
//     }





}
