#pragma once
#include <iostream>
#include "Nodo.h"
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
+ Eliminar
*/
template <class T>

class ABB_Array
{
private:
Nodo<T> * raiz; //1000


public:
ABB_Array(){
     raiz =  NULL;
}

~ABB_Array(){
}
Nodo<T>*& getRaiz(){
    return raiz; 
}


void insertar(T elemento, Nodo <T> *&nodo){ //Testear 
    if (nodo == NULL){
        nodo = new Nodo <T>();
        nodo->setElem(elemento); 
        nodo->setCont(1); 
    
    }  
     else{
        
        if(elemento < nodo->getElem()){
            insertar(elemento, nodo->getSubIzq());
        }
        else if(elemento > nodo->getElem()){
            insertar(elemento, nodo->getSubDer());
        }
        else if(elemento == nodo->getElem()){
            int cur = nodo->getCont();
            nodo->setCont(cur+1);
        }        
    }
  
  
}

void mostrarInOrder(Nodo <T> *nodo){
    
    if(nodo != NULL){ 
        mostrarInOrder(nodo->getSubIzq()); //izquierda
        nodo->mostrar();
        mostrarInOrder(nodo->getSubDer()); //derecha 
    }
}
    
void mostrarPreOrder(Nodo <T> *nodo){
     
    if(nodo != NULL){
        nodo->mostrar();
        mostrarPreOrder(nodo->getSubIzq()); //izquierda
        mostrarPreOrder(nodo->getSubDer()); //derecha 
    }
    
}
void mostrarPostOrder(Nodo <T> *nodo){
    //cout<<"entra"<< nodo<< "-" <<vec[nodo]->getElem() <<endl; 
    if(nodo != NULL){
        mostrarPostOrder(nodo->getSubIzq()); //izquierda
        mostrarPostOrder(nodo->getSubDer()); //derecha 
        nodo->mostrar();
    }
    
}
int contarNodos(Nodo <T> *nodo){
     
    if(nodo != NULL){
        
        return 1 + contarNodos(nodo->getSubIzq()) + contarNodos(nodo->getSubDer());
    } else{
        return 0;
    }
}
int altura(Nodo <T> *nodo){
    
    if(nodo != NULL){
       int alturaIzq = altura(nodo->getSubIzq());
       int alturaDer = altura(nodo->getSubDer());
        return max(alturaIzq, alturaDer) + 1;
    } else{
        return 0;
    }
}
bool buscar(T elemento,Nodo <T> *nodo){
    if(nodo != NULL){
        if(nodo->getElem() == elemento) {
            return true;
        } else {
            if (elemento < nodo->getElem()) {
               
               return buscar(elemento, nodo->getSubIzq());
            } else {
                
                return buscar(elemento, nodo->getSubDer());
            }
        }

    } else {
        return false;
    }
}

T menor(Nodo <T> *nodo){ //izquierda
    if(nodo->getSubIzq() == NULL){
        return nodo->getElem();
    }
        return menor(nodo->getSubIzq());
    }

T mayor(Nodo <T> *nodo){ //derecha
     if(nodo->getSubDer() == NULL){
        return nodo->getElem();
    }
        return mayor(nodo->getSubDer());
    }

void eliminar(T elemento,Nodo<T>*& nodo){
    T aux;

    if(nodo != NULL){
        if(elemento < nodo->getElem()) {
            eliminar(elemento, nodo->getSubIzq());
        }
        
       else if (elemento > nodo->getElem()){
            eliminar(elemento, nodo->getSubDer());   
        }
        else if(elemento == nodo->getElem()){
            
            if(nodo->esHoja(nodo)){

                nodo = NULL;
            }
            else{
                if(nodo->getSubIzq()!= NULL){
                    aux=mayor(nodo->getSubIzq());
                    nodo->setElem(aux);
                    eliminar(aux, nodo->getSubIzq());

                }else{
                    aux=menor(nodo->getSubDer());
                    nodo->setElem(aux);
                    eliminar(aux, nodo->getSubDer());
                }    
            }
        }
    } 
}

}; 

