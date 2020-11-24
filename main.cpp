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

    cin >> u;
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
    Civilizacion c;
    cin >> c; cin.ignore();


    Civilizacion *ptr = l.buscar(c);
    if (ptr == nullptr){
        cout << endl << "No encontrado" << endl;
    }
    else {
        cout  << endl << endl << "Encontrado" << endl;
        cout << *ptr << endl;
        cout << "Ingrese los nuevos datos:" << endl;
        
        cin >> c;
        cin >> c; cin.ignore();
    }
    cout << endl;
    system("pause");
}

void resumen(){
    l.mostrar();
    cout << endl;
    system("pause");
}

