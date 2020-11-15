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
    int ubicacionX;
    int ubicacionY;
    float puntuacion;
public:
    Civilizacion();
    Civilizacion(const string &nombre, 
              float &ubicacionX,
              float &ubicacionY,
              int puntuacion);
              
    void setSo(const string &v);
    string getSo();
    void setNomuser(const string &v);
    string getNomuser();
    void setAlmacenamiento(const string &fuerza);
    string getAlmacenamiento();
    void setRam(int v);
    int getRam();

    /* Primera carga de operador */
    friend ostream& operator<<(ostream &out, const Civilizacion &c)
    {
        out << left;
        out << setw(20) << c.so;
        out << setw(20) << c.nomuser;
        out << setw(20) << c.almacenamiento;
        out << setw(15) << c.ram;
        out << endl;
        return out;
    }

    /* Segunda carga de extraccion */
    friend istream& operator>>(istream &in, Civilizacion &c)
    {
        // string temp;
        // float fuerza;
        // int salud; 

        cout << "Sistema Operativo: ";
        getline(cin, c.so);
        
        cout << "Nombre usuario: ";
        getline(cin, c.nomuser);
        
        cout << "Almacenamiento: ";
        getline(cin, c.almacenamiento);
        
        cout << "RAM: ";
        cin >> c.ram;



        return in;
    } 

    bool operator==(const Civilizacion& c){
        return nomuser == c.nomuser;
    }
    
    bool operator==(const Civilizacion& c) const{
        return nomuser == c.nomuser;
    }

    bool operator<(const Civilizacion& c){ 
        return nomuser < c.nomuser;
    }

    bool operator<(const Civilizacion& c) const{ 
        return nomuser < c.nomuser;
    }
};

#endif