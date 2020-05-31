#ifndef Grafo_h
#define Grafo_h

#include"Vertice.h"
#include <queue>
#include <functional>
#include <fstream>
typedef pair<int, pair<int, int>>pi;

class Grafo
{
private:
    
    Vertice<int> vec[100];
    int iesimo;
public:
    
    Grafo();
    ~Grafo();
    void insertarArista(int origen, int destino, int peso);
    bool busquedaAmplitud(int origen, int destino);
    bool busquedaProfundidad(int origen, int destino);
    void mostrarAdyacentes();
    bool eliminarArista(int origen, int destino);
    void inicializarBusqueda();
    void mostrarCamino(int origen, int destino);
    void caminoMinimoATodos(int origen);
    int Kruskal(Grafo &AE);
    void leerArchivo();
    void mostrarKruskal();
    void Dijkstra(int origen);
    void mostrarDijkstra(int ori, int dest);
    int BuscarCiclo(int x);
};

Grafo::Grafo()
{
}

Grafo::~Grafo()
{
}

void Grafo::insertarArista(int origen, int destino, int peso)
{
    vec[origen].getList()->insertarFinal(destino, peso);
    vec[destino].getList()->insertarFinal(origen, peso);
    //vec[origen].setInsertado(true);
}

bool Grafo::busquedaAmplitud(int origen, int destino)
{
    int vert;
    queue<int> cola;
    Nodo<int>* adyacente;
    bool encontre = false;
    vec[origen].setMarca(true);
    cola.push(origen);
    
    while (!cola.empty() && encontre == false)
    {
        iesimo = 1;
        vert = cola.front();
        cola.pop();
        adyacente = vec[vert].getList()->ElementoIPosicion(iesimo);
        while (adyacente != NULL && encontre == false)
        {
            if (vec[adyacente->getElemento()].getMarca() == false)
            {
                vec[adyacente->getElemento()].setPadre(vert);
                if (adyacente->getElemento() == destino)
                    encontre = true;
                else
                {
                    vec[adyacente->getElemento()].setMarca(true);
                    cola.push(adyacente->getElemento());
                }
            }
            iesimo = iesimo + 1;
            adyacente = vec[vert].getList()->ElementoIPosicion(iesimo);
        }
    }
    
    return encontre;
}

bool Grafo::busquedaProfundidad(int origen, int destino)
{
    queue<int> cola;
    Nodo<int>* adyacente;
    bool encontreCamino = false;
    vec[origen].setMarca(true);
    iesimo = 1;
    adyacente = vec[origen].getList()->ElementoIPosicion(iesimo);
    while (adyacente != NULL) {
        if (encontreCamino == false && vec[adyacente->getElemento()].getMarca() == false)
        {
            vec[adyacente->getElemento()].setPadre(origen);
            if (adyacente->getElemento() == destino)
                encontreCamino = true;
            else
                encontreCamino = busquedaProfundidad(adyacente->getElemento(), destino);
        }
        iesimo = iesimo + 1;
        adyacente = vec[origen].getList()->ElementoIPosicion(iesimo);
    }
    return encontreCamino;
}

void Grafo::mostrarAdyacentes()
{
    Nodo<int>* adyacente;
    int cant = 1;
    for (int i = 0; i < 100; i++)
    {
        if (vec[i].getList()->getElemexistentes() == true)
        {
            cant = 1;
            cout << "Nodo" << i << ": ";
            vec[i].getList()->MostrarLista();
            
            cout << endl;
        }
    }
}

bool Grafo::eliminarArista(int origen, int destino)
{
    bool resp = false;
    if (vec[origen].getList()->getElemexistentes() == true)
        resp = vec[origen].getList()->elliminarElementoDado(destino);
    return resp;
}

void Grafo::inicializarBusqueda()
{
    for (int i = 0; i < 100; i++)
    {
        vec[i].setPadre(-1);
        vec[i].setMarca(false);
        vec[i].setDistancia(999999);
    }
}

void Grafo::mostrarCamino(int origen, int destino)
{
    bool resp;
    inicializarBusqueda();
    resp = busquedaProfundidad(origen, destino);
    int aux = destino;
    if (resp == true)
    {
        
        while (aux != origen)
        {
            cout << aux << " <- ";
            aux = vec[aux].getPadre();
        }
        cout << origen << endl;
    }
    else
        cout << "camino no encontrado!" << endl;
}

