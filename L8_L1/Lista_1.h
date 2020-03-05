#pragma once
#include <iostream>
#include <string>
using namespace std;
#define TAM 40
class Lista_1
{
private:
	int size;
	string estudiantes[TAM];

public:
	Lista_1()
	{
		size = 0;
	}

	~Lista_1()
	{

	}

	void insertarFinal(string Es)
	{
		if (size < TAM){
			estudiantes[size] = Es;
			size++;
			
		}
	}

	void eliminarFinal()
	{
		estudiantes[size] = "";
		size--;
	}

	bool buscar(string Es)
	{
		bool res = false;
		for (int i = 0; i < size; i++){
			if (estudiantes[i] == Es){
				res = true;
			}
		}
		return res;
	}

	void imprimirArray()
	{
		for (int i = 0; i < size; i++)
		{
			cout << estudiantes[i] << endl;
		}
	
	}
};

