#include <iostream>
#include "Arbol_Rojo_Negro.h"
#include <fstream>

using namespace std;

void mostrarMenu() 
{
    Arbol_Rojo_Negro<string> arbol;
    fstream archEntrada;
    string palabra; 
    

    bool continuar = true;
    bool paridad = true;
    bool lado = true;

    bool res; 

   

    int op;
    string v;
   
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
        cout<<  "10. Insertar libro"<<endl;
        cout<<  "11. Verificar hijo negro"<<endl; 
        cout << "12.Salir" << endl;
        cout << endl;
        cout << "Ingresa una opcion" << endl;
        cin >> op;
        switch (op)
        {
        case 1:
            cout << "Ingresa un valor para insertar" << endl;
            cin >> v;
            arbol.insertar(v,arbol.getRaiz(),&continuar, &paridad, &lado);
            arbol.getRaiz()->setColor('N'); 
            break;
        case 2:
            cout << "Mostrando Arbol IN Order" << endl;
            arbol.mostrarInOrder(arbol.getRaiz());
            cout<<endl;
            break;
        case 3:
            cout << "Mostrando Arbol PRE Order" << endl;
            arbol.mostrarPreOrder(arbol.getRaiz());
            cout<<endl;
            break;
        case 4:
            cout << "Mostrando Arbol POST Order" << endl;
            arbol.mostrarPostOrder(arbol.getRaiz());
            cout<<endl;
            break;
        case 5:
            cout<<"El arbol tiene "<<arbol.contarNodos(arbol.getRaiz())<<" nodos"<<endl;
            break;

        case 6:
            cout<<"Altura: "<<arbol.altura(arbol.getRaiz())<<endl; 
            break;

        case 7:
            cout << "Ingresa un valor para buscar" << endl;
            cin>>v; 
            if(arbol.buscar(v, arbol.getRaiz())){
                cout<< "Elemento encontrado"<<endl;
            } else {
                cout<< "Elemento no encontrado"<<endl;
            }
            break;
        case 8:
            cout<< "El mayor es "<<arbol.mayor(arbol.getRaiz())<<endl;
            break;
        case 9:
            cout<< "El menor es "<<arbol.menor(arbol.getRaiz())<<endl;
            break;
        case 10:
             archEntrada.open("soledad.txt");
            while (!archEntrada.eof() && archEntrada >> palabra)
            {
                arbol.insertar(palabra,arbol.getRaiz(),&continuar, &paridad, &lado);
                arbol.getRaiz()->setColor('N'); 
            }
            archEntrada.close();
            break;
        case 11:
       
        res = arbol.hijoNegro(arbol.getRaiz()); 
        if(res){cout<<"Si"<<endl;}
        else {cout<<"No"<<endl;}
            break;
        case 12:
            break;
        default:
            break;
        }
        
    } while (op != 12);
}


int main()
{
    mostrarMenu(); 

    // bool continuar = true;
    // bool paridad = true;
    // bool lado = true;
    // Arbol_Rojo_Negro<int> arbol;
    // arbol.insertar(15, arbol.getRaiz(), &continuar, &paridad, &lado);
    // arbol.mostrarInOrder();
    // cout << endl;
    // arbol.insertar(8, arbol.getRaiz(), &continuar, &paridad, &lado);
    // arbol.mostrarInOrder();
    // cout << endl;
    // arbol.insertar(33, arbol.getRaiz(), &continuar, &paridad, &lado);
    // arbol.mostrarInOrder();
    // cout << endl;
    // arbol.insertar(12, arbol.getRaiz(), &continuar, &paridad, &lado);
    // arbol.mostrarInOrder();
    // cout << endl;
    // arbol.insertar(9, arbol.getRaiz(), &continuar, &paridad, &lado);
    // arbol.mostrarInOrder();
    // cout << endl;
    // arbol.insertar(5, arbol.getRaiz(), &continuar, &paridad, &lado);
    // arbol.mostrarInOrder();
    // cout << endl;

    
}