#pragma once
#include"Lista_8.h"
template<class T>
class Vertice
{
private:
	T nombre;
	string nombreDep;
	bool marca;
	Lista_8<T>lista;
	int padre;
	bool existe;
	int distancia;
public:

Vertice()
{
	marca = false;
	padre = -1;
	existe = false;
	distancia = 99999;
}

~Vertice()
{

}

void setNombre(T nombre)
{
	this->nombre = nombre;
}

void setMarca(bool marca)
{
	this->marca = marca;
}

void setPadre(int padre)
{
	this->padre = padre;
}

T getNombre()
{
	return nombre;
}

bool getMarca()
{
	return marca;
}

int getPadre()
{
	return padre;
}

void insertarFinalLista8(T elemento)
{
	lista.insertBack(elemento);
}
void eliminarArista(T elemento)
{
	lista.eliminarElemento(elemento);
}

void mostrarLista8()
{
	lista.mostrar();
}

void setExiste(bool existe)
{
	this->existe = existe;
}

bool getExiste()
{
	return existe;
}

 Terna<T>* sacarSiguienteAdyacente(int i_esimo)
{
	Terna<T>*aux=lista.sacarSiguienteAdyacente(i_esimo);
	return aux;
}

// int getCont()
// {
// 	return lista.contarElementos();
// }

void setDistancia(int distancia)
{
	this->distancia = distancia;
}

int getDistancia()
{
	return distancia;
}

void setNombreDep(string nombreDep)
{
	this->nombreDep = nombreDep;
}

string getNombreDep()
{
	return nombreDep;
}
Lista_8<T> * getList()
{
	return lista;
}


};