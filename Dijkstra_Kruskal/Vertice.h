//
//  Vertice.h
//  DijkstraKruskal
//
//  Created by MacBook Air on 11/18/18.
//  Copyright © 2018 MacBook Air. All rights reserved.
//

#ifndef Vertice_h
#define Vertice_h

#pragma once
#include"Lista8.h"
template <class T>
class Vertice
{
private:
    int padre;
    bool marca;
    bool insertado = false;
    int distancia;
    Lista8<int>* lista;
public:
    Vertice();
    ~Vertice();
    int getPadre();
    void setPadre(int padre);
    bool getMarca();
    void setMarca(bool marca);
    void insertar(int destino,int peso);
    bool getInsertado();
    void setInsertado(bool ins);
    int getDistancia();
    void setDistancia(int dist);
    Lista8<int>* getList();
};

template<class T>
inline Vertice<T>::Vertice() :lista()
{
    padre = -1;
    marca = false;
    lista = new Lista8<int>;
    distancia = 99999;
}


template<class T>
inline Vertice<T>::~Vertice()
{
    
}

template<class T>
inline int Vertice<T>::getPadre()
{
    return padre;
}

template<class T>
inline void Vertice<T>::setPadre(int padre)
{
    this->padre = padre;
}

template<class T>
inline bool Vertice<T>::getMarca()
{
    return marca;
}

template<class T>
inline void Vertice<T>::setMarca(bool marca)
{
    this->marca = marca;
}

template<class T>
inline void Vertice<T>::insertar(int destino,int peso)
{
    lista->insertarFinal(destino,peso);
}

template<class T>
inline bool Vertice<T>::getInsertado()
{
    return insertado;
}

template<class T>
inline void Vertice<T>::setInsertado(bool ins)
{
    this->insertado = ins;
}

template<class T>
inline int Vertice<T>::getDistancia()
{
    return distancia;
}

template<class T>
inline void Vertice<T>::setDistancia(int dist)
{
    this->distancia = dist;
}

template<class T>
inline Lista8<int> * Vertice<T>::getList()
{
    return lista;
}

#endif /* Vertice_h */
