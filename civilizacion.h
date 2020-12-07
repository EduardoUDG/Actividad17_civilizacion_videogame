#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include<iostream>
#include<conio.h>
#include<iomanip>
#include<string>
#include<list>


#include "aldeano.h"
using namespace std;

class Civilizacion{
private:
    // Civilizacion
    string nombre;
    float ubicacionX;
    float ubicacionY;
    float puntuacion;

    // Aldeano
    string nombreList;
    list<Aldeano> aldeanos;

public:
    Civilizacion();
    Civilizacion(const string &nombre, 
              float ubicacionX,
              float ubicacionY,
              float puntuacion);

    void setNombre(const string &v);
    string getNombre();
    void setUbicacionX(float v);
    float getUbicacionX();
    void setUbicacionY(float v);
    float getUbicacionY();
    void setPuntuacion(float v);
    float getPuntuacion();

    


    // Aldeano ↓
    Civilizacion(const string &nombreList):nombreList(nombreList){}

    void setNombreList(const string &nombreList);
    string getNombreList();

    void agregarFinal(const Aldeano &j);
    void agregarInicio(const Aldeano &j);
    void print();

    // eliminar
    void eliminarNombre(const string &nombre);
    void eliminarEdad();
    void eliminarSalud(int salud);

    // ordenar
    void ordenarNombre();
    void ordenarEdad();
    void ordenarSalud();
    void mostrar();

    
    void buscarNombreAldeano(const string &nombre);
    void buscarAldeano(const string &nombre);
    Aldeano* modificarAldeano(Aldeano &c);




    // Civilizacion
    /* Primera carga de operador */
    friend ostream& operator<<(ostream &out, const Civilizacion &c)
    {
        out << left;
        out << setw(20) << c.nombre;
        out << setw(20) << c.ubicacionX;
        out << setw(20) << c.ubicacionY;
        out << setw(15) << c.puntuacion;
        out << endl;
        return out;
    }
    
    // Civilizacion
    /* Segunda carga de extraccion */
    friend istream& operator>>(istream &in, Civilizacion &c)
    {
        // string temp;
        // float fuerza;
        // int salud; 

        cout << "Nombre: ";
        getline(cin, c.nombre);
        
        cout << "Ubicacion en X: ";
        cin >> c.ubicacionX;
        
        cout << "Ubicacion en Y: ";
        cin >> c.ubicacionY;
        
        cout << "Puntuacion: ";
        cin >> c.puntuacion;

        return in;
    } 

    bool operator==(const Civilizacion& c){
        return nombre == c.nombre;
    }
    
    bool operator==(const Civilizacion& c) const{
        return nombre == c.nombre;
    }

    bool operator<(const Civilizacion& c){ 
        return nombre < c.nombre;
    }

    bool operator<(const Civilizacion& c) const{ 
        return nombre < c.nombre;
    }
};

#endif