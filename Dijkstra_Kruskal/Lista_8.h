#ifndef Lista_8_h
#define Lista_8_h

#include"Nodo.h"
template<class T>
class Lista_8
{
private:
    Nodo<T> *primero;
    Nodo<T> *ultimo;
    bool elemExistentes;
    int cantElementos;
public:
    Lista_8();
    ~Lista_8();
    void insertarPrincipio(T elem);
    void insertarFinal(T elem, int peso);
    void EliminarPrincipio();
    void EliminarFinal();
    void MostrarLista();
    void MostrarListaInvertida();
    void InvertirLista();
    bool elliminarElementoDado(T el);
    bool buscar(T el);
    void ordenarLista();
    void MoverAlPrincipio(Nodo<T>*aux);
    Nodo<T>* ElementoIPosicion(int posicion);
    bool getElemexistentes();
    Nodo<T>* getUltimo();
    Nodo<T>* getPrimero();
    int getCantElementos();
    
    
};

template<class T>
Lista_8<T>::Lista_8()
{
    primero = NULL;
    ultimo = NULL;
    elemExistentes = false;
    cantElementos = 0;
}

template<class T>
Lista_8<T>::~Lista_8()
{
    //FALTA DELETES//
}

template<class T>
void Lista_8<T>::insertarPrincipio(T elem)
{
    
    elemExistentes = true;
    if (ultimo == NULL && primero == NULL)
    {
        primero = new Nodo<T>;
        primero->setElem(elem);
        ultimo = primero;
        
    }
    else
    {
        Nodo<T>* nuevo;
        nuevo = new Nodo<T>;
        nuevo->setElem(elem);
        nuevo->setSiguiente(primero);
        primero->serAnterior(nuevo);
        primero = nuevo;
    }
}

template<class T>
void Lista_8<T>::insertarFinal(T elem, int peso)
{
    bool resp = false;
    elemExistentes = true;
    if (ultimo == NULL && primero == NULL)
    {
        ultimo = new Nodo<T>;
        ultimo->setElem(elem);
        ultimo->setPeso(peso);
        primero = ultimo;
        resp = true;
    }
    else
    {
        Nodo<T>* aux;
        aux = new Nodo<T>;
        aux->setElem(elem);
        aux->setPeso(peso);
        ultimo->setSiguiente(aux);
        aux->serAnterior(ultimo);
        ultimo = aux;
        resp = true;
    }
    
}
template<class T>
void Lista_8<T>::EliminarPrincipio()
{
    
    cantElementos--;
    if (primero != NULL)
    {
        Nodo<T>* aux;
        aux = primero;
        if (aux->getSiguiente() != NULL)
        {
            aux = aux->getSiguiente();
            aux->serAnterior(NULL);
            delete primero;
            primero = aux;
        }
        else
        {
            delete primero;
            elemExistentes = false;
            primero = NULL;
            ultimo = NULL;
        }
        cout << "eliminado del principio " << endl;
    }
}

template<class T>
void Lista_8<T>::EliminarFinal()
{
    Nodo<T>* aux;
    aux = ultimo->getAnterior();
    aux->setSiguiente(NULL);
    delete ultimo;
    ultimo = aux;
    cout << "eliminado del final " << endl;
}

template<class T>
void Lista_8<T>::MostrarLista()
{
    Nodo<T>* aux;
    aux = primero;
    if (aux == NULL)
        cout << "lista esta vacia" << endl;
    else
    {
        while (aux->getSiguiente() != NULL)
        {
            cout << aux->getElemento()<<"("<<aux->getPeso()<<") ";
            aux = aux->getSiguiente();
        }
       cout << aux->getElemento()<<"("<<aux->getPeso()<<") ";
    }
}

template<class T>
void Lista_8<T>::MostrarListaInvertida()
{
    Nodo<T>* aux;
    aux = ultimo;
    if (aux->getSiguiente() == NULL)
        cout << "lista esta vacia" << endl;
    while (aux->getAnterior() != NULL)
    {
        cout << aux->getElemento() << endl;
        aux = aux->getAnterior();
    }
    cout << aux->getElemento() << endl;
}

template<class T>
void Lista_8<T>::InvertirLista()
{
    Nodo<T>* aux;
    Nodo<T>*aux2;
    Nodo<T>* auxElem;
    aux = primero;
    aux2 = ultimo;
    do
    {
        auxElem = aux;
        aux->setElem(aux2->getElemento());
        aux2->setElem(auxElem->getElemento());
        aux = aux->getSiguiente();
        aux2 = aux2->getAnterior();
        
    } while (aux != aux2 || aux2->getSiguiente() != aux);
}



