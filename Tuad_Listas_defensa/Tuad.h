#pragma once
#include<iostream>
#include <string>
#include "Lista_8.h"
using namespace std;
template <class T>

class Tuad {

private:
    Lista_8 <string> vec[50];
public:
    Tuad(){

    }
    void insertarTuad(T palabra){

        vec[palabra.length()].insertarEnSuLugar(palabra);
    }
    void mostrar() {
        for (int i = 0; i < 50; i++) {
            vec[i].mostrar();
        }
    }
    void buscar(T palabra){
		bool parametro = false; 
        parametro = vec[palabra.length()].buscar(palabra); 
        if(parametro){
            cout<<"El valor se encuentra en la lista"<<endl;
        } 
        else{
            cout<<"El valor no se encuentra en la lista"<<endl;
        }
	}
    ~Tuad() {

    }



};