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
+ Eliminar
*/

void mostrarMenu() 
{
    ABB_Array<string>* abb = new ABB_Array<string>();
    int op;
    string v;
    fstream archEntrada;
    string palabra;
   
    do {
        cout << "-----MENU-----" << endl;
        cout << "1.Insertar valor" << endl;
        cout << "2.Recorrer IN Order" << endl;
        cout << "3.Recorrer PRE Order" << endl;
        cout << "4.Recorrer POST Order" << endl;
        cout << "5.Contar nodos" << endl;
        cout << "6.Calcular altura" << endl;
        cout << "7.Buscar" << endl;
        cout << "8.Encontrar mayor" << endl;
        cout << "9.Encontrar menor" << endl;
        cout << "11.Eliminar al azar" << endl;
        cout << "12.Insertar libro" << endl;
        cout << "13.Salir" << endl;
        cout << endl;
        cout << "Ingresa una opcion" << endl;
        cin >> op;
        switch (op)
        {
        case 1:
            cout << "Ingresa un valor para insertar" << endl;
            cin >> v;
           abb->insertar(v,abb->getRaiz());
            break;
        case 2:
            cout << "Mostrando Arbol IN Order" << endl;
            abb->mostrarInOrder(abb->getRaiz());
            cout<<endl;
            break;
        case 3:
            cout << "Mostrando Arbol PRE Order" << endl;
            abb->mostrarPreOrder(abb->getRaiz());
            cout<<endl;
            break;
        case 4:
            cout << "Mostrando Arbol POST Order" << endl;
            abb->mostrarPostOrder(abb->getRaiz());
            cout<<endl;
            break;
        case 5:
            cout<<"El arbol tiene "<<abb->contarNodos(abb->getRaiz())<<" nodos"<<endl;
            break;

        case 6:
            cout<<"Altura: "<<abb->altura(abb->getRaiz())<<endl;
            break;

        case 7:
            cout << "Ingresa un valor para buscar" << endl;
            cin>>v; 
            if(abb->buscar(v,abb->getRaiz())){
                cout<< "Elemento encontrado"<<endl;
            } else {
                cout<< "Elemento no encontrado"<<endl;
            }
            break;
        case 8:
            cout<<"El mayor es "<<abb->mayor(abb->getRaiz())<<endl;
            break;
        case 9:
            cout<< "El menor es "<<abb->menor(abb->getRaiz())<<endl;
            break;
        case 11:
           cout << "Ingresa un valor para eliminar" << endl;
            cin>>v; 
            abb->eliminar(v,abb->getRaiz()); 
            break;
        case 12:
            archEntrada.open("soledad.txt");
            while (!archEntrada.eof() && archEntrada >> palabra)
            {
                abb->insertar(palabra,abb->getRaiz());
            }
            archEntrada.close();
            break;
        case 13:
            break;
        default:
            break;
        }
        
    } while (op != 13);
}

int main(){

    mostrarMenu();  //n*2 izq ; (n*2)+1 der 
   
}   