#pragma once
#include <iostream>
#include "Nodo.h"
#include "Trie.h"
using namespace std;

void mostrarMenu() 
{
    Trie<char>* trie = new Trie<char>();
    int op; 
    string palabra;
    fstream archEntrada;
   
    do {
        cout << "-----MENU-----" << endl;
        cout << "1.Insertar palabra" << endl;
        cout << "2.Buscar palabra" << endl;
        cout << "3.Salir" << endl;
        cout << endl;
        cout << "Ingresa una opcion" << endl;
        cin >> op;
        switch (op)
        {
        case 1:
            cout << "Ingresa un valor para insertar" << endl;
            cin >> palabra;
            trie->insertar(palabra); 
            break;
        case 2:
            cout << "Ingresa un valor para buscar" << endl;
            cin >> palabra;
            trie->buscarPalabra(palabra); 
            break;
        case 3:
            break;
        default:
            break;
        }
        
    } while (op != 11);
}


int main() {
	Trie<char>* a = new Trie<char>();
	a->insertar("AB");
	a->insertar("AC");
	a->insertar("BC");
	a->insertar("A");
	a->insertar("BCA");
	a->insertar("BCADE");
	a->insertar("ZAZ");
	a->insertar("Z");

    cout<<a->buscarPalabra("BC")<<endl;
    cout<<a->buscarPalabra("BB")<<endl; 
} 