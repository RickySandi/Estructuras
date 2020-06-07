#include <iostream>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <queue>
#include "fstream"
#define V 6
using namespace std;
 
/*
 * Returns true if there is a path from source 's' to sink 't' in
 * residual graph. Also fills parent[] to store the path
 */
fstream archEntrada;

int bfs(int rGraph[V][V], int s, int t, int parent[])
{
    bool visited[V];
    memset(visited, 0, sizeof(visited));
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < V; v++)
        {
            if (visited[v] == false && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return (visited[t] == true);
}
 
/*
 *  A DFS based function to find all reachable vertices from s.
 */
void dfs(int rGraph[V][V], int s, bool visited[])
{
    visited[s] = true;
    for (int i = 0; i < V; i++)
    {
        if (rGraph[s][i] && !visited[i])
           dfs(rGraph, i, visited);
    }
}
 
/*
 * Prints the minimum s-t cut
 */
void minCut(int graph[V][V], int origen, int destino)   // s t 
{
    int u, v;
    int rGraph[V][V];
    for (u = 0; u < V; u++)
    {
        for (v = 0; v < V; v++)
             rGraph[u][v] = graph[u][v];
    }
    int parent[V];
    while (bfs(rGraph, origen, destino, parent))
    {
        int path_flow = 65536; //256 al cuadrado
        for (v = destino; v != origen; v = parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
        for (v = destino; v != origen; v = parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
    }
    bool visited[V];
    int cortes = 0; 
    memset(visited, 0, sizeof(visited));
    dfs(rGraph, origen, visited);
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
           
            if (visited[i] && !visited[j] && graph[i][j]){
                cout << i << " - " << j << endl;
                cortes++; 
            }
                
        }
    }
    cout<<"Numero de cortes: "<<cortes<<endl; 
}
void insertarGrafo(int graph[V][V], int i, int j, int peso){
    
    graph[i][j] =  peso;
}

void leerArchivo(int graph[V][V]){

   int peso;   
   int i =0, j=0; 
   archEntrada.open("minCut.txt");
            while (!archEntrada.eof() && archEntrada >> peso)
            {
                insertarGrafo(graph, i,j,peso);
                j++;
                if(j>= V){
                    cout << endl;
                    i++;
                    j=0; 
                }

            }
    archEntrada.close();
}





void imprimirArchivo(int graph[V][V]){
         for(int i=0; i<V;i++){
            for(int j=0; j<V;j++){
                cout<<graph[i][j] << " ";
            }
            cout<<endl; 
        }

}








/*
 * Main Contains Menu
 */ 