#pragma once
#include <stdio.h>
#include<iostream>
#include "Lista_8.h"
#include <math.h>

using namespace std;
template <class T>

class Hash
{
private:

	Lista_8<string> lista[38011];

public:

	Hash(){

	}

	~Hash(){

	}

	void insertar(string palabra)
	{
		lista[funcion(palabra)].insertFirst(palabra);
	}

	void eliminar(string palabra)
	{
		lista[funcion(palabra)].eliminarElemento(palabra);
	}

	void buscar(string palabra)
	{
		bool r;
		r = lista[funcion(palabra)].buscar(palabra);
		if (r == true) {
			lista[funcion(palabra)].buscar1(palabra);
		}
	}
	void mostrar(){
		

	}
	int funcion(string palabra)
	{
		int res = 0;
		int x;
		for (int i = 0; i < palabra.size(); i++) {
			x = palabra[i];
			res = res + (x * pow(2, i));
		}
		return res % 38011;
	}
	int contarDiferentes(){
		int diferentes =0; 
		for(int i =0; i<38011;i++){
			diferentes += lista[i].contar(); 
		}
		return  diferentes; 
	
	}

	void contarColisiones(){
		int vec[20] = {0}; 
		int palabras = 0; 
		// int u=0; 
		for(int i =0; i<38011;i++){
			palabras = lista[i].contar();
			vec[palabras] = vec[palabras] +1;
		}

		for(int i =0; i<20;i++){
			cout<<"La posicion "<<i<<" tiene "<<vec[i]<<" elementos"<<endl; 
		}


	}

};

