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

	Terna* getNext() {
		return next;
	}

	Terna* getPrevious() {
		return previous;
	}

	T getValue() {
		return value;
	}

	void setValue(T v) {
		value = v;
	}

	void setNext(Terna* t) {
		next = t;
	}

	void setPrevious(Terna* t) {
		previous = t;
	}


	~Terna() {
	}
};

