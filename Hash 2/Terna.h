#pragma once
#include<iostream>
using namespace std;

template <class T>

class Terna
{
private:

	T value;
	Terna* next;
	Terna* previous;
	int repeticiones;

public:

	Terna()
	{
		next = NULL;
		previous = NULL;
		repeticiones = 0;
	}

	void setValue(T v)
	{
		value = v;
		repeticiones++;
	}

	void setNext(Terna<T>* t)
	{
		next = t;
	}

	void setPrevious(Terna<T>* t)
	{
		previous = t;
	}

	void addSize()
	{
		repeticiones++;
	}

	Terna<T>* getNext()
	{
		return next;
	}

	Terna<T>* getPrevious()
	{
		return previous;
	}

	T getValue()
	{
		return value;
	}

	int getSize()
	{
		return repeticiones;
	}
	void mostrar()
	{
		cout << value << " " << repeticiones << endl;
	}
	~Terna()
	{

	}
};

