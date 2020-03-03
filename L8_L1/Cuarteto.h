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
	string criterio; 
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
		return value;
	}

	void setValue(T v) 
	{
		value = v;
	}

	void setNext(Cuarteto<T>* t) 
	{
		next = t;
	}

	void setPrevious(Cuarteto<T>* t)
	{
		previous = t;
	}

	~Cuarteto()
	{

	}
};



