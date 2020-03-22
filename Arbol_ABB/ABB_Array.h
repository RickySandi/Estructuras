#pragma once
#include <iostream>
#include "Dupla.h"
using namespace std;

/*
Insertar contando en el árbol
Recorrer IN Order
Recorrer PRE Order
Recorrer POST Order
Contar Nodos
Calcular la altura del árbol
Buscar
Encontrar el Menor
Encontrar el Mayor
*/
template <class T>

class ABB_Array
{
private:
int tam = 100;
Dupla<T> * vec[100]; //1000


public:
ABB_Array(){
     for (int i=0 ; i < tam ; i++) {
         vec[i] = new Dupla<T>();
     }
}

~ABB_Array(){
}

void insertar(T elemento, int raiz = 1){ //Testear 
        
    
     if(!vec[raiz]->getExisteNodo()){
        vec[raiz]->setExisteNodo();
        vec[raiz]->setElem(elemento);
      
    }
    else{
        if(elemento < vec[raiz]->getElem()){
            insertar(elemento, raiz*2);
        }
        if(elemento > vec[raiz]->getElem()){
            insertar(elemento, (raiz*2)+1);
        }
    }
    // cout << "IMPRIMIR:" << endl << endl;
    // for (int i=0 ; i < tam ; i++) {
    //     cout << vec[i]->getElem() << endl;
    // }
}
void mostrarINorder(int raiz){
    //cout<<"entra"<< raiz<< "-" <<vec[raiz]->getElem() <<endl; 
    if(vec[raiz]->getExisteNodo()){
        mostrarINorder(raiz*2); //izquierda
        vec[raiz]->mostrar();
        mostrarINorder((raiz*2)+1); //derecha 
    }
}

}; 

