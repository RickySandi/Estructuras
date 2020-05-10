#include <iostream>
#include "Monticulo.h"
#include <fstream>

using namespace std;

void mostrarMenu() 
{
    Monticulo<int> arbol;

    int op;
    int v;
    int vec[10001];
	int vec1[10001];
   
    do {
        cout << "-----MENU-----" << endl;
        cout << "1.Insertar" << endl;
        cout << "2.Eliminar raiz" << endl;
        cout << "3.Recorrer IN Order" << endl;
        cout << "4.Contar nodos" << endl;
        cout << "5.Calcular altura" << endl;
        cout << "6.Defensa" << endl;
        cout << "7.Salir" << endl;

        cout << endl;
        cout << "Ingresa una opcion" << endl;
        cin >> op;
        switch (op)
        {
        case 1:
            cout << "Ingresa un valor para insertar" << endl;
            cin >> v;
            arbol.insertar(v);
            break;
        case 2:
            cout << "Eliminando raiz" << endl;
            arbol.eliminar();
            cout << "Raiz eliminada" << endl;
            break;
        case 3:
            cout << "Mostrando Arbol IN Order" << endl;
            arbol.mostrarInOrder();
            cout<<endl;
            break;
        case 4:
            cout<<"Nodos: "<<arbol.contarNodos()<<endl; 
            break;
        case 5:
            cout<<"Altura: "<<arbol.altura()<<endl; 
            break;
        case 6:
            arbol.defensa(vec,vec1); 
            break;
 
        case 7:    
            break; 

        default:
            break;
        }
        
    } while (op != 6);
}


int main()
{
  //  mostrarMenu(); 


























//   Monticulo <int> arbol; 

//   // cout<<"Antes de insertar"<<endl; 
//   arbol.insertar(85);
//   arbol.insertar(55);
//   arbol.insertar(70); 
//   arbol.insertar(33);
//   arbol.insertar(54);
//   arbol.insertar(68);
//   arbol.insertar(50); 


//  // cout<<"Despues de insertar"<<endl;
//   arbol.mostrarInOrder();
//   cout<<endl; 
//   cout<<"Nodos: "<<arbol.contarNodos()<<endl; 
//   cout<<"Altura: "<<arbol.altura()<<endl; 
//   cout<<"-----------------------------------------------"<<endl;
//   arbol.eliminar();
//   arbol.eliminar();
//   arbol.eliminar();
//   arbol.mostrarInOrder();
//   cout<<endl; 
//   cout<<"Nodos: "<<arbol.contarNodos()<<endl; 
//   cout<<"Altura: "<<arbol.altura()<<endl; 
//   //cout<<"Despues de mostrar"<<endl;

    
}
