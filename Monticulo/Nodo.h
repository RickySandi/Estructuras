#pragma once
#include <iostream>
using namespace std;

template <class T>

class Nodo
{
private:
T elem;
//int cont;
bool existe;  



public:
Nodo(){
    //cont = 0; 
    existe = false; 
}

~Nodo(){
}
void setElem(T v){
    elem = v; 
}
T getElem(){
    return elem; 
}

void mostrar(){
    cout<<elem<<" "; 
}

void setExisteNodo(bool e){
    existe = e; 
}

bool getExisteNodo(){
    return existe; 
}


}; 