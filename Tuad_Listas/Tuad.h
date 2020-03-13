#pragma once
#include<iostream>
#include <string>
#include "Lista_8.h"
using namespace std;
template <class T>

class Tuad{

private:
Lista_8 <T> vec[46]; 
public: 
Tuad(){
    
	
}
~Tuad(){

}
void insertarTuad(T palabra){
    cout<<"Hola"<<endl;
    cout<<"long "<<strlen(palabra.c_str());
    vec[palabra.c_str()].insertarEnSuLugar(palabra); 

}
void mostrar(){
    for(int i=0;i<46;i++){
        vec[i].mostrar(); 
    }
}




};