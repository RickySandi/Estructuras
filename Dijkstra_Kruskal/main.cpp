//
//  main.cpp
//  DijkstraKruskal
//
//  Created by MacBook Air on 11/18/18.
//  Copyright © 2018 MacBook Air. All rights reserved.
//

#include <iostream>
using namespace std;
#include "Grafo.h"

void Menu()
{
    int origen, destino;
    int op=-1, peso,total;
    bool resp;
    Grafo grafo,AE;
    cout << "1. Insertar Arista" << endl;
    cout << "2. Mostrar adyacencias" << endl;
    cout << "3. Eliminar" << endl;
    cout << "4. BFS" << endl;
    cout << "5. DFS" << endl;
    cout << "6. Mostrar Caminos" << endl;
    cout << "7. Defensa." << endl;
    cout << "8. Kruskal" << endl;
    cout<< "9. Dijkstra" <<endl;
    cout<<"10. Defensa Archivo"<<endl;
    cout << "0. Salir" << endl;
    while(op!=0)
    {
        //system("cls");
        cin >> op;
        if(op==1){
                
                cout << "origen: ";
                cin >> origen;
                cout << "destino: ";
                cin >> destino;
                cout << "peso: ";
                cin >> peso;
                grafo.insertarArista(origen, destino, peso);
        }
        if(op==2){
                grafo.mostrarAdyacentes();
        }
    
    
        if(op==3){
                cout << "ingresar origen: ";
                cin >> origen;
                cout << "ingresar destino: ";
                cin >> destino;
                resp = grafo.eliminarArista(origen, destino);
                if (resp == true)
                {
                    cout << "Arista elminada" << endl;
                }
                else
                    cout << "no se encontro" << endl;
                }
        if(op==4){
                cout << "origen: ";
                cin >> origen;
                cout << "destino: ";
                cin >> destino;
                grafo.inicializarBusqueda();
                resp = grafo.busquedaAmplitud(origen, destino);
                if (resp == true)
                {
                    cout << "Arista encontrada" << endl;
                }
                else
                    cout << "No encontrada" << endl;
                }
        if(op==5){
                cout << "origen: ";
                cin >> origen;
                cout << "destino: ";
                cin >> destino;
                grafo.inicializarBusqueda();
                resp = grafo.busquedaProfundidad(origen, destino);
                if (resp == true)
                {
                    cout << "Arista encontrada" << endl;
                }
                else
                    cout << "No encontrada" << endl;
                }
            if(op==6){
                
                cout << "origen: ";
                cin >> origen;
                cout << "destino: ";
                cin >> destino;
                grafo.mostrarCamino(origen, destino);
            }
            if(op==7){
                cout << "origen: ";
                cin >> origen;
                grafo.caminoMinimoATodos(origen);
            }
        
            if(op==8){
                grafo.inicializarBusqueda();
                total=grafo.Kruskal(AE);
                AE.mostrarKruskal();
                cout << "Total " << total;
            }
        if(op==9){
            grafo.inicializarBusqueda();
            cout << "origen: ";
            cin >> origen;
            grafo.Dijkstra(origen);
            for (int i = 1; i <100; i++)
            {
                grafo.mostrarDijkstra(origen, i);
            }
        }
        }
        
       // system("pause");
        
    }

int main() {
    Menu();
    
    //prueba
  
    return 0;
}
