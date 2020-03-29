c#pragma once
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
int tam = 1000;
Dupla<T> * vec[1000]; //1000


public:
ABB_Array(){
     for (int i=0 ; i < tam ; i++) {
         vec[i] = new Dupla<T>();
     }
}

~ABB_Array(){
}

void insertar(T elemento, int nodo = 1){ //Testear 
        
    
     if(!vec[nodo]->getExisteNodo()){
        vec[nodo]->setExisteNodo();
        vec[nodo]->setElem(elemento);
      
    }
    else{
        if(elemento < vec[nodo]->getElem()){
            insertar(elemento, nodo*2);
        }
        else if(elemento > vec[nodo]->getElem()){
            insertar(elemento, (nodo*2)+1);

        } else if(elemento == vec[nodo]->getElem()) {
            int cur = vec[nodo]->getCont();
            vec[nodo]->setCont(cur+1);
        }

    }
    // cout << "IMPRIMIR:" << endl << endl;
    // for (int i=0 ; i < tam ; i++) {
    //     cout << vec[i]->getElem() << endl;
    // }
}
void mostrarInOrder(int nodo = 1){
    //cout<<"entra"<< nodo<< "-" <<vec[nodo]->getElem() <<endl; 
    if(vec[nodo]->getExisteNodo()){
        mostrarInOrder(nodo*2); //izquierda
        vec[nodo]->mostrar();
        mostrarInOrder((nodo*2)+1); //derecha 
    }
    
}
void mostrarPreOrder(int nodo = 1){
    //cout<<"entra"<< nodo<< "-" <<vec[nodo]->getElem() <<endl; 
    if(vec[nodo]->getExisteNodo()){
        vec[nodo]->mostrar();
        mostrarPreOrder(nodo*2); //izquierda
        mostrarPreOrder((nodo*2)+1); //derecha 
    }
    
}
void mostrarPostOrder(int nodo = 1){
    //cout<<"entra"<< nodo<< "-" <<vec[nodo]->getElem() <<endl; 
    if(vec[nodo]->getExisteNodo()){
        mostrarPostOrder(nodo*2); //izquierda
        mostrarPostOrder((nodo*2)+1); //derecha 
        vec[nodo]->mostrar();
    }
    
}
int contarNodos(int nodo = 1){
     
    if(vec[nodo]->getExisteNodo()){
        
        return 1 + contarNodos(nodo*2) + contarNodos(nodo*2+1);
    } else{
        return 0;
    }
}
int altura(int nodo =1){
    
    if(vec[nodo]->getExisteNodo()){
       int alturaIzq = altura(nodo*2);
       int alturaDer = altura(nodo*2 + 1);
        return max(alturaIzq, alturaDer) + 1;
    } else{
        return 0;
    }
}
bool buscar(T elemento, int nodo = 1){
    if(vec[nodo]->getExisteNodo()){
        if(vec[nodo]->getElem() == elemento) {
            return true;
        } else {
            if (elemento < vec[nodo]->getElem()) {
               
               return buscar(elemento, nodo*2);
            } else {
                
                return buscar(elemento, nodo*2+ 1);
            }
        }

    } else {
        return false;
    }
}

T menor( int nodo =1){ //izquierda
    if(!vec[nodo*2]->getExisteNodo()){
        return vec[nodo]->getElem();
    }
        return menor(nodo*2);
    }

T mayor( int nodo =1){ //derecha
    if(!vec[(nodo*2)+1]->getExisteNodo()){
        return vec[nodo]->getElem();
    }
        return mayor((nodo*2)+1);
    }

void imprimirNivel(int nodo ,int nivel){
     if(vec[nodo]->getExisteNodo()){
        if(nivel == 1){
            cout<<vec[nodo]->getElem()<<"="<<vec[nodo]->getCont() << " ";
        } 
        else if(nivel > 1){
            imprimirNivel(nodo*2, nivel -1);
            imprimirNivel((nodo*2)+1, nivel -1);

        }
    }
}

void mostrarNivel(int raiz =1){
   // int res,A1,A2
   if(!vec[raiz]->getExisteNodo()){
       cout<< "Arbol vacio"<<endl; 
    }
    else{ 
   int alt = altura(); 
    for (int i =1; i <= alt; i++){
        imprimirNivel(raiz,i);
        cout<<endl; 
        
    }
    }
}
   

}; 

