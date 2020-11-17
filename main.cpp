#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<string>


#include "videogame.h"

using namespace std;

void nombreUsuario();
void agregar();
void insertar();
void crear();
void primPos();
void ultiPos();
void ordenarCivilizacion();
void eliminarCivilizacion();
void buscarCivilizacion();
void modificarCivilizacion();
void resumen();

VideoGame l;


int main(){
    string op;

    while (true){
        
        system("cls");
        cout << "1) Nombre de usuario" << endl;
        cout << "2) Agregar " << endl;
        cout << "3) Insertar " << endl;
        cout << "4) Crear" << endl;
        cout << "5) Primera" << endl;
        cout << "6) Ultima" << endl;
        cout << "7) Ordena" << endl;
        cout << "8) Elimina" << endl;
        cout << "9) Busca" << endl;
        cout << "10) Modifica" << endl;
        cout << "11) Resumen" << endl;
        cout << "12) Salir" << endl;
        cout << "Opcion:" << endl;
        getline(cin, op);



        if (op == "1"){
            nombreUsuario();
        }
        else if (op == "2"){
            agregar();
        }
        else if (op == "3"){
            insertar();
        }
        else if (op == "4"){
            crear();
        }
        else if (op == "5"){
            primPos();
        }
        else if (op == "6"){
            ultiPos();
        }
        else if (op == "7"){
            ordenarCivilizacion();
        }
        else if (op == "8"){
            eliminarCivilizacion();
        }
        else if (op == "9"){
            buscarCivilizacion();
        }
        else if (op == "10"){
            modificarCivilizacion();
        }
        else if (op == "11"){
            resumen();
        }
        else if (op == "12"){
            system("pause");
            break;
        }    
    }
    


    getch();
    return 0;
}

void nombreUsuario(){
    VideoGame u;

    u.setNombreGame("Eduardo");
    cout << endl;

}

void agregar(){
    Civilizacion c;

    cin >> c;

    l.agregarPersonaje(c);
    cin.ignore();
}

void insertar(){
    Civilizacion c;
    cin >> c;

    size_t pos;
    cout << "Posicion: " << endl;
    cin >> pos; cin.ignore();

    if (pos >= l.size()){
        cout << "Posicion no valida" << endl;
    }
    else {
        l.insertar(c,pos);
    }
}

void crear(){
    Civilizacion c;
    cin >> c;

    size_t n;
    cout << "n: " << endl;
    cin >> n; cin.ignore();
    l.inicializar(c, n);
}

void primPos(){
    l.primera();
    cout << endl;
    system("pause");
}

void ultiPos(){
    l.ultimo();
    cout << endl;
    system("pause");
}

void ordenarCivilizacion(){
    string opc;

    cout << endl;
    cout << "Selecciona la opcion a ordenar: " << endl;
    cout << "1) Nombre" << endl;
    cout << "2) Ubicacion en X" << endl;
    cout << "3) Ubicacion en Y" << endl;
    cout << "4) Puntuacion" << endl;
    getline(cin, opc);

    if (opc == "1"){
        l.ordenarNombre();
    }
    else if (opc == "2"){
        l.ordenarUbicacionX();
    }
    else if (opc == "3"){
        l.ordenarUbicacionY();
    }
    else if (opc == "4"){
        l.ordenarPuntuacion();
    }
}

void eliminarCivilizacion(){
    size_t pos;
    cout << "Posicion: " << endl;
    cin >> pos; cin.ignore();

    if (pos >= l.size()){
        cout << "Posicion no valida" << endl;
    }
    else {
        l.eliminar(pos);
    }
}

void buscarCivilizacion(){
    Civilizacion c;
    cin >> c; cin.ignore();

    Civilizacion *ptr = l.buscar(c);
    if (ptr == nullptr){
        cout << endl << "No encontrado" << endl;
    }
    else {
        cout << "Encontrado" << endl << endl;
        cout << *ptr << endl;
    }
    cout << endl;
    system("pause");
}

void modificarCivilizacion(){
    // Pendiente
}

void resumen(){
    l.mostrar();
    cout << endl;
    system("pause");
}





















































// system("cls");
//         cout << "1) Agregar personaje" << endl;
//         cout << "2) Mostrar" << endl;
//         cout << "3) Respaldar" << endl;
//         cout << "4) Recuperar" << endl;
//         cout << "5) Insertar" << endl;
//         cout << "6) Inicializar" << endl;
//         cout << "7) Eliminar" << endl;
//         cout << "8) Ordenar Nombre" << endl;
//         cout << "10) Ordenar UbicacionX" << endl;
//         cout << "11) Ordenar UbicacionY" << endl;
//         cout << "12) Ordenar Puntuacion" << endl;
//         cout << "13) Primera" << endl;
//         cout << "14) Ultimo" << endl;
//         cout << "15) Total" << endl;
//         cout << "9) Buscar" << endl;
//         cout << "0) Salir" << endl;
//         cout << "Opcion:" << endl;
//         getline(cin, op);



//         if (op == "1"){
//             Civilizacion c;

//             cin >> c;

//             l.agregarPersonaje(c);
//             cin.ignore();
//         }
//         else if (op == "2"){
//             l.mostrar();
//             cout << endl;
//             system("pause");

//         }
//         else if (op == "3"){
//             l.respaldar();
//         }
//         else if (op == "4"){
//             l.recuperar();
//         }
//         else if (op == "5"){
//             Civilizacion c;
//             cin >> c;

//             size_t pos;
//             cout << "Posicion: " << endl;
//             cin >> pos; cin.ignore();

//             if (pos >= l.size()){
//                 cout << "Posicion no valida" << endl;
//             }
//             else {
//                 l.insertar(c,pos);
//             }
            
//         }
//         else if (op == "6"){
//             Civilizacion c;
//             cin >> c;

//             size_t n;
//             cout << "n: " << endl;
//             cin >> n; cin.ignore();

//             l.inicializar(c, n);
//         }
//         else if (op == "7"){
//             size_t pos;
//             cout << "Posicion: " << endl;
//             cin >> pos; cin.ignore();

//             if (pos >= l.size()){
//                 cout << "Posicion no valida" << endl;
//             }
//             else {
//                 l.eliminar(pos);
//             }
//         }
//         else if (op == "8"){
//             l.ordenarNombre();
//         }
//         else if (op == "10"){
//             l.ordenarUbicacionX();
//         }
//         else if (op == "11"){
//             l.ordenarUbicacionY();
//         }
//         else if (op == "12"){
//             l.ordenarPuntuacion();
//         }
//         else if (op == "13"){
//             l.primera();
//             cout << endl;
//             system("pause");
//         }
//         else if (op == "14"){
//             l.ultimo();
//             cout << endl;
//             system("pause");
//         }
//         else if (op == "15"){
//             cout << "Total de civilizaciones: " << l.total();
//             cout << endl;
//             system("pause");
//         }
//         else if (op == "9"){
//             Civilizacion c;
//             cin >> c; cin.ignore();

//             Civilizacion *ptr = l.buscar(c);
//             if (ptr == nullptr){
//                 cout << "No encontrado" << endl;
//             }
//             else {
//                 cout << "Encontrado" << endl << endl;
//                 cout << *ptr << endl;
//             }
//             cout << endl;
//             system("pause");
//         }
//         else if (op == "0")
//         {
//             system("pause");
//             break;
//         }
        
//     }
