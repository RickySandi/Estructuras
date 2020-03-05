#pragma once
#include<iostream>
#include "Lista_1.h"
using namespace std;

template <class T>

class Cuarteto
{
	private:
		Cuarteto* next;
		Cuarteto* previous;
		T criterio;
		Lista_1* lista;
	public:
		Cuarteto() {
			next = NULL;
			previous = NULL;
			lista = new Lista_1();
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

		void setList(Lista_1* l) {
			
			lista = l;
		}

		Lista_1* getList() {
			return lista;
		}

		~Cuarteto()
		{

		}
};

