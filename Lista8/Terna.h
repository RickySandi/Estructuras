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

public:

	Terna()
	{
		next = NULL;
		previous = NULL;
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

	void setValue(T v) 
	{
		value = v;
	}

	void setNext(Terna<T>* t) 
	{
		next = t;
	}

	void setPrevious(Terna<T>* t)
	{
		previous = t;
	}

	~Terna()
	{

	}
};