template<class T>
bool Lista_8<T>::elliminarElementoDado(T el)
{
    Nodo<T>* auxi;
    bool resp = false;
    if (primero != NULL)
    {
        auxi = primero;
        while (auxi->getSiguiente() != NULL && auxi->getElemento() != el)
        {
            auxi = auxi->getSiguiente();
        }
        
        if (auxi->getElemento() == el)
        {
            resp = true;
            Nodo<T>* auxi2;
            if (auxi == primero && auxi == ultimo)
            {
                delete primero;
                primero = NULL;
                ultimo = NULL;
                cantElementos = 0;
                elemExistentes = false;
            }
            else
            {
                if (auxi == ultimo)
                {
                    auxi2 = auxi->getAnterior();
                    auxi2->setSiguiente(NULL);
                    ultimo = auxi2;
                    delete auxi;
                    cantElementos--;
                }
                else
                {
                    if (auxi == primero)
                    {
                        auxi2 = auxi->getSiguiente();
                        auxi2->serAnterior(NULL);
                        primero = auxi2;
                        delete auxi;
                        cantElementos--;
                    }
                    else
                    {
                        if (auxi != primero && auxi != ultimo)
                        {
                            auxi2 = auxi->getSiguiente();
                            auxi2->serAnterior(auxi->getAnterior());
                            auxi2 = auxi->getAnterior();
                            auxi2->setSiguiente(auxi->getSiguiente());
                            delete auxi;
                            cantElementos--;
                        }
                    }
                    
                }
                
            }
            
        }
        
    }
    return resp;
}

template<class T>
bool Lista_8<T>::buscar(T el)
{
    Nodo<T>* auxi;
    bool resp = false;
    if (primero == NULL)
        resp = false;
    else
    {
        auxi = primero;
        while (auxi->getSiguiente() != NULL)
        {
            if (auxi->getElemento() == el)
                resp = true;
            auxi = auxi->getSiguiente();
        }
        if (ultimo->getElemento() == el)
            resp = true;
    }
    return resp;
    
    
}
template<class T>
Nodo<T>* Lista_8<T>::getUltimo()
{
    return ultimo;
}

template<class T>
inline Nodo<T>* Lista_8<T>::getPrimero()
{
    return primero;
}

template<class T>
int Lista_8<T>::getCantElementos()
{
    return cantElementos;
}

template<class T>
void Lista_8<T>::ordenarLista()
{
    Nodo<T>* aux;
    Nodo<T>* aux2;
    while (aux != ultimo)
    {
        for (aux2 = aux; aux2 != NULL; aux2->getSiguiente())
        {
            if (aux2->getElemento() > aux2->getSiguiente()->getElemento())
            {
              //  swap{ {} }
            }
        }
    }
}

template<class T>
void Lista_8<T>::MoverAlPrincipio(Nodo<T>*aux)
{
    Nodo<T>*aux2;
    insertarPrincipio(aux->getElemento());
    aux2 = aux->getAnterior();
    aux2->setSiguiente(aux->getSiguiente());
    aux2 = aux->getSiguiente();
    aux2->serAnterior(aux->getAnterior());
    delete aux;
    
}

template<class T>
Nodo<T>* Lista_8<T>::ElementoIPosicion(int posicion)
{
    /*
     Nodo<T>* aux = primero;
     if (posicion == 1)
     {
     return aux;
     }
     else
     {
     for (int i = 2; i <= posicion; i++)
     {
     aux = aux->getSiguiente();
     if (aux == NULL)
     return NULL;
     
     }
     }
     return aux;
     */
    /*
     int aux;
     aux = pos;
     Nodo<T>*aux2;
     aux2 = primero;
     while (aux != 0)
     {
     aux2 = aux2->getSig();
     aux--;
     }
     if (aux2 == NULL)
     {
     return NULL;
     }
     else
     {
     return aux2->getElem();
     }
     */
    Nodo<T>* aux = primero;
    int aux2 = posicion - 1;
    
    while (aux2 != 0 && aux != NULL)
    {
        aux = aux->getSiguiente();
        aux2--;
    }
    return aux
    ;
    
}

template<class T>
bool Lista_8<T>::getElemexistentes()
{
    return elemExistentes;
}

#endif /* Lista_8_h */
