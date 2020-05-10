#pragma once
#include <iostream>
using namespace std;
template <class T>
class Nodo
{
private:
    Nodo* tuad[27] = { NULL };
    bool finPal;
    T dato;
public:
    Nodo() {
        finPal = false;
        dato = NULL;

    }
    T getDato() {
        return dato;
    }

    void setDato(T p) {
        dato = p;
    }
    Nodo*& getHijo(int i) {
        return tuad[i];
    }
    void setFinalPalabra(bool f) {
        finPal = f;
    }
    bool getFinalPalabra() {
        return finPal;
    }

};