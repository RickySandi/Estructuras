#pragma once
#include "Nodo.h"

using namespace std;
template <class T>

class Monticulo 
{
private:
int tam = 10000; 
	Nodo<T> * vec[10000];
    int ultimaHoja;
public:
    Monticulo()
	{
		for (int i=1 ; i < tam ; i++) {
         vec[i] = new Nodo<T>();
		}
		//ultimaHoja = 0; 
	}
	~Monticulo() 
	{

	}
void insertar(T elemento, int raiz =1){
	if(vec[1]->getExisteNodo()==false){
		//cout<<"ENTRA"<<endl; 
        ultimaHoja=1;
        vec[ultimaHoja]->setElem(elemento);
        vec[ultimaHoja]->setExisteNodo(true);
		//cout<<"vec[1] "<<vec[1]->getElem()<<endl;
    }
	else{
    	ultimaHoja = ultimaHoja + 1;
    	vec[ultimaHoja]->setElem(elemento);
  		vec[ultimaHoja]->setExisteNodo(true);
   		recuperarAbajoArriba(ultimaHoja);
    }
    
}
void recuperarAbajoArriba(int raiz =1){
	int aux;
    if (vec[raiz/2]->getExisteNodo()){
        if (vec[raiz]->getElem() > vec[raiz/2]->getElem()) {
            aux=vec[raiz/2]->getElem();
            vec[raiz/2]->setElem(vec[raiz]->getElem());
            vec[raiz]->setElem(aux);

            recuperarAbajoArriba(raiz/2);
         }
    }
} 
void mostrarInOrder(int raiz =1){
   // cout<<"ENTRA"<<endl;
    if(vec[raiz]->getExisteNodo()){ 
        mostrarInOrder(raiz*2); //izquierda
        vec[raiz]->mostrar();
        mostrarInOrder(raiz*2 +1); //derecha 
    }
}
    
// void mostrarPreOrder(int raiz =1){
     
//     if(raiz != NULL){
//         nodo->mostrar();
//         mostrarPreOrder(raiz*2); //izquierda
//         mostrarPreOrder(raiz*2 +1); //derecha 
//     }
    
// }
// void mostrarPostOrder(int raiz =1){
    
//     if(raiz != NULL){
//         mostrarPostOrder(raiz*2); //izquierda
//         mostrarPostOrder(raiz*2 +1); //derecha 
//         nodo->mostrar();
//     }
    
// }
int contarNodos(int raiz =1){
     
    if(vec[raiz]->getExisteNodo()){
        //cout<<"entra"<<endl; 
        return 1 + contarNodos(raiz*2) + contarNodos(raiz*2 +1);
    } else{
        return 0;
    }
}
int altura(int raiz=1){
    
    if(vec[raiz]->getExisteNodo()){
       int alturaIzq= altura(raiz*2);
       int alturaDer = altura(raiz*2 +1);
       
        return max(alturaIzq, alturaDer)+1;
    } else{
        return 0;
    }
}
int eliminar(int raiz=1){
	int mayor; 
	if(vec[raiz]->getExisteNodo()){
		mayor = vec[1]->getElem();
        vec[1]->setElem(vec[ultimaHoja]->getElem()) ;
        vec[ultimaHoja]->setExisteNodo(false);
        ultimaHoja = ultimaHoja - 1;
       recuperarArribaAbajo();
        
    }
    return mayor;

}

void recuperarArribaAbajo(int raiz =1){
	int aux;
    if(vec[raiz*2]->getExisteNodo() && vec[raiz*2+1]->getExisteNodo()){
        if(vec[raiz*2]->getElem() < vec[raiz*2+1]->getElem() && vec[raiz*2+1]->getElem() >= vec[raiz]->getElem()){
            aux = vec[raiz]->getElem();
            vec[raiz]->setElem(vec[raiz*2+1]->getElem());
            vec[raiz*2+1]->setElem(aux);
            recuperarArribaAbajo(raiz*2+1);

        }else if(vec[raiz*2]->getElem() > vec[raiz*2+1]->getElem() && vec[raiz*2]->getElem() >= vec[raiz]->getElem()){
            aux = vec[raiz]->getElem();
            vec[raiz]->setElem(vec[raiz*2]->getElem());
            vec[raiz*2]->setElem(aux);
            recuperarArribaAbajo(raiz*2);

        }
	}
}

void defensa(int vec1[500], int vec2[500]){

	for(int i =0; i<500; i++){
		insertar(vec[i]);
	}

	for(int i =0; i<500; i++){
		vec2[i] = vec[1]->getElem();
		eliminar(); 
	}
}


};

