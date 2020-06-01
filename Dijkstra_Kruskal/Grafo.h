#ifndef Grafo_h
#define Grafo_h

#include"Vertice.h"
#include <queue>
#include <functional>
#include <fstream>
typedef pair<char, pair<char, char>>pi;

class Grafo
{
private:
    
    Vertice<int> vec[100];
    int iesimo;
public:
    
    Grafo();
    ~Grafo();
    void insertarArista(char origen, char destino, char peso);
    bool busquedaAmplitud(char origen, char destino);
    bool busquedaProfundidad(char origen, char destino);
    void mostrarAdyacentes();
    bool eliminarArista(char origen, char destino);
    void inicializarBusqueda();
    void mostrarCamino(char origen, char destino);
    void caminoMinimoATodos(char origen);
    int Kruskal(Grafo &AE);
    void leerArchivo();
    void mostrarKruskal();
    void Dijkstra(char origen);
    void mostrarDijkstra(char ori, char dest);
    int BuscarCiclo(char x);
};

Grafo::Grafo()
{
}

Grafo::~Grafo()
{
}

void Grafo::insertarArista(char origen, char destino, char peso)
{   
    vec[origen-65].getList()->insertarFinal(destino, peso);
    vec[destino-65].getList()->insertarFinal(origen, peso);
    //vec[origen].setInsertado(true);
}

bool Grafo::busquedaAmplitud(char origen, char destino)
{
    char vert;
    queue<int> cola;
    Nodo<char>* adyacente;
    bool encontre = false;
    vec[origen-65].setMarca(true);
    cola.push(origen);
    
    while (!cola.empty() && encontre == false)
    {
        iesimo = 1;
        vert = cola.front();
        cola.pop();
        adyacente = vec[vert-65].getList()->ElementoIPosicion(iesimo);
        while (adyacente != NULL && encontre == false)
        {
            if (vec[adyacente->getElemento()-65].getMarca() == false)
            {
                vec[adyacente->getElemento()-65].setPadre(vert);
                if (adyacente->getElemento() == destino)
                    encontre = true;
                else
                {
                    vec[adyacente->getElemento()-65].setMarca(true);
                    cola.push(adyacente->getElemento());
                }
            }
            iesimo = iesimo + 1;
            adyacente = vec[vert-65].getList()->ElementoIPosicion(iesimo);
        }
    }
    
    return encontre;
}

bool Grafo::busquedaProfundidad(char origen, char destino)
{
    queue<int> cola;
    Nodo<char>* adyacente;
    bool encontreCamino = false;
    vec[origen-65].setMarca(true);
    iesimo = 1;
    adyacente = vec[origen-65].getList()->ElementoIPosicion(iesimo);
    while (adyacente != NULL) {
        if (encontreCamino == false && vec[adyacente->getElemento()-65].getMarca() == false)
        {
            vec[adyacente->getElemento()-65].setPadre(origen);
            if (adyacente->getElemento() == destino)
                encontreCamino = true;
            else
                encontreCamino = busquedaProfundidad(adyacente->getElemento(), destino);
        }
        iesimo = iesimo + 1;
        adyacente = vec[origen-65].getList()->ElementoIPosicion(iesimo);
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

bool Grafo::eliminarArista(char origen, char destino)
{
    bool resp = false;
    if (vec[origen-65].getList()->getElemexistentes() == true)
        resp = vec[origen-65].getList()->elliminarElementoDado(destino);
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

void Grafo::mostrarCamino(char origen, char destino)
{
    bool resp;
    inicializarBusqueda();
    resp = busquedaProfundidad(origen, destino);
    int aux = destino-65;
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

void Grafo::caminoMinimoATodos(char origen)
{
    
    bool resp;
    for (int i = 0; i < 100; i++)
    {
        inicializarBusqueda();
        resp = busquedaAmplitud(origen, i);
        int aux = i;
        if (resp == true)
        {
            
            while (aux != (origen-65))
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
    Grafo<T>* AE= new Grafo<T>;
	priority_queue<pi, vector<pi>, greater<pi>>colaP;
	int cont = 0,cantNodos=0,verticeOrigen,verticeDestino;
	Nodo<int>trio;
	for (int i = 0; i < 10; i++)
	{
		if (vec[i].getInsertado() == true)
		{
			Nodo<T>*adyacente=vec[i].sacarSiguienteAdyacente(1);
			while (adyacente != NULL)
			{
				colaP.insertarArista(adyacente->getPeso(), i, adyacente->getElem());
				cantNodos++;
				adyacente = adyacente->getSiguiente();
			}
		}
	}
	while (cont < cantNodos)
	{
		trio = colaP.sacarRaiz();
		verticeOrigen = BuscarCiclo(trio.getVerticeOrigen());
		verticeDestino = BuscarCiclo(trio.getVerticeDestino());
		if (verticeOrigen != verticeDestino)
		{
			AE->insertar(trio.getVerticeOrigen(), trio.getVerticeDestino(), trio.getElemento());
			total = total + trio.getElemento();
			vec[verticeOrigen].setPadre(vec[verticeDestino].getPadre());
		}
		cont++;
	}
	return AE;
}
void Grafo::Dijkstra(char origen)
{
    char vertice;
    int distancia;
    Nodo<char> *Ady;
    priority_queue<pi, vector<pi>, greater<pi>>colaP;
    vec[origen-65].setDistancia(0);
    pi duo;
    duo.first = vec[origen-65].getDistancia();
    duo.second.first = origen;
    colaP.push(duo);
    while (!colaP.empty())
    {
        duo = colaP.top();
        colaP.pop();
        vertice = duo.second.first;
        if (vec[vertice-65].getMarca() == false)
        {
            vec[vertice-65].setMarca(true);
            Ady = vec[vertice-65].getList()->getPrimero();
            while (Ady != NULL)
            {
                if (vec[Ady->getElemento()-65].getMarca() == false && Ady->getPeso()>0)
                {
                    if (vec[vertice-65].getDistancia() + Ady->getPeso()<vec[Ady->getElemento()-65].getDistancia())
                    {
                        vec[Ady->getElemento()-65].setDistancia(vec[vertice-65].getDistancia() + Ady->getPeso());
                        vec[Ady->getElemento()-65].setPadre(vertice);
                        duo.first = vec[Ady->getElemento()-65].getDistancia();
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
void Grafo::mostrarDijkstra(char ori, char dest)
{
    vector<char> cam;
    if (vec[dest-65].getMarca() != false)
    {
        while (dest != ori)
        {
            cam.push_back(dest);
            dest = vec[dest-65].getPadre();
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

int Grafo::BuscarCiclo(char x)
{
    while (x != vec[x-65].getPadre())
    {
        x = vec[x-65].getPadre();
    }
    return x;
}


#endif /* Grafo_h */
