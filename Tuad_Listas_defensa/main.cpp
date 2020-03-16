#pragma once
#include <iostream>
#include <fstream>
#include <time.h>
#include "Lista_8.h"
#include "Terna.h"
#include "Tuad.h"

using namespace std;

void mostrarMenu() 
{
    int op;
    string palabra;
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
            tuad->insertarTuad(palabra);
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
            archEntrada.open("soledad.txt");
            while (!archEntrada.eof() && archEntrada >> palabra)
            {
               tuad->insertarTuad(palabra);
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
     
   // mostrarMenu();

        fstream archEntrada;
        string palabra;
        archEntrada.open("soledad.txt");
        Tuad<string>* tuad = new Tuad<string>();
        Lista_8<string>* lista8 = new Lista_8<string>(); 

        while (!archEntrada.eof() && archEntrada >> palabra)
        {
            //tuad->insertarTuad(palabra);
            lista8->insertarEnSuLugar(palabra); 
        }
        archEntrada.close();

         lista8->mostrar();

    clock_t t1, t2;
	float f1, f2;
        t1 = clock();
      tuad->insertarTuad(palabra); 
			f1 = (((float)t1) / CLOCKS_PER_SEC);
			
      t2 = clock();
		 lista8->insertarEnSuLugar(palabra);
			t2 = clock() - t2;
			f2 = (((float)t2) / CLOCKS_PER_SEC);

      cout << "Insertar en la TUAD tarda  en seg " << f1 << endl;
	  cout << "Insertar en Lista 8 tarda en seg " << f2 << endl;
      

      
 }

