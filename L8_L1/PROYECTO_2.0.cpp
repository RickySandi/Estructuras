#pragma once
#include <iostream>
#include "Lista_Listas.h"
#include "Cuarteto.h"
using namespace std; 

void mostrarMenu(){
    
    Lista_Listas <int>* lista = new Lista_Listas <int>();  

   int op;
   int v;
   Cuarteto <int>* p = lista->getFirst(); 
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
  
    Lista_Listas  <string>* listaListas = new Lista_Listas <string>();
    Cuarteto <string>* cuarteto_1 = new Cuarteto <string>(); // Docentes

    Lista_1 *  listaEstudiantes = new Lista_1  ();

    cuarteto_1->setValue("Dieter Montanio"); // Docente 
    listaListas->insertFirst(cuarteto_1->getValue()); 
    listaListas->mostrar(); 

    listaEstudiantes->insertarFinal("Estudiante 1"); 
    listaEstudiantes->insertarFinal("Estudiante 2");
    listaEstudiantes->insertarFinal("Estudiante 3");
    listaEstudiantes->mostrarArray(); 
    listaEstudiantes->eliminarFinal();
    listaEstudiantes->mostrarArray(); 
    
    
   
};
