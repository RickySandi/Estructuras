#pragma once
#include <iostream>
using namespace std;

template <class T>

class Dupla
{
private:
T elem;
int cont;  


public:
Dupla(){
    cont = 0; 
    elem = NULL;
}

~Dupla(){
}
void setElem(T v){
    elem = v; 
}
T getElem(){
    return elem; 
}

T getCont(){
    return cont; 
}
void setExisteNodo(){
    cont = 1; 
}

int getExisteNodo(){
    return cont; 
}
void mostrar(){
    cout<<elem<<" "; 
}
void moverIzquierda(){
    elem *= 2; 
}
void moverDerecha(){
    elem *= 2+1; 
}

}; 