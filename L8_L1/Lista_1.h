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
	
	int size = 0;
	}

	~Lista_1() {

	}
	void insertarFinal(string nomEstudiante){
		while(TAM > 0 ){
			estudiantes[TAM-size-1] = nomEstudiante; 
			size++;
		}
	}
	void mostrar(){
		for(int i = size; i<TAM;i++){
			cout<<estudiantes[i]<<endl; 
		}
	}
	
		
	
};