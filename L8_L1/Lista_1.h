#pragma once
#include "Cuarteto.h"
using namespace std;

# define TAM 40

//template <class T>
 

class Lista_1 			//Vector de estudiantes
{
private:

	 int size;
	 string estudiantes [TAM]; 
	 string nomEstudiante; 
public:
	Lista_1() {
	
	 size = 0;
	}

	~Lista_1() {

	}
	void insertarFinal(string nomEstudiante){
		
		if(size < TAM){

			estudiantes[TAM-1-size] = nomEstudiante; 
			size++;
		}	
	}

	void eliminarFinal(){
		
			estudiantes[size] = ""; 
			size--;
	}	

	bool buscar(string nomEstudiante){ // convertir a bool 

	cout<<"size"<<size<<endl;
	cout<<"TAM -1"<<TAM -1<<endl; 
		
		//string res = "Estudiante no encontrado";
		bool res = false; 
		
		for(int i= TAM-1 ; i >=size; i--){
			if(estudiantes[i] == nomEstudiante){
				res = true; 
			//	return true; 
				
			}
		}
	
		return res;
		
		
	}
	
	void mostrarArray(){

		for(int i = TAM -1; i >= TAM - size;i--){
			cout<<estudiantes[i]<<endl; 
		}
	}
	
		
	
};