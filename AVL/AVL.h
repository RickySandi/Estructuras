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
	void insertar(T elemento, Nodo<T>*& nodo, bool* continuar)
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
    else
    {
       
        if (elemento < nodo->getElem())
        {
            continuar = insertar(elemento, nodo->getSubIzq());     
            if (continuar == true)
            {
                nodo->setCont(nodo->getCont() + 1);
                if (nodo->getCont() == 0)
                    continuar = false;
                else
                {
                    if (nodo->getCont() == 2)
                    {
                        continuar = false;
                        if (nodo->getSubIzq()->getCont() == 1)
                            RDS(nodo); // rotar derecha simple
                        else
                        {
                            if (nodo->getSubIzq()->getCont() == -1)
                                RDC(nodo); // rotar derecha compuesto
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
                    else
                    {
                        if (nodo->getCont() == -2)
                        {
                            continuar = false;
                            if (nodo->getSubDer()->getCont() == -1)
                                RIS(nodo); // rotar izquierda simple
                            else
                            {
                                if (nodo->getSubDer()->getCont() == 1)
                                    RIC(nodo); // rotar izquierda compuesto
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
		Nodo<T>* nuevaRaiz = nodo->getSubDer();
        Nodo<T>* hi = nodo->getSubIzq();
    
        nuevaRaiz->setSubIzq(nodo);
        nodo->setSubDer(hi);
        nuevaRaiz->setCont(0);
        nodo->setCont(0);
        nodo = nuevaRaiz;
	}

	void rotarDerechaSimple(Nodo<T>*& nodo){

		Nodo<T>* nuevaRaiz = nodo->getSubIzq();
        Nodo<T>* hi = nodo->getSubdDer();
    
        nuevaRaiz->setSubDer(nodo);
        nodo->setSubIzq(hi);
        nuevaRaiz->setCont(0);
        nodo->setCont(0);
        nodo = nuevaRaiz;
	}

    void rotarIzquirdaCompuesto(Nodo<T>*& nodo){
        
        Nodo<T>* nuevaRaiz = nodo->getSubDer()->getSubIzq();
        Nodo<T>* hd = nuevaRaiz->getSubDer(); ;
        Nodo<T>* hi = nuevaRaiz->getSubIzq(); ;
      
        nuevaRaiz->setIzq(nodo);
        nuevaRaiz->setDer(nodo->getSubDer());
        nodo->setDer(hi);
        nuevaRaiz->getSubDer()->setIzq(hd);
             if (hd == NULL && hi == NULL){
                nuevaRaiz->getSubIzq()->setCont(0);
                nodo->setCont(0);
            }
             else{
                if (hd == NULL){
                nuevaRaiz->getSubDer()->setCont(-1);
                nodo->setCont(0);
            }
            else{
            if (hi == NULL){
                nuevaRaiz->getSubDer()->setCont(0);
                nodo->setCont(1);
            }
        }
    }
    nodo = nuevaRaiz;
    nodo->setCont(0);
}

void rotarDerechaCompuesto(Nodo<T>*& nodo){
    Nodo<T>* nuevaRaiz = nodo->getIzq()->getDer();
    Nodo<T>* hd = nuevaRaiz->getSubDer(); 
    Nodo<T>* hi = nuevaRaiz->getSubIzq(); 

    nuevaRaiz->setDer(nodo);
    nuevaRaiz->setIzq(nodo->getIzq());
    nodo->setIzq(hd);
    nuevaRaiz->getIzq()->setDer(hi);
    if (hd == NULL && hi == NULL)
    {
        nuevaRaiz->getIzq()->setCont(0);
        raiz->setCont(0);
    }
    else
    {
        if (hd == NULL)
        {
            nuevaRaiz->getIzq()->setCont(0);
            nodo->setCont(-1);
        }
        else
        {
            if (hi == NULL)
            {
                nuevaRaiz->getIzq()->setCont(1);
                nodo->setCont(0);
            }
        }
    }
    nodo = nuevaRaiz;
    nodo->setCont(0);
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
       int altunodoq = altura(nodo->getSubIzq());
       int alturaDer = altura(nodo->getSubDer());
        return max(altunodoq, alturaDer) + 1;
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

bool hijoNegro(Nodo <T> *nodo){
	
	bool res = false;
	if (nodo != NULL ){
		if (nodo->getColor() == 'R'){
			if (nodo->getSubIzq() != NULL && nodo->getSubDer() != NULL){
				if (nodo->getSubIzq()->getColor() == 'N' && nodo->getSubDer()->getColor() == 'N'){
					res = true;
				}
				else{ res = false;}
			}
			else{ res = true;}

			if (nodo->getSubIzq() != NULL && nodo->getSubDer() == NULL){
				if (nodo->getSubIzq()->getColor() == 'N'){

					res = true;
				}
				else{ res = false;}
			}
			else
			{
				if (nodo->getSubDer()->getColor() == 'N'){
					res = true;
				}
				else{ res = false;}
			}
		}
		else
		{
			res = hijoNegro(nodo->getSubIzq());
			res = hijoNegro(nodo->getSubDer());
		}
	}
	else{ res = false;}

	return res;
}


Nodo<T>*& getnodo(){
		return nodo;
	}
};

