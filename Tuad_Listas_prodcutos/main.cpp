#pragma once
#include <iostream>
#include <fstream>
#include "Lista_8.h"
#include "Terna.h"
#include "Tuad.h"

using namespace std;

void mostrarMenu() 
{
    int op;
    string palabra;
    int cantidad; 
    fstream archEntrada;
    Tuad<string>* tuad = new Tuad<string>();
    do {
        cout << "-----MENU-----" << endl;
        cout << "1.Insertar palabra en su lugar" << endl;
        cout << "2.Mostrar palabras ordenadas por tamano" << endl;
        cout << "3.Buscar palabra" << endl;
        cout << "4.Insertar texto" << endl;
        cout << "5.Salir" << endl;
      
        cout << endl;
        cout << "Ingresa una opcion" << endl;
        cin >> op;
        switch (op)
        {
        case 1:
            cout << "Ingresa una palabra" << endl;
            cin >> palabra;
            cout << "Ingresa una cantidad" << endl;
            cin >> cantidad;
            tuad->insertarTuad(palabra,cantidad);
            break;
        case 2:
            tuad->mostrar();
            break;
        case 3:
            cout << "Ingresa una palabra" << endl;
            cin >> palabra;
            tuad->buscar(palabra);
            break;
        case 4:
            archEntrada.open("pedido.txt");
            while (!archEntrada.eof() && archEntrada >> palabra >> cantidad)
            {
               tuad->insertarTuad(palabra,cantidad);
            }
            archEntrada.close();
            break; 
        case 5:
            break;
        default:
            break;
        
        }
        
    } while (op != 5);
}


int main(){
     
    mostrarMenu();

        // fstream archEntrada;
        // string palabra;
        // archEntrada.open("soledad.txt");
        // Tuad<string>* tuad = new Tuad<string>();
        // while (!archEntrada.eof() && archEntrada >> palabra)
        // {
        //     tuad->insertarTuad(palabra);
        // }
        // archEntrada.close();
        // tuad->mostrar();
        // tuad->buscar("despues");
        // tuad->buscar("Bolivia");
        // //tuad->buscar("cien");
 }

