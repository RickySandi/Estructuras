#include <iostream>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

int main()
{
	string producto, cantPro;
	int cant;
	fstream archEntrada;
	map<string, int> Arbol;
	map<string, int>::iterator it;
	pair<string, int> i;
	int aux1, aux;
	archEntrada.open("pedido.txt");
	while (!archEntrada.eof() && archEntrada >> producto && archEntrada >> cantPro)
	{
		istringstream(cantPro) >> cant;
		if (Arbol.find(producto) != Arbol.end())
		{
			aux = Arbol[producto];
			aux1 = aux + cant;
			Arbol.erase(producto);
		}
		else
		{
			aux1 = cant;
		}
		i.first = producto;
		i.second = aux1;
		Arbol.insert(i);
	}
	for (it = Arbol.begin(); it != Arbol.end(); ++it)
		cout << it->first << " => " << it->second << '\n';
}