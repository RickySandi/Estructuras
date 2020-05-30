//
//  Nodo.h
//  DijkstraKruskal
//
//  Created by MacBook Air on 11/18/18.
//  Copyright © 2018 MacBook Air. All rights reserved.
//

#ifndef Nodo_h
#define Nodo_h
#include <iostream>
using namespace std;
template< class T>

class Nodo
{
private:
    T elemento;
    int peso;
    Nodo<T> *siguiente;
    Nodo<T> *anterior;
    
public:
    Nodo();
    ~Nodo();
    T getElemento();
    Nodo* getSiguiente() { return siguiente; }
    Nodo* getAnterior() { return anterior; }
    void setElem(T elem);
    void setSiguiente(Nodo* aux);
    void serAnterior(Nodo* aux);
    void setPeso(int peso);
    int getPeso();
};

template<class T>
Nodo<T>::Nodo()
{
    siguiente = NULL;
    anterior = NULL;
    peso = 0;
}

template<class T>
Nodo<T>::~Nodo()
{
}

template<class T>
T Nodo<T>::getElemento()
{
    return elemento;
}


template<class T>
void Nodo<T>::setElem(T elem)
{
    this->elemento = elem;
}

template<class T>
void Nodo<T>::setSiguiente(Nodo * aux)
{
    this->siguiente = aux;
}

template<class T>
void Nodo<T>::serAnterior(Nodo * aux)
{
    this->anterior = aux;
}

template<class T>
inline void Nodo<T>::setPeso(int peso)
{
    this->peso = peso;
}

template<class T>
inline int Nodo<T>::getPeso()
{
    return peso;
}


#endif /* Nodo_h */
