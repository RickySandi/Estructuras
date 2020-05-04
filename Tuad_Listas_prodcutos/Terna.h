#pragma once
#include<iostream>
#include<string>
using namespace std;

template <class T>

class Terna
{
private:

	T value;
	int cant;
	Terna* next;
	Terna* previous;
	int tam;

public:

	Terna()
	{
		next = NULL;
		previous = NULL;
		tam = 0;
		cant=0; 
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
	int getTam()
	{
		return tam;
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
	void setTam(int i)
	{
		tam = i;
	}
	void increaseCant(int c){
		cant += c;  
	}
	
	int getCant(){
		return cant; 
	}
	Terna<T>* getTerna(){
		return this; 
	}
	~Terna()
	{

	}
};