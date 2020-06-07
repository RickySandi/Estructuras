#include "Grafo.h"
#define TAM 10 // TAM 10 para porbar con min.txt   TAM 6 para porbar con minCut.txt 
using namespace std; 

void mostrarMenu() 
{
    int grafo[TAM][TAM]; 
    int op;
  
   
    do {
        cout << "-----MENU-----" << endl;
        cout << "1.Leer Archivo" << endl;
        cout << "2.Min Cut" << endl;
        cout << "3.Salir" << endl;
        
        cout << endl;
        cout << "Ingresa una opcion" << endl;
        cin >> op;
        switch (op)
        {
        case 1:
            leerArchivo(grafo); 
            break;
        case 2:
          minCut(grafo,0,TAM-1);
        case 3:    
            break; 

        default:
            break;
        }
        
    } while (op != 3);
}

int main()
{
    mostrarMenu();
    // int graph [TAM][TAM]; 
    // leerArchivo(graph);
    // minCut(graph, 0, 9);        // 0,   TAM-1





}
//El archivo de lectura es la Matriz de Ayacencia de los pesos