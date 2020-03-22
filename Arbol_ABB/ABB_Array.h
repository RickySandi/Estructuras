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
void mostrarInOrder(int raiz = 1){
    //cout<<"entra"<< raiz<< "-" <<vec[raiz]->getElem() <<endl; 
    if(vec[raiz]->getExisteNodo()){
        mostrarInOrder(raiz*2); //izquierda
        vec[raiz]->mostrar();
        mostrarInOrder((raiz*2)+1); //derecha 
    }
}
void mostrarPreOrder(int raiz = 1){
    //cout<<"entra"<< raiz<< "-" <<vec[raiz]->getElem() <<endl; 
    if(vec[raiz]->getExisteNodo()){
        vec[raiz]->mostrar();
        mostrarPreOrder(raiz*2); //izquierda
        mostrarPreOrder((raiz*2)+1); //derecha 
    }
}
void mostrarPostOrder(int raiz = 1){
    //cout<<"entra"<< raiz<< "-" <<vec[raiz]->getElem() <<endl; 
    if(vec[raiz]->getExisteNodo()){
        mostrarPostOrder(raiz*2); //izquierda
        mostrarPostOrder((raiz*2)+1); //derecha 
        vec[raiz]->mostrar();
    }
}
int contarNodos(int raiz = 1){
     
    if(vec[raiz]->getExisteNodo()){
        
        return 1 + contarNodos(raiz*2) + contarNodos(raiz*2+1);
    } else{
        return 0;
    }
}
int altura(int raiz =1){
    
    if(vec[raiz]->getExisteNodo()){
       int alturaIzq = altura(raiz*2);
       int alturaDer = altura(raiz*2 + 1);
        return max(alturaIzq, alturaDer) + 1;
    } else{
        return 0;
    }
}

}; 

