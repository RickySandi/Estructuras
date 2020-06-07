#include "grafo.h"
using namespace std; 
int main()
{
    // int graph[V][V] = { {0, 16, 13, 0, 0, 0},
    //                     {0, 0, 10, 12, 0, 0},
    //                     {0, 4, 0, 0, 14, 0},
    //                     {0, 0, 9, 0, 0, 20},
    //                     {0, 0, 0, 7, 0, 4},
    //                     {0, 0, 0, 0, 0, 0}
    //                   };
 
    //minCut(graph, 0, 5);



    int graph [6][6]; 
    leerArchivo(graph);
    imprimirArchivo(graph); 
    return 0;
}

/*   1-3   
     4-3
     4-5
*/