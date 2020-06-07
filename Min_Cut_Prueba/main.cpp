#include "Grafo.h"
#define TAM 10 // TAM 10 para porbar con min.txt   TAM 6 para porbar con minCut.txt 
using namespace std; 
int main()
{
    int graph [TAM][TAM]; 
    leerArchivo(graph);
    minCut(graph, 0, 9);        // 0,   TAM-1





}
//El archivo de lectura es la Matriz de Ayacencia de los pesos