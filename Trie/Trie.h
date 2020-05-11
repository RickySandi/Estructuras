#pragma once
#include <iostream>
#include <fstream>
#include "Nodo.h"
using namespace std;
template <class T>
class Trie
{
private:
	Nodo<T>* raiz;
public:
	Trie() {
		raiz = new Nodo<T>();
	}
	void insertar(string palabra) {
		insertar(palabra,raiz->getHijo(toupper(palabra[0]) - 65));
	}
	void insertar(string palabra, Nodo<T>*& raiz) {
		if (!palabra.empty()) {
			if (raiz == NULL) {
				raiz = new Nodo<T>(toupper(palabra[0]));
			}
			if (palabra.size() == 1) {
				raiz->setFinalPalabra(true);
			}
			else {
				insertar(palabra.substr(1), raiz->getHijo((toupper(palabra[1]) - 65)));
			}
		}
	}
	bool buscarPalabra(string p) {
		Nodo<T>* res;
		return buscarPalabra(p, raiz->getHijo(toupper(p[0]) - 65),res);
	}
	bool buscarPalabra(string palabra, Nodo<T>*& raiz, Nodo<T>*& res) {
		bool enc = false;
		res = raiz;
		if (!palabra.empty() && raiz != NULL) {
			if (raiz->getFinalPalabra()&& palabra.size() == 1) {
				enc = true;
			}
			else {
				if (palabra.size() > 1) {
					enc = buscarPalabra(palabra.substr(1), raiz->getHijo(toupper(palabra[1]) - 65), res);
				}
			}
		}
		return enc;
	}
	void mostrarPalabras() {
		string palabra = "";
		for (int i = 0; i < 26; i++) {
			if (raiz->getHijo(i) != NULL) {
				mostrarPalabras(raiz->getHijo(i), palabra);
			}
		}
	}
	void mostrarPalabras(Nodo<T>*& raiz, string palabra) {
		palabra += raiz->getDato();
		if (raiz->getFinalPalabra()) {
			cout << palabra << endl;
		}
		for (int i = 0; i < 26; i++) {
			if (raiz->getHijo(i) != NULL) {
				mostrarPalabras(raiz->getHijo(i), palabra);
			}
		}
	}
	int cantidadPalabras() {
		int c = 0;
		for (int i = 0; i < 26; i++) {
			if (raiz->getHijo(i) != NULL) {
				c+=cantidadPalabras(raiz->getHijo(i));
			}
		}
		return c;
	}
	int cantidadPalabras(Nodo<T>*&raiz) {
		int c = 0;
		if (raiz!=NULL) {
			if (raiz->getFinalPalabra()) {
				c++;
			}
			for (int i = 0; i < 26; i++) {
				if (raiz->getHijo(i) != NULL) {
					c+=cantidadPalabras(raiz->getHijo(i));
				}
			}
		}
		return c;
	}
	int tamPalabra() {
		char pal[23];
		string palabra = "                       ";
		int t = 0;
		for (int i = 0; i < 26; i++) {
			if (raiz->getHijo(i) != NULL) {
				int a=tamPalabra(raiz->getHijo(i), palabra, 0,pal)+1;
				if (a > t) {
					t = a;
					palabra[0] = raiz->getHijo(i)->getDato();
				}
				
			}
		}
		cout << palabra << endl;
		return t;
	}
	int tamPalabra(Nodo<T>*&raiz,string& palabra,int pos,char pal[23]) {
		int tam = 0;
		for (int i = 0; i < 26; i++) {
			if (raiz->getHijo(i) != NULL) {
				int t = tamPalabra(raiz->getHijo(i), palabra, pos + 1,pal)+1;
				if (t > tam) {
					tam = t;
					if (t>pal[pos+1]) {
						palabra[pos + 1] = raiz->getHijo(i)->getDato();
						pal[pos + 1] = t;
					}
					
				}
				
			}
		}
		return tam;
	}
	void mostrarPalabrasContiene(string palabra) {
		Nodo<T>* res;
		buscarPalabra(palabra, raiz->getHijo(toupper(palabra[0]) - 65),res);
		if (res!=NULL) {
			mostrarPalabras(res, palabra.substr(0, palabra.size() - 1));
		}
	}

};

