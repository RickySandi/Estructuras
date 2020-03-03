#pragma once
#include<iostream>
#include "Lista_1.h"
using namespace std;

template <class T>

class Cuarteto
{
private:

	//T value;
	Cuarteto* next;
	Cuarteto* previous;
	T criterio; 
	Lista_1 * lista;


public:

	Cuarteto()
	{
		next = NULL;
		previous = NULL;
	}

	Cuarteto<T>* getNext()
	{
		return next;
	}

	Cuarteto<T>* getPrevious()
	{
		return previous;
	}

	T getValue() 
	{
		return criterio;
	}

	void setValue(T v) 
	{
		criterio = v;
	}

	void setNext(Cuarteto<T>* t) 
	{
		next = t;
	}

	void setPrevious(Cuarteto<T>* t)
	{
		previous = t;
	}

	Lista_1 * getLista(){
		return lista;
	}


	~Cuarteto()
	{

	}
};



