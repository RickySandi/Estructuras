#pragma once
#include <iostream>
#include <fstream>
#include "Lista_8.h"
#include "Terna.h"
#include "Hash.h"

using namespace std;

void mostrarMenu() 
{
    fstream archEntrada;
    string palabra;
    Hash<string>* hash = new Hash<string>();
    int op;
    string v;
    string i;
    do {
        cout << "-----MENU-----" << endl;
        cout << "1.Insertar palabra" << endl;
        cout << "2.Eliminar palabra" << endl;
        cout << "3.Buscar palabra" << endl;
        cout << "4.Insertar el libro" << endl;
        cout << "5.Contar palabras diferentes" << endl;
        cout << "6.Contar colisiones" << endl;
        cout << "7.Salir" << endl;
        cout << endl;
        cout << "Ingresa una opcion" << endl;
        cin >> op;
        switch (op)
        {
        case 1:
            cout << "Ingresa una palabra" << endl;
            cin >> v;
            hash->insertar(v);
            break;
        case 2:
            cout << "Ingresa una palabra" << endl;
            cin >> v;
            hash->eliminar(v);
            break;
        case 3:
            cout << "Ingresa una palabra" << endl;
            cin >> v;
            hash->buscar(v);
            system("pause");
            break;
        case 4:
            archEntrada.open("soledad.txt");
            while (!archEntrada.eof() && archEntrada >> palabra)
            {
                hash->insertar(palabra);
            }
            archEntrada.close();
            break; 
        case 5:
            int diferentes;  
            diferentes = hash->contarDiferentes();
            cout<< "Hay "<<diferentes<<" diferentes palabras"<<endl; 
            break; 

        case 6:
             hash->contarColisiones(); 

        case 7:
            break;
        default:
            break;
        }
        
    } while (op != 7);
}


int main()
{
    mostrarMenu(); 

    // fstream archEntrada;
    // string palabra;
    // archEntrada.open("soledad.txt");
    // Hash<string>* hash = new Hash<string>();
    // while (!archEntrada.eof() && archEntrada >> palabra)
    // {
    //     hash->insertar(palabra);
    // }
    // archEntrada.close();
    // hash->buscar("de");
    // hash->buscar("y");
    // hash->buscar("cien");

    // int diferentes;  
    // diferentes = hash->contarDiferentes();
    // cout<< "Hay "<<diferentes<<" diferentes palabras"<<endl; 

    // hash->contarColisiones(); 
    
}