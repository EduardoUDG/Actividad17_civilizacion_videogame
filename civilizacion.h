#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include<iostream>
#include<conio.h>
#include<iomanip>
#include<string>

using namespace std;

class Civilizacion{
private:
    string nombre;
    float ubicacionX;
    float ubicacionY;
    float puntuacion;
public:
    Civilizacion();
    Civilizacion(const string &nombre, 
              float ubicacionX,
              float ubicacionY,
              float puntuacion);

    void setNombre(const string &v);
    float getNombre();
    void setUbicacionX(float v);
    float getUbicacionX(float v);
    void setUbicacionY(float v);
    float getUbicacionY(float v);
    void setPuntuacion(float v);
    float getPuntuacion();

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