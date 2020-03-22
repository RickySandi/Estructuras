#pragma once
#include <iostream>
#include "Dupla.h"
#include "ABB_Array.h"
using namespace std;

int main(){

    ABB_Array<int>* abb = new ABB_Array<int>(); 
    abb->insertar(10);
    abb->insertar(15);
    abb->insertar(5);
    abb->insertar(3);
    abb->insertar(8);
    abb->insertar(12);
    abb->insertar(20);
    
    // abb->mostrarInOrder();
    // cout<<endl;
    // abb->mostrarPreOrder();
    // cout<<endl;
    // abb->mostrarPostOrder(); 
    
//    cout<<"El arbol tiene "<<abb->contarNodos()<<" nodos"<<endl;
    // cout<<"Altura: "<<abb->altura()<<endl;
     
    // if(abb->buscar(30)){
    //     cout<< "Elemento encontrado"<<endl;
    // } else {
    //     cout<< "Elemento no encontrado"<<endl;
    // }
    cout<< "El mayor es "<<abb->mayor()<<endl;
    cout<< "El menor es "<<abb->menor()<<endl;


}