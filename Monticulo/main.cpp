#include <iostream>
#include "Monticulo.h"
#include <fstream>

using namespace std;

// void mostrarMenu() 
// {
//     Monticulo<string> arbol;
//     fstream archEntrada;
//     string palabra; 
    

//     bool continuar = true;
//     bool res; 

//     int f1 = 0;
//     int f2 =0;
//     int f3 = 0; 

//     int op;
//     string v;
   
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
//         cout<<  "10. Insertar libro"<<endl;
//         cout<<"11. Nodos Factor"<<endl; 
//         cout << "14 .Salir" << endl;

//         cout << endl;
//         cout << "Ingresa una opcion" << endl;
//         cin >> op;
//         switch (op)
//         {
//         case 1:
//             cout << "Ingresa un valor para insertar" << endl;
//             cin >> v;
//             arbol.insertar(v,arbol.getRaiz(),continuar);
//             break;
//         case 2:
//             cout << "Mostrando Arbol IN Order" << endl;
//             arbol.mostrarInOrder(arbol.getRaiz());
//             cout<<endl;
//             break;
//         case 3:
//             cout << "Mostrando Arbol PRE Order" << endl;
//             arbol.mostrarPreOrder(arbol.getRaiz());
//             cout<<endl;
//             break;
//         case 4:
//             cout << "Mostrando Arbol POST Order" << endl;
//             arbol.mostrarPostOrder(arbol.getRaiz());
//             cout<<endl;
//             break;
//         case 5:
//             cout<<"El arbol tiene "<<arbol.contarNodos(arbol.getRaiz())<<" nodos"<<endl;
//             break;

//         case 6:
//             cout<<"Altura: "<<arbol.altura(arbol.getRaiz())<<endl; 
//             break;

//         case 7:
//             cout << "Ingresa un valor para buscar" << endl;
//             cin>>v; 
//             if(arbol.buscar(v, arbol.getRaiz())){
//                 cout<< "Elemento encontrado"<<endl;
//             } else {
//                 cout<< "Elemento no encontrado"<<endl;
//             }
//             break;
//         case 8:
//             cout<< "El mayor es "<<arbol.mayor(arbol.getRaiz())<<endl;
//             break;
//         case 9:
//             cout<< "El menor es "<<arbol.menor(arbol.getRaiz())<<endl;
//             break;
//         case 10:
//              archEntrada.open("soledad.txt");
//             while (!archEntrada.eof() && archEntrada >> palabra)
//             {
//                 arbol.insertar(palabra,arbol.getRaiz(),continuar);
                
//             }
//             archEntrada.close();
//             break;
//          case 11:  
//              arbol.nodosFactor(arbol.getRaiz(),f1,f2,f3);  
//              cout<<"Factor 0 "<<f1<<endl;
//              cout<<"Factor 1 "<<f2<<endl;
//              cout<<"Factor -1 "<<f3<<endl; 
//             break;
 
//         case 14:    
//             break; 

//         default:
//             break;
//         }
        
//     } while (op != 11);
// }


int main()
{
   // mostrarMenu(); 

  Monticulo <int> arbol; 

  //cout<<"Antes de insertar"<<endl; 
  arbol.insertar(85);
  arbol.insertar(55);
  arbol.insertar(70); 
  arbol.insertar(33);
  arbol.insertar(54);
  arbol.insertar(68);
//arbol.insertar(50); 

 // cout<<"Despues de insertar"<<endl;
  arbol.mostrarInOrder();
  cout<<endl; 
  cout<<"Nodos: "<<arbol.contarNodos()<<endl; 
  cout<<"Altura: "<<arbol.altura()<<endl; 
  cout<<"-----------------------------------------------"<<endl;
  arbol.eliminar();
  arbol.eliminar();
  arbol.eliminar();
  arbol.mostrarInOrder();
  cout<<endl; 
  cout<<"Nodos: "<<arbol.contarNodos()<<endl; 
  cout<<"Altura: "<<arbol.altura()<<endl; 
  //cout<<"Despues de mostrar"<<endl;

    
}