void Grafo::caminoMinimoATodos(int origen)
{
    
    bool resp;
    for (int i = 0; i < 100; i++)
    {
        inicializarBusqueda();
        resp = busquedaAmplitud(origen, i);
        int aux = i;
        if (resp == true)
        {
            
            while (aux != origen)
            {
                cout << aux << " <- ";
                aux = vec[aux].getPadre();
            }
            cout << origen << endl;
        }
        
    }
    
}

int Grafo::Kruskal(Grafo &AE)
{
    int vertice, distancia;
    priority_queue<pi, vector<pi>, greater<pi>>colaP;
    pi trio;
    Nodo<int>* adyacente;
    int cant,cantnodos=0;
    for (int i = 0; i < 100; i++)
    {
        if (vec[i].getList()->getElemexistentes() == true)
        {
            cant = 1;
            vec[i].setPadre(i);
            adyacente = vec[i].getList()->ElementoIPosicion(cant);
            while (adyacente != NULL)
            {
                trio.first = adyacente->getPeso();
                trio.second.first = i;
                trio.second.second = adyacente->getElemento();
                colaP.push(trio);
                cant++;
                cantnodos++;
                adyacente = vec[i].getList()->ElementoIPosicion(cant);
            }
        }
    }
    
    int vo, vd,total=0;
    cant = 0;
    while (cant<cantnodos)
    {
        trio = colaP.top();
        colaP.pop();
        vo = BuscarCiclo(trio.second.first);
        vd = BuscarCiclo(trio.second.second);
        if (vo != vd)
        {
            AE.insertarArista(vo,vd, trio.first);
            total = total + trio.first;
            vec[vo].setPadre(vec[vd].getPadre());
        }
        cant++;
    }
    return total;
}
void Grafo::Dijkstra(int origen)
{
    int vertice, distancia;
    Nodo<int> *Ady;
    priority_queue<pi, vector<pi>, greater<pi>>colaP;
    vec[origen].setDistancia(0);
    pi duo;
    duo.first = vec[origen].getDistancia();
    duo.second.first = origen;
    colaP.push(duo);
    while (!colaP.empty())
    {
        duo = colaP.top();
        colaP.pop();
        vertice = duo.second.first;
        if (vec[vertice].getMarca() == false)
        {
            vec[vertice].setMarca(true);
            Ady = vec[vertice].getList()->getPrimero();
            while (Ady != NULL)
            {
                if (vec[Ady->getElemento()].getMarca() == false && Ady->getPeso()>0)
                {
                    if (vec    [vertice].getDistancia() + Ady->getPeso()<vec[Ady->getElemento()].getDistancia())
                    {
                        vec[Ady->getElemento()].setDistancia(vec[vertice].getDistancia() + Ady->getPeso());
                        vec[Ady->getElemento()].setPadre(vertice);
                        duo.first = vec[Ady->getElemento()].getDistancia();
                        duo.second.first = Ady->getElemento();
                        duo.second.second = 0;
                        colaP.push(duo);
                    }
                }
                Ady = Ady->getSiguiente();
            }
        }
        
    }
}
void Grafo::mostrarDijkstra(int ori, int dest)
{
    vector<int> cam;
    if (vec[dest].getMarca() != false)
    {
        while (dest != ori)
        {
            cam.push_back(dest);
            dest = vec[dest].getPadre();
        }
        cout << ori;
        
        while (!cam.empty())
        {
            cout << "->" << cam.back();
            cam.pop_back();
        }
        cout << endl;
    }
    
}


void Grafo::leerArchivo()
{
    fstream archEnter;
    int ori, fin, dist;
    archEnter.open("numeros.txt");
    
    while (!archEnter.eof() && archEnter >> ori >> fin >> dist)
    {
        insertarArista(ori, fin, dist);
    }
    
    archEnter.close();
    cout << "exito..." << endl;
    
}
void Grafo::mostrarKruskal()
{
    for (int i = 1; i < 100; i++)
    {
        if (vec[i].getList()->getElemexistentes() != false)
        {
            cout << "Nodo "<< i <<": " ;
            vec[i].getList()->MostrarLista();
            cout << endl;
        }
        
    }
    
}

int Grafo::BuscarCiclo(int x)
{
    while (x != vec[x].getPadre())
    {
        x = vec[x].getPadre();
    }
    return x;
}


#endif /* Grafo_h */
