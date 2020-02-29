#pragma once
#include <iostream>
#include "Lista_8.h"
#include "Terna.h"
using namespace std; 

void mostrarMenu(){
    
    Lista_8 <int>* lista = new Lista_8 <int>();  

   int op;
   int v;
   Terna <int>* p = lista->getFirst(); 
   do{
    cout<<"-----MENU-----"<<endl;
    cout<<"1.Insertar al principio"<<endl;
    cout<<"2.Insertar al final"<<endl;
    cout<<"3.Eliminar al principio"<<endl;
    cout<<"4.Eliminar al final"<<endl;
    cout<<"5.Mostar"<<endl;
    cout<<"6.Buscar"<<endl;
    cout<<"7.Buscar Recursivo"<<endl;
    cout<<"8.Insertar en su lugar"<<endl;
    cout<<"9.Eliminar elemento dado"<<endl;
    cout<<"10.Invertir"<<endl;
    cout<<"11.Buscar elemento en la i posicion"<<endl;
    cout<<"12.Eliminar toda la lista"<<endl;
   // cout<<"13.Fusionar dos listas"<<endl;
    cout<<"14.Salir"<<endl;
    cout<<endl;
    cout<<"Ingresa una opcion"<<endl; 
    cin>>op; 

     
    switch (op)
    {
    
    case 1 :
        //int v; 
        cout<<"Ingresa un valor"<<endl; 
        cin>>v;
        lista->insertFirst(v);
        break;
    case 2 :
        // int v; 
        cout<<"Ingresa un valor"<<endl; 
        cin>>v;
         lista->insertBack(v);
        break;
    case 3 :
         lista->deleteFirst();
        break;
    case 4 :
         lista->deleteBack();
        break;
    case 5 :
         lista->mostrar();
        break;
    case 6 :
    
        cout<<"Ingresa un valor a buscar"<<endl; 
        cin>>v;
        lista->buscar(v);
        break;
    case 7 :
        
        cout<<"Ingresa un valor a buscar"<<endl; 
        cin>>v;
        lista->buscarRecursivo(v, p); 
        break; 
    case 8: 
        cout<<"Ingresa un valor"<<endl; 
        cin>>v;
        lista->insertarEnSuLugar(v);
        break;
    case 9: 
        cout<<"Ingresa un valor a eliminar"<<endl; 
        cin>>v;
        lista->eliminarElemento(v);
        break;
    case 10: 
        lista->invertir();
        break;
    case 11: 
        cout<<"Ingresa la posicion a buscar"<<endl; 
        cin>>v;
        lista->buscarIPos(v);
        break;
    case 12:
        lista->deleteList();
     case 13:
       // lista->deleteList();
    default:
        break;
    }
        }while (op!=14);
    }
        
int main()
{
   // mostrarMenu(); 
  
    Lista_8 <int>* lista = new Lista_8 <int>();
    Lista_8 <int>* lista2 = new Lista_8 <int>();
    Lista_8 <int>* lista3 = new Lista_8 <int>();

     lista2->insertFirst(100);
    lista2->insertFirst(56);
    lista2->insertFirst(34);
    lista2->insertFirst(19);

    lista->insertFirst(200);
    lista->insertFirst(150);
     lista->insertFirst(20);
    lista->insertFirst(10);

    
    Terna <int>* primeroLista = lista->getFirst(); 
    Terna <int>* primeroLista2 = lista2->getFirst();

    //lista2->mostrar();


    lista3 = lista->fusionarListas(primeroLista2);
    lista3->mostrar(); 

    lista->mostrar();
    lista2->mostrar();

    

  /* 
   lista->eliminarElemento(34); 
     lista->mostrar();
   lista->eliminarElemento(56);
     lista->mostrar();
   lista->eliminarElemento(19);
     lista->mostrar();
    lista->eliminarElemento(100); 
   lista->mostrar();
   */
  
    //lista->insertarEnSuLugar(10);
    //lista->insertarEnSuLugar(58);
    //lista->insertarEnSuLugar(93);
    /*
    lista->mostrar();
    lista->eliminarElemento(19);
    lista->eliminarElemento(100);
    lista->mostrar();
    lista->eliminarElemento(10);
    lista->mostrar();
    */

    //  lista->insertarEnSuLugar(-8);
  //  lista->insertarEnSuLugar(-2);
   // lista->mostrar(); 

   /* 
    lista->insertarEnSuLugar(1);
    lista->mostrar(); 
    lista->insertarEnSuLugar(200);
    lista->mostrar(); 
    */


  // lista->deleteList();
    //lista->mostrar();
    /* 
    int val1 = lista->searchPos(2);
    cout<<val1<<endl; 
    int val2 =lista->searchPos(4);
    cout<<val2<<endl; 
    */
   
/* 
     string i = lista->buscarRecursivo(40, lista->getFirst());
    string x = lista->buscarRecursivo(30, lista->getFirst());
    cout << i;
    cout<<endl;
    cout << x;
    cout<<endl;
*/
    //lista->invertir(); 
   // lista->mostrar(); 

    /* 
    lista->buscar(20);
    lista->buscar(50);
    lista->buscar(100);
    lista->buscar(-50);
    lista->buscar(10);
    */

    /* 
    lista->deleteFirst();
    lista->mostrar();

    lista->insertBack(40);
    lista->insertBack(100);
    lista->mostrar(); 

    lista->deleteBack();
    lista->deleteBack();
    lista->deleteBack(); 
    lista->mostrar(); 
   */
};
