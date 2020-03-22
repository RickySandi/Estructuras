#pragma once
#include <iostream>
#include "Dupla.h"
#include "ABB_Array.h"
using namespace std;

void mostrarMenu() 
{
    ABB_Array<int>* abb = new ABB_Array<int>();
    int op;
    int v;
   
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
        cout << "10.Salir" << endl;
        cout << endl;
        cout << "Ingresa una opcion" << endl;
        cin >> op;
        switch (op)
        {
        case 1:
            cout << "Ingresa un valor para insertar" << endl;
            cin >> v;
            abb->insertar(v);
            break;
        case 2:
            cout << "Mostrando Arbol IN Order" << endl;
            abb->mostrarInOrder();
            cout<<endl;
            break;
        case 3:
            cout << "Mostrando Arbol PRE Order" << endl;
            abb->mostrarPreOrder();
            cout<<endl;
            break;
        case 4:
            cout << "Mostrando Arbol POST Order" << endl;
            abb->mostrarPostOrder();
            cout<<endl;
            break;
        case 5:
            cout<<"El arbol tiene "<<abb->contarNodos()<<" nodos"<<endl;
            break;

        case 6:
            cout<<"Altura: "<<abb->altura()<<endl; 
            break;

        case 7:
            cout << "Ingresa un valor para buscar" << endl;
            cin>>v; 
            if(abb->buscar(v)){
                cout<< "Elemento encontrado"<<endl;
            } else {
                cout<< "Elemento no encontrado"<<endl;
            }
            break;
        case 8:
            cout<< "El mayor es "<<abb->mayor()<<endl;
            break;
        case 9:
            cout<< "El menor es "<<abb->menor()<<endl;
            break;
        case 10:
            break;
        default:
            break;
        }
        
    } while (op != 10);
}

int main(){

    mostrarMenu();

}