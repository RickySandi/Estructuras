#pragma once
#include <iostream>

using namespace std;
template <class T>

class Nodo
{
private:
	T elemento;
	Nodo* subIzq;
	Nodo* subDer;
	char color;
public:
	Nodo()
	{
		subIzq = NULL;
		subDer = NULL;
		color = NULL;
	}
	~Nodo()
	{

	}
	void setElemento(T elemento)
	{
		this->elemento = elemento;
	}
	T getElem(){
		return elemento; 
	}
	void setSubIzq(Nodo<T>* subIzq)
	{
		this->subIzq = subIzq;
	}
	void setSubDer(Nodo<T>* subDer)
	{
		this->subDer = subDer;
	}
	void setColor(char c)
	{
		color = c;
	}
	T getElemento()
	{
		return elemento;
	}
	Nodo<T>*& getSubIzq()
	{
		return subIzq;
	}
	Nodo<T>*& getSubDer()
	{
		return subDer;
	}
	char getColor()
	{
		return color;
	}
	void mostrar()
	{
		cout << elemento << "=" << color << "     ";
	}
};

