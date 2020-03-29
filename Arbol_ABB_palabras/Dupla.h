#pragma once
#include <iostream>
using namespace std;

template <class T>

class Dupla
{
private:
T elem;
int cont; 
Dupla * subIzq;
Dupla * subDer; 


public:
Dupla(){
    cont = 0; 
    subIzq = NULL;
    subDer = NULL;
}

~Dupla(){
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
void setSubIzq(Dupla <T>* Sizq){
     subIzq = Sizq; 
}
Dupla <T>*& getSubIzq(){
    return subIzq;
}
void setSubDer(Dupla <T>* Sder){
     subDer = Sder; 
}
Dupla <T>*& getSubDer(){
    return subDer;
}


}; 