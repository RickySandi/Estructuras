#pragma once
#include <iostream>
using namespace std;

template <class T>

class Nodo
{
private:
T elem;
int cont; 
int factor;
Nodo * subIzq;
Nodo * subDer; 


public:
Nodo(){
    cont = 0; 
    factor = 0; 
    subIzq = NULL;
    subDer = NULL;
}

~Nodo(){
}
void setElem(T v){
    elem = v; 
}
T getElem(){
    return elem; 
}

void setCont(int c){
    cont = c; 
}

int getCont(){
    return cont; 
}

void setFactor(int f){
    factor = f; 
}

int getFactor(){
    return factor; 
}

void mostrar(){
    cout<<elem<<" "; 
}
void setSubIzq(Nodo <T>* Sizq){
     subIzq = Sizq; 
}
Nodo <T>*& getSubIzq(){
    return subIzq;
}
void setSubDer(Nodo <T>* Sder){
     subDer = Sder; 
}
Nodo <T>*& getSubDer(){
    return subDer;
}

void setExisteNodo(){
    cont = 1; 
}

int getExisteNodo(){
    return cont; 
}


}; 