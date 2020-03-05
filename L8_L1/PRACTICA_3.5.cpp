#include <iostream>
#include "Lista_1.h"
#include "Cuarteto.h"
#include "Lista_Listas.h"
using namespace std;

void mostrarMenu(){
    
    Lista_1* lista = new Lista_1();
    Cuarteto<string>* cuarteto = new Cuarteto<string>();
    Lista_Listas<string>* listaListas = new Lista_Listas<string>(); 

    Cuarteto<string>* docente1 = new Cuarteto<string>();
    Cuarteto<string>* docente2 = new Cuarteto<string>();

    

   int op;
   string nomEstudiante, nomDocente;
   string nom1, nom2; 
 
   do{
    cout<<"-----MENU-----"<<endl;
    cout<<"1.Insertar estudiante al final"<<endl;
    cout<<"2.Eliminar estudiante al final"<<endl;
    cout<<"3.Mostrar estudiantes"<<endl;
    cout<<"4.Buscar estudiante"<<endl;

    cout<<"5.Insertar al final de la lista"<<endl;
    cout<<"6.Eliminar al final de la lista"<<endl;
    cout<<"7.Mostrar la lista"<<endl;
    cout<<"8.Buscar estudiante recursivamente"<<endl;
    cout<<"9.Buscar un docente"<<endl;
    cout<<"10.Intercambiar estudiantes"<<endl;
    cout<<"11.Salir"<<endl;
    cout<<endl;
    cout<<"Ingresa una opcion"<<endl; 
    cin>>op; 

     
    switch (op)
    {
    
    case 1 :
        //int v; 
        cout<<"Ingresa nombre del estudiante"<<endl; 
        cin>>nomEstudiante;
        lista->insertarFinal(nomEstudiante);
        break;
    case 2 :
        // int v; 
         lista->eliminarFinal();
        break;
    case 3 :
         lista->imprimirArray();
        break;
    case 4 :
    bool res; 
        cout<<"Ingresa nombre para buscar"<<endl; 
        cin>>nomEstudiante; 
        res = lista->buscar(nomEstudiante);
        if(res){cout<<"Estudiante encontrado"<<endl;}
        else{{cout<<"Estudiante no encontrado"<<endl;}}
        break;
    case 5 :
        
        cout<<"Ingresa nombre del estudiante"<<endl; 
        cin>>nomEstudiante;
        cout<<"Ingresa nombre del docente"<<endl; 
        cin>>nomDocente;
        listaListas->insertBack(nomEstudiante,nomDocente);
        break;
    case 6 :
        listaListas->deleteBack(); 
        break;
    case 7 :
        listaListas->mostrar(); 
        break; 
    case 8: 
        //Falta 
        cout<<"Ingresa nombre del estudiante"<<endl; 
        cin>>nomEstudiante;
        listaListas->buscarEstudiante(nomEstudiante);
        //Falta
         
    case 9: 
        cout<<"Ingresa nombre del docente"<<endl; 
        cin>>nomDocente;
        listaListas->buscarDocente(nomDocente);
        break;

    case 10: 
        cout<<"Ingresa nombre del primer docente"<<endl; 
        cin>>nom1;
        cout<<"Ingresa nombre del segundo docente"<<endl; 
        cin>>nom2;

        listaListas->intercambiarEstudiantes(nom1, nom2);
        break;
    
    default:
        break;
    }
        }while (op!=11);
}

int main()
{
    mostrarMenu();
//     Lista_1* lista = new Lista_1();
//     Cuarteto<string>* cuarteto = new Cuarteto<string>();
//     Lista_Listas<string>* listaListas = new Lista_Listas<string>();
//    /* lista->insertarFinal("ana");
//     lista->insertarFinal("luna");
//     lista->insertarFinal("pepe");
//     lista->insertarFinal("pepito");
//     lista->insertarFinal("juan");
//     lista->insertarFinal("#dieter");
//     lista->imprimirArray();
//     lista->eliminarFinal();
//     lista->imprimirArray();
//     bool a = lista->buscar("#dieter");
//     cout << a << endl;
//     lista->imprimirArray();
//     cuarteto->setValue("progra");
//     cuarteto->setList(lista);

//     cout << cuarteto->getValue() << endl;
//     cuarteto->getList()->imprimirArray();*/

     
//       docente1->setValue("PROGRA");
//       docente1->setValue("PROGRA2");

//     listaListas->insertBack("ricardo", "PROGRA");
//     listaListas->insertBack("#dieterPuto", "PROGRA");
//     listaListas->insertBack("#dieterMarica", "PROGRA2");
//     listaListas->insertBack("maria", "PROGRA1");
//     listaListas->mostrar();

    
   

//     // listaListas->deleteBack();
//     // listaListas->mostrar();

//     // cout<<endl;

//     //   listaListas->deleteBack();
//     // listaListas->mostrar();

//     //  cout<<endl;

//     //   listaListas->deleteBack();
//     // listaListas->mostrar();

//     // // listaListas->deleteBack();
//     // // listaListas->mostrar();

//     // listaListas->insertBack("mariana", "BASE1");
//     // listaListas->mostrar();

//     //    listaListas->deleteBack();
//     // listaListas->mostrar();
    
//     // listaListas->buscarDocente("#dieter");
//     // listaListas->buscarDocente("PROGRA");

}
