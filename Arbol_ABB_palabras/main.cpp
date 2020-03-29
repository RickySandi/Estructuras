#pragma once
#include <iostream>
#include <fstream>
#include "Nodo.h"
#include "ABB_Array.h"
using namespace std;
/*
Insertar contando en el árbol
Recorrer IN Order
Recorrer PRE Order
Recorrer POST Order
Contar Nodos
Calcular la altura del árbol
Buscar
Encontrar el Menor
Encontrar el Mayor
+ Eliminar al azar 
*/

// void mostrarMenu() 
// {
//     ABB_Array<string>* abb = new ABB_Array<string>();
//     int op;
//     string v;
//     fstream archEntrada;
//     string palabra;
   
//     do {
//         cout << "-----MENU-----" << endl;
//         cout << "1.Insertar valor" << endl;
//         cout << "2.Recorrer IN Order" << endl;
//         cout << "3.Recorrer PRE Order" << endl;
//         cout << "4.Recorrer POST Order" << endl;
//         cout << "5.Contar nodos" << endl;
//         cout << "6.Calcular altura" << endl;
//         cout << "7.Buscar" << endl;
//         cout << "8.Encontrar mayor" << endl;
//         cout << "9.Encontrar menor" << endl;
//         cout<<  "10. Mostrar por niveles"<<endl;
//         cout << "11.Eliminar al azar" << endl;
//         cout << "12.Insertar libro" << endl;
//         cout << "13.Salir" << endl;
//         cout << endl;
//         cout << "Ingresa una opcion" << endl;
//         cin >> op;
//         switch (op)
//         {
//         case 1:
//             cout << "Ingresa un valor para insertar" << endl;
//             cin >> v;
//            // abb->insertar(v);
//             break;
//         case 2:
//             cout << "Mostrando Arbol IN Order" << endl;
//             abb->mostrarInOrder();
//             cout<<endl;
//             break;
//         case 3:
//             cout << "Mostrando Arbol PRE Order" << endl;
//             abb->mostrarPreOrder();
//             cout<<endl;
//             break;
//         case 4:
//             cout << "Mostrando Arbol POST Order" << endl;
//             abb->mostrarPostOrder();
//             cout<<endl;
//             break;
//         case 5:
//             cout<<"El arbol tiene "<<abb->contarNodos()<<" nodos"<<endl;
//             break;

//         case 6:
//             cout<<"Altura: "<<abb->altura()<<endl; 
//             break;

//         case 7:
//             cout << "Ingresa un valor para buscar" << endl;
//             cin>>v; 
//             if(abb->buscar(v)){
//                 cout<< "Elemento encontrado"<<endl;
//             } else {
//                 cout<< "Elemento no encontrado"<<endl;
//             }
//             break;
//         case 8:
//             cout<< "El mayor es "<<abb->mayor()<<endl;
//             break;
//         case 9:
//             cout<< "El menor es "<<abb->menor()<<endl;
//             break;
//         case 10:
//             abb->mostrarNivel();
//             break;
//         case 11:
//         //eliminar al azar
//             break;
//       /*  case 12:
//         //insertar libro
//         archEntrada.open("soledad.txt");
//             while (!archEntrada.eof() && archEntrada >> palabra)
//             {
//         //        abb->insertar(palabra);
//             }
//             archEntrada.close();
//             break;
            
//         */
//         case 13:
//             break;
//         default:
//             break;
//         }
        
//     } while (op != 13);
// }

int main(){

 //   mostrarMenu();
   ABB_Array<string>* abb = new ABB_Array<string>();//n*2 izq ; (n*2)+1 der 
   //Dupla <string> *  raiz; 

    abb->insertar("d",abb->getRaiz());
    abb->insertar("b",abb->getRaiz());
    abb->insertar("f",abb->getRaiz());
    abb->insertar("a",abb->getRaiz());
    abb->insertar("c",abb->getRaiz());
    abb->insertar("e",abb->getRaiz());
    abb->insertar("g",abb->getRaiz());
    
    cout<<"IN ORDER"<<endl; 
    abb->mostrarInOrder(abb->getRaiz());
    cout<<endl; 
    cout<<"PRE ORDER"<<endl;
    abb->mostrarPreOrder(abb->getRaiz()); 
    cout<<endl;
    cout<<"POST ORDER"<<endl;
    abb->mostrarPostOrder(abb->getRaiz()); 
    cout<<endl;
    cout<<"El arbol tiene "<<abb->contarNodos(abb->getRaiz())<<" nodos"<<endl;
    cout<<"Altura: "<<abb->altura(abb->getRaiz())<<endl;

    string v; 
    cout << "Ingresa un valor para buscar" << endl;
            cin>>v; 
            if(abb->buscar(v,abb->getRaiz())){
                cout<< "Elemento encontrado"<<endl;
            } else {
                cout<< "Elemento no encontrado"<<endl;
            }
    


}   