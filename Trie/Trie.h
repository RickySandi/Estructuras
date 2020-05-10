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
		insertar(palabra, 0, raiz->getHijo(toupper(palabra[0]) - 65));
	}
	void insertar(string palabra, int pos, Nodo<T>*& raiz) {

		if (pos < palabra.size()) {

			if (raiz == NULL) {
				raiz = new Nodo<T>;
				raiz->setDato(toupper(palabra[pos]));

			}
			if (pos == (palabra.size() - 1)) {
				raiz->setFinalPalabra(true);
			}

			else {
				insertar(palabra, pos + 1, raiz->getHijo((toupper(palabra[pos + 1]) - 65)));
			}

		}
	}
	bool buscarPalabra(string p) {
		return raiz->getHijo(p[0] - 65) != NULL && buscarPalabra(p, 0, raiz->getHijo(toupper(p[0]) - 65));
	}
	bool buscarPalabra(string palabra, int pos, Nodo<T>*& raiz) {
		bool enc = false;
		if (pos < palabra.size()) {
			if (raiz->getFinalPalabra() && pos == palabra.size() - 1) {
				enc = true;
			}
			else {
				if (raiz->getHijo(toupper(palabra[pos + 1]) - 65) != NULL) {
					enc = buscarPalabra(palabra, pos + 1, raiz->getHijo(toupper(palabra[pos + 1]) - 65));
				}
			}
		}
		return enc;
	}

};

