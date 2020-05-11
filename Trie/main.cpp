#include "Trie.h"
#include <iostream>
#include "Nodo.h"

using namespace std;

void mostrarMenu(){
     Trie<char>* trie = new Trie<char>;
    int op; 
    string res;
    fstream archEntrada; 
    do {
        cout<<"------MENU------"<<endl; 
        cout << "1.Insertar palabra" << endl;
        cout << "2.Buscar palabra" << endl;
        cout << "3.Leer archivo" << endl;
        cout << "4.Mostrar" << endl;
        cout << "5.Mostrar palabras que contengan" << endl;
        cout << "6.Salir" << endl;
        cout<<endl; 
        cout << "Ingresa una opcion" << endl;
        cin >> op;
        switch (op)
        {
        case 1:
            cout << "Ingresa una palabra" << endl;
            cin >> res;
            trie->insertar(res);
            break;
        case 2:
            cout << "Ingresa una palabra"<< endl;
            cin >> res;
            if (trie->buscarPalabra(res)) {
                cout <<"Existe"<< endl;
            }
            else {
                cout << "No existe" << endl;
            }
            break;
        
        case 3:
            archEntrada.open("Palabras.txt");
            while (!archEntrada.eof() && archEntrada >> res)
            {
                trie->insertar(res);
            }
            archEntrada.close();
            break;
        case 4:
            trie->mostrarPalabras();
            break;
        case 5:
            cout << "Ingresa una palabra" << endl;
            cin >> res;
            trie->mostrarPalabrasContiene(res);
            break;
        default:
            break;
        }
        } while (op != 6);
}

int main() {
   
        mostrarMenu(); 


}

