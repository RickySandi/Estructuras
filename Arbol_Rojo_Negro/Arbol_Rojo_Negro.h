#pragma once
#include "Nodo.h"

using namespace std;
template <class T>

class Arbol_Rojo_Negro
{
private:
	Nodo<T>* nodo;
public:
    Arbol_Rojo_Negro()
	{
		nodo = NULL;
	}
	~Arbol_Rojo_Negro() 
	{

	}
	void insertar(T elemento, Nodo<T>*& nodo, bool* continuar, bool* paridad, bool* lado)		//lado false = der	// paridad false = impar
	{
		Nodo<T>*& nuevo = nodo;
		if (nodo == NULL){
		    nuevo = new Nodo<T>();
			nuevo->setColor('R');  
			nuevo->setElemento(elemento);
			nodo = nuevo;
			*continuar = true;
			*paridad = true;
		}
		else{
			if (elemento < nodo->getElemento()){
				insertar(elemento, nodo->getSubIzq(), continuar, paridad, lado);
				if (*continuar == true){
					if (*paridad == true){
						if (nodo->getColor() == 'N'){
							*continuar = false;
						}
						else{
							*paridad = false;
							*lado = true;
						}
					}
					else{
						if (*paridad == false){
							if (nodo->getSubDer() != NULL && nodo->getSubDer()->getColor() == 'R'){
								nodo->getSubIzq()->setColor('N');
								nodo->getSubDer()->setColor('N');
								nodo->setColor('R');
								*paridad = true;
							}
							else{
								*continuar = false;

								if (*lado == false){
									rotarIzquirda(nodo->getSubIzq());
								}
								nodo->getSubIzq()->setColor('N');
								nodo->setColor('R');
								rotarDerecha(nodo);
							}
						}
					}
				}
			}
			if (elemento > nodo->getElemento()){
				insertar(elemento, nodo->getSubDer(), continuar, paridad, lado);
				if (*continuar == true){
					if (*paridad == true){
						if (nodo->getColor() == 'N'){
							*continuar = false;
						}
						else{
							*paridad = false;
							*lado = false;
						}
					}
					else{
						if (*paridad == false){
							if (nodo->getSubIzq() != NULL && nodo->getSubIzq()->getColor() == 'R'){
								nodo->getSubIzq()->setColor('N');
								nodo->getSubDer()->setColor('N');
								nodo->setColor('R');
								*paridad = true;
							}
							else{
								*continuar = false;
								if (*lado == true){
									rotarDerecha(nodo->getSubDer());
								}
								nodo->getSubDer()->setColor('N');
								nodo->setColor('R');
								rotarIzquirda(nodo);
							}
						}
					}
				}
			}
		}
	}

	void rotarIzquirda(Nodo<T>*& nodo)
	{
		Nodo<T>* nuevo = nodo->getSubDer();
		Nodo<T>* flotante;
		if (nuevo->getSubIzq() != NULL){
			flotante = nuevo->getSubIzq();
		}
		else{
			flotante = NULL;
		}
		nuevo->getSubIzq() = nodo;
		nodo->setSubDer(flotante);
		nodo = nuevo;
	}

	void rotarDerecha(Nodo<T>*& nodo){
		Nodo<T>* nuevo = nodo->getSubIzq();
		Nodo<T>* flotante;

		if (nuevo->getSubDer() != NULL){
			flotante = nuevo->getSubDer();
		}
		else{
			flotante = NULL;
		}
		nuevo->setSubDer(nodo);
		nodo->setSubIzq(flotante);
		nodo = nuevo;
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

Nodo<T>*& getRaiz(){
		return nodo;
	}
};

