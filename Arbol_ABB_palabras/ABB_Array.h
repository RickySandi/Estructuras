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
+ Eliminar al azar 
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
// int altura(int nodo =1){
    
//     if(vec[nodo]->getExisteNodo()){
//        int alturaIzq = altura(nodo*2);
//        int alturaDer = altura(nodo*2 + 1);
//         return max(alturaIzq, alturaDer) + 1;
//     } else{
//         return 0;
//     }
// }
// bool buscar(T elemento, int nodo = 1){
//     if(vec[nodo]->getExisteNodo()){
//         if(vec[nodo]->getElem() == elemento) {
//             return true;
//         } else {
//             if (elemento < vec[nodo]->getElem()) {
               
//                return buscar(elemento, nodo*2);
//             } else {
                
//                 return buscar(elemento, nodo*2+ 1);
//             }
//         }

//     } else {
//         return false;
//     }
// }

// T menor( int nodo =1){ //izquierda
//     if(!vec[nodo*2]->getExisteNodo()){
//         return vec[nodo]->getElem();
//     }
//         return menor(nodo*2);
//     }

// T mayor( int nodo =1){ //derecha
//     if(!vec[(nodo*2)+1]->getExisteNodo()){
//         return vec[nodo]->getElem();
//     }
//         return mayor((nodo*2)+1);
//     }

// void imprimirNivel(int nodo ,int nivel){
//      if(vec[nodo]->getExisteNodo()){
//         if(nivel == 1){
//             cout<<vec[nodo]->getElem()<<"="<<vec[nodo]->getCont() << " ";
//         } 
//         else if(nivel > 1){
//             imprimirNivel(nodo*2, nivel -1);
//             imprimirNivel((nodo*2)+1, nivel -1);

//         }
//     }
// }

// void mostrarNivel(int raiz =1){
//    // int res,A1,A2
//    if(!vec[raiz]->getExisteNodo()){
//        cout<< "Arbol vacio"<<endl; 
//     }
//     else{ 
//    int alt = altura(); 
//     for (int i =1; i <= alt; i++){
//         imprimirNivel(raiz,i);
//         cout<<endl; 
        
//     }
//     }
// }
   

}; 

