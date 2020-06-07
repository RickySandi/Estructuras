#include <iostream>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <queue>
#include "fstream"
#define TAM 10  // TAM 10 para porbar con min.txt   TAM 6 para porbar con minCut.txt 
using namespace std;

fstream archEntrada;

int busquedaAmplitud(int grafo[TAM][TAM], int origen, int destino, int parent[]){
    bool visited[TAM];
    memset(visited, 0, sizeof(visited));
    queue <int> q;
    q.push(origen);
    visited[origen] = true;
    parent[origen] = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < TAM; v++)
        {
            if (visited[v] == false && grafo[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return (visited[destino] == true);
}
 
/*
 *  A DFS based function to find all reachable vertices from s.
 */
void busquedaProfundidad(int grafo[TAM][TAM], int origen, bool visited[]){
    visited[origen] = true;
    for (int i = 0; i < TAM; i++)
    {
        if (grafo[origen][i] && !visited[i])
           busquedaProfundidad(grafo, i, visited);
    }
}

char intToChar(int num){
    //char charsArray[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char charsArray[] = {'A','B','C','D','E','F','G','H','X','Y'};
    
    return charsArray[num];
    
}
 

void minCut(int grafo[TAM][TAM], int origen, int destino) {
    int u, v;
    int grafoAux[TAM][TAM];
    for (u = 0; u < TAM; u++)
    {
        for (v = 0; v < TAM; v++)
             grafoAux[u][v] = grafo[u][v];
    }
    int parent[TAM];
    while (busquedaAmplitud(grafoAux, origen, destino, parent))
    {
        int path_flow = 65536; //256 al cuadrado
        for (v = destino; v != origen; v = parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, grafoAux[u][v]);
        }
        for (v = destino; v != origen; v = parent[v])
        {
            u = parent[v];
            grafoAux[u][v] -= path_flow;
            grafoAux[v][u] += path_flow;
        }
    }
    bool visited[TAM];
    int cortes = 0; 
    memset(visited, 0, sizeof(visited));
    busquedaProfundidad(grafoAux, origen, visited);

    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
           
            if (visited[i] && !visited[j] && grafo[i][j]){
                //cout << i << " - " << j << endl;                         //Para probar con minCut.txt
                cout << intToChar(i) << " - " << intToChar(j) << endl;    //Para probar ccon min.txt
                cortes++; 
            }
                
        }
    }
    cout<<"Numero de cortes: "<<cortes<<endl; 
}
void insertarPeso(int grafo[TAM][TAM], int i, int j, int peso){
    
    grafo[i][j] =  peso;
}

void leerArchivo(int grafo[TAM][TAM]){

   int peso;   
   int i =0, j=0; 
   archEntrada.open("min.txt"); //leer archivo min.txt para probar con letras   minCut.txt para probar con numeros 
            while (!archEntrada.eof() && archEntrada >> peso)
            {
                insertarPeso(grafo,i,j,peso);
                j++;
                if(j>= TAM){
                    i++;
                    j=0; 
                }

            }
    archEntrada.close();
}

void imprimirArchivo(int grafo[TAM][TAM]){
         for(int i=0; i<TAM;i++){
            for(int j=0; j<TAM;j++){
                cout<<grafo[i][j] << " ";
            }
            cout<<endl; 
        }

}
