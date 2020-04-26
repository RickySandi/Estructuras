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
    
    if(vec[raiz]->getExisteNodo() != false){ 
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
    
    if(raiz != NULL){
       int alturaIzq= altura(raiz*2);
       int alturaDer = altura(raiz*2 +1);
       
        return max(alturaIzq, alturaDer)+1;
    } else{
        return 0;
    }
}

};

