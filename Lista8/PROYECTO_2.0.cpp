#pragma once
#include <iostream>
#include "Lista_8.h"
#include "Terna.h"
using namespace std; 

void mostrarMenu(){
    
    Lista_8 <int>* lista = new Lista_8 <int>();  

   int op;
   int v;
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
    cout<<"11.Buscar elemento"<<endl;
    cout<<"12.Eliminar toda la lista"<<endl;
    cout<<"13.Salir"<<endl;
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
         //lista->eraseBack();
        break;
    case 5 :
         lista->mostrar();
        break;
    case 6 :
    
        cout<<"Ingresa un valor a buscar"<<endl; 
        cin>>v;
        //lista->buscar(v);
        break;
    case 7 :
       // lista->invertirLista(); 
        break; 
    case 8: 
        break;
    default:
        break;
    }
        }while (op!=13);
    }
        
int main()
{
    Lista_8 <int>* lista = new Lista_8 <int>();

 
    lista->insertFirst(19);
    lista->insertFirst(34);
    lista->insertFirst(56);
    lista->insertFirst(100);
    

    lista->invertir(); 
    lista->mostrar();

   // lista->eliminarElemento(2); 
   // lista->mostrar();

    lista->insertarEnSuLugar(48);
    lista->mostrar(); 


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
}
