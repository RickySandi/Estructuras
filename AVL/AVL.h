#pragma once
#include "Nodo.h"

using namespace std;
template <class T>

class AVL
{
private:
	Nodo<T>* nodo;
public:
    AVL()
	{
		nodo = NULL;
	}
	~AVL() 
	{

	}
    void insertar(T elem, Nodo<T>*& raiz, bool& continuar)
   {
    if (raiz == NULL)
	{
		Nodo<T>* nuevaRaiz = new Nodo<T>;
		nuevaRaiz->setElem(elem);
		nuevaRaiz->setFactor(0);
		nuevaRaiz->setSubIzq(NULL);
		nuevaRaiz->setSubDer(NULL);
		raiz = nuevaRaiz;
		continuar = true;
	}
	else
	{
		if (elem < raiz->getElem())
		{
			insertar(elem, raiz->getSubIzq(),continuar);

			if (continuar)
			{
				raiz->setFactor(raiz->getFactor() + 1);
				if (raiz->getFactor() == 0)
				{
					continuar = false;
				}
				else
				{
					if (raiz->getFactor() == 2)
					{
						continuar = false;
						if (raiz->getSubIzq()->getFactor() == 1)
						{
							rotarDerechaSimple(raiz);
						}
						else
						{
							rotarDerechaCompuesto(raiz);
						}
					}
				}
			}
		}
		else
		{
			if (elem > raiz->getElem())
			{
				insertar(elem, raiz->getSubDer(),  continuar);

				if (continuar)
				{
					raiz->setFactor(raiz->getFactor() - 1);
					if (raiz->getFactor() == 0)
					{
						continuar = false;
					}
					else
					{
						if (raiz->getFactor() == -2)
						{
							continuar = false;
							if (raiz->getSubDer()->getFactor() == -1)
							{
								rotarIzquirdaSimple(raiz);
							}
							else
							{
								rotarIzquirdaCompuesto(raiz);
							}
						}
					}
				}
			}
		}
	}
}

	// void rotarIzquirdaSimple(Nodo<T>*& nodo){
	//     Nodo<T>* nuevo = nodo->getSubDer();
	// 	Nodo<T>* flotante;
	// 	if (nuevo->getSubIzq() != NULL){
	// 		flotante = nuevo->getSubIzq();
	// 	}
	// 	else{
	// 		flotante = NULL;
	// 	}
	// 	nuevo->getSubIzq() = nodo;
	// 	nodo->setSubDer(flotante);
	// 	nodo = nuevo;
	// }
    void rotarIzquirdaSimple(Nodo<T>*& raiz){
       	Nodo<T>* aux = new Nodo<T>;
	    Nodo<T>* nuevo = raiz->getSubDer();

	    if (nuevo->getSubIzq() != NULL)
	    {
		aux = nuevo->getSubIzq();
	    }
	    else
	    {
		    aux = NULL;
	    }

	    nuevo->setSubIzq(raiz);
	    raiz->setSubDer(aux);
	    nuevo->setFactor(0);
	    raiz->setFactor(0);

	raiz = nuevo;
    }

	// void rotarDerechaSimple(Nodo<T>*& nodo){

	// 	Nodo<T>* nuevo = nodo->getSubIzq();
	// 	Nodo<T>* flotante;

	// 	if (nuevo->getSubDer() != NULL){
	// 		flotante = nuevo->getSubDer();
	// 	}
	// 	else{
	// 		flotante = NULL;
	// 	}
	// 	nuevo->setSubDer(nodo);
	// 	nodo->setSubIzq(flotante);
	// 	nodo = nuevo;
	// }

    void rotarDerechaSimple(Nodo<T>*& raiz){
       	Nodo<T>* aux = new Nodo<T>;
	    Nodo<T>* nuevo = raiz->getSubIzq();

	if (nuevo->getSubDer() != NULL)
	{
		aux = nuevo->getSubDer();
	}
	else
	{
		aux = NULL;
	}

	nuevo->setSubDer(raiz);
	raiz->setSubIzq(aux);
	nuevo->setFactor(0);
	raiz->setFactor(0);

	raiz = nuevo;
    }

    void rotarIzquirdaCompuesto(Nodo<T>*& raiz){
        
	Nodo<T>* nuevaRaiz = raiz->getSubDer()->getSubIzq();
	Nodo<T>* hd = nuevaRaiz->getSubDer();
	Nodo<T>* hi = nuevaRaiz->getSubIzq();

	nuevaRaiz->setSubDer(raiz->getSubDer());
	nuevaRaiz->setSubIzq(raiz);

	raiz->setSubDer(hi);
	nuevaRaiz->getSubDer()->setSubIzq(hd);
	raiz = nuevaRaiz;

	if (raiz->getFactor() == 0)
	{
		raiz->getSubIzq()->setFactor(0);
		raiz->getSubDer()->setFactor(0);
		raiz->setFactor(0);
	}

	if (raiz->getFactor() == -1)
	{
		raiz->getSubIzq()->setFactor(1);
		raiz->getSubDer()->setFactor(0);
		raiz->setFactor(0);
	}

	if (raiz->getFactor() == 1)
	{
		raiz->getSubIzq()->setFactor(0);
		raiz->getSubDer()->setFactor(-1);
		raiz->setFactor(0);
	}
}

 


void rotarDerechaCompuesto(Nodo<T>*& raiz){
	Nodo<T>* nuevaRaiz = raiz->getSubIzq()->getSubDer();
	Nodo<T>* hd = nuevaRaiz->getSubDer();
	Nodo<T>* hi = nuevaRaiz->getSubIzq();

	nuevaRaiz->setSubIzq(raiz->getSubIzq());
	nuevaRaiz->setSubDer(raiz);

	raiz->setSubIzq(hd);
	nuevaRaiz->getSubIzq()->setSubDer(hi);
	raiz = nuevaRaiz;

	if (raiz->getFactor() == 0)
	{

		raiz->getSubIzq()->setFactor(0);
		raiz->getSubDer()->setFactor(0);
		raiz->setFactor(0);
	}

	if (raiz->getFactor() == -1)
	{
		raiz->getSubIzq()->setFactor(1);
		raiz->getSubDer()->setFactor(0);
		raiz->setFactor(0);
	}

	if (raiz->getFactor() == 1)
	{
		raiz->getSubIzq()->setFactor(0);
		raiz->getSubDer()->setFactor(-1);
		raiz->setFactor(0);
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
       int alturaIzq= altura(nodo->getSubIzq());
       int alturaDer = altura(nodo->getSubDer());
       
        return max(alturaIzq, alturaDer)+1;
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

Nodo<T>*& getRaiz(){
		return nodo;
	}

};

