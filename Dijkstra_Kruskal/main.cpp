#include <iostream>
#include "Grafo.h"
#include <fstream>
using namespace std;

void Menu()
{
    int origen, destino; //int 
    int peso,total;
    bool resp;
    Grafo grafo,AE;
    fstream archEntrada;

    int op;
	do
	{
    cout << "1. Insertar Arista" << endl;
    cout << "2. Mostrar adyacencias" << endl;
    cout << "3. Eliminar" << endl;
    cout << "4. BFS" << endl;
    cout << "5. DFS" << endl;
    cout << "6. Mostrar Caminos" << endl;
    cout << "7. Camino Minimo a todos" << endl;
    cout << "8. Kruskal" << endl;
    cout<<  "9. Dijkstra" <<endl;
    cout << "10. Leer archivo" << endl;
    cout << "11. Salir" << endl;

    cout<<"Ingresa una opcion"<<endl; 
	cin >> op;
		
	switch (op)
	{
    case 1:
        cout << "origen: ";
        cin >> origen;
        cout << "destino: ";
        cin >> destino;
        cout << "peso: ";
        cin >> peso;
        grafo.insertarArista(origen, destino, peso);
    break;      

    case 2:
        grafo.mostrarAdyacentes();
    break;
    
    case 3:
        cout << "ingresar origen: ";
        cin >> origen;
        cout << "ingresar destino: ";
        cin >> destino;
        resp = grafo.eliminarArista(origen, destino);
        if (resp){
            cout << "Arista elminada" << endl;
        }
        else{
            cout << "no se encontro" << endl;
        }
    break; 
                    
    case 4:
        cout << "origen: ";
        cin >> origen;
        cout << "destino: ";
        cin >> destino;
        grafo.inicializarBusqueda();
        resp = grafo.busquedaAmplitud(origen, destino);
        if (resp){
            cout << "Arista encontrada" << endl;
        }
        else{
            cout << "No encontrada" << endl;
        }
    break; 

    case 5:
        cout << "origen: ";
        cin >> origen;
        cout << "destino: ";
        cin >> destino;
        grafo.inicializarBusqueda();
        resp = grafo.busquedaProfundidad(origen, destino);
            if (resp){
                cout << "Arista encontrada" << endl;
            }
            else{
                cout << "No encontrada" << endl;
            }
    break; 
    
    case 6: 
        cout << "origen: ";
        cin >> origen;
        cout << "destino: ";
        cin >> destino;
        grafo.mostrarCamino(origen, destino);
    break; 

    case 7:
        cout << "origen: ";
        cin >> origen;
        grafo.caminoMinimoATodos(origen);
    break;
        
    case 8:
        grafo.inicializarBusqueda();
        total=grafo.Kruskal(AE);
        AE.mostrarKruskal();
        cout << "Total " << total<<endl;
    break;

    case 9:
        grafo.inicializarBusqueda();
        cout << "origen: ";
        cin >> origen;
        grafo.Dijkstra(origen);

        for (int i = 1; i <100; i++){
            grafo.mostrarDijkstra(origen, i);
        }
    case 10:
        archEntrada.open("grafo_2.txt");
            while (!archEntrada.eof() && archEntrada >> origen >> destino >> peso)
            { 
                grafo.insertarArista(origen, destino, peso);
            }
        archEntrada.close();
    }
    } while (op != 11);
}

int main() {
    Menu();
    
    //prueba
  
    return 0;
}
