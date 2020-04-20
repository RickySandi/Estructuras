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
    bool insertar(T elemento, Nodo<T>*& nodo)
   {
    bool continuar=false;
    Nodo<T>* nuevo;
    if (nodo == NULL)
    {
        nuevo = new Nodo<T>;
        nuevo->setElem(elemento);
        nuevo->setCont(0);
        nuevo->setSubDer(NULL);
        nuevo->setSubIzq(NULL);
        nodo = nuevo;
        continuar = true;
        
    }
    else{
        if (elemento < nodo->getElem())
        {
            continuar = insertar(elemento, nodo->getSubIzq());
            if (continuar == true)
            {
                nodo->setCont(nodo->getCont() + 1);
                if (nodo->getCont() == 0)
                    continuar = false;
                else{
                    if (nodo->getCont() == 2)
                    {
                        continuar = false;
                        if (nodo->getSubIzq()->getCont() == 1)
                            rotarDerechaSimple(nodo); 
                        else{
                            if (nodo->getSubIzq()->getCont() == -1)
                            rotarDerechaCompuesto(nodo);
                        }
                    }
                }
            }
        }
        else
        {
            if (elemento > nodo->getElem())
            {
                continuar = insertar(elemento, nodo->getSubDer());
                if (continuar == true)
                {
                    nodo->setCont(nodo->getCont() - 1);
                    if (nodo->getCont() == 0)
                        continuar = false;
                    else{
                        if (nodo->getCont() == -2)
                        {
                            continuar = false;
                            if (nodo->getSubDer()->getCont() == -1)
                                rotarIzquirdaSimple(nodo); 
                            else{
                                if (nodo->getSubDer()->getCont() == 1)
                                    rotarIzquirdaCompuesto(nodo); 
                            }
                            
                        }
                    }
                }
            }
        }
    }
    return continuar;
}

	void rotarIzquirdaSimple(Nodo<T>*& nodo){
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

	void rotarDerechaSimple(Nodo<T>*& nodo){

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

    void rotarIzquirdaCompuesto(Nodo<T>*& nodo){
        
        Nodo<T>* nuevaRaiz = nodo->getSubDer()->getSubIzq();
        Nodo<T>* hd = nuevaRaiz->getSubDer(); 
        Nodo<T>* hi = nuevaRaiz->getSubIzq(); 

        nuevaRaiz->setSubDer(nodo->getSubDer());
        nuevaRaiz->setSubIzq(nodo);
        nodo->setSubDer(hi); 
        nuevaRaiz->getSubDer()->setSubIzq(hd);
        nodo = nuevaRaiz; 
        if (hd == NULL && hi == NULL)
        {
            nodo->getSubIzq()->setCont(0);
            nodo->getSubDer()->setCont(0);
            nodo->setCont(0);
        }
        if (hi == NULL && hd != NULL)
        {
            nodo->getSubIzq()->setCont(1);
            nodo->getSubDer()->setCont(0);
            nodo->setCont(0);
        }
        if (hi != NULL && hd == NULL)
        {
            nodo->getSubIzq()->setCont(0);
            nodo->getSubDer()->setCont(-1);
            nodo->setCont(0);
        }
}

void rotarDerechaCompuesto(Nodo<T>*& nodo){
    Nodo<T>* nuevaRaiz = nodo->getSubIzq()->getSubDer();
    Nodo<T>* hd = nuevaRaiz->getSubDer(); 
    Nodo<T>* hi = nuevaRaiz->getSubIzq(); 

    nuevaRaiz->setSubIzq(nodo->getSubIzq());
    nuevaRaiz->setSubDer(nodo);
    nodo->setSubIzq(hd); 
    nuevaRaiz->getSubIzq()->setSubDer(hi);
    nodo = nuevaRaiz; 
    if (hd == NULL && hi == NULL)
    {
        nodo->getSubIzq()->setCont(0);
        nodo->getSubDer()->setCont(0);
        nodo->setCont(0);
    }
    if (hi == NULL && hd != NULL)
    {
        nodo->getSubIzq()->setCont(1);
        nodo->getSubDer()->setCont(0);
        nodo->setCont(0);
    }
     if (hi != NULL && hd == NULL)
    {
        nodo->getSubIzq()->setCont(0);
        nodo->getSubDer()->setCont(-1);
        nodo->setCont(0);
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
       int altunodoq= altura(nodo->getSubIzq());
       int alturaDer = altura(nodo->getSubDer());
       
        return max(altunodoq, alturaDer)+1;
    } else{
        return 0;
    }
}
bool buscar(T elementoemento,Nodo <T> *nodo){
    if(nodo != NULL){
        if(nodo->getElem() == elementoemento) {
            return true;
        } else {
            if (elementoemento < nodo->getElem()) {
               
               return buscar(elementoemento, nodo->getSubIzq());
            } else {
                
                return buscar(elementoemento, nodo->getSubDer());
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

