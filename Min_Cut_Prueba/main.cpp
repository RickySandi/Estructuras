#include "grafo.h"
#define TAM 6  // TAM 26 para porbar con letras
using namespace std; 
int main()
{
    int graph [TAM][TAM]; 
    leerArchivo(graph);
    minCut(graph, 0, 5);        // 0, TAM-1





}
//El archivo de lectura es la Matriz de Ayacencia de los pesos