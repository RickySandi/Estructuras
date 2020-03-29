#pragma once
#include <iostream>
using namespace std;

template <class T>

class Nodo
{
private:
T elem;
int cont; 
Nodo * subIzq;
Nodo * subDer; 


public:
Nodo(){
    cont = 0; 
    subIzq = NULL;
    subDer = NULL;
}

~Nodo(){
}
void setElem(T v){
    elem = v; 
}

void setCont(int c){
    cont = c; 
}
T getElem(){
    return elem; 
}

int getCont(){
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


}; 