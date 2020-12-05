
#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include "civilizacion.h"
#include <vector>

class VideoGame
{ 
    string nombreGame;
    vector<Civilizacion> _civilizacion;

public:
    VideoGame();
    void setNombreGame(const string &v);
    string getNombreGame();

    void agregarPersonaje(const Civilizacion &p);
    void mostrar();
    void respaldar_tabla();
    void respaldar();
    void recuperar();

    void insertar(const Civilizacion &c, size_t pos);
    size_t size();
    size_t total();
    void inicializar(const Civilizacion &c, size_t n);
    void eliminar(size_t pos);
    void primera();
    void ultimo();
    void ordenarNombre();
    void ordenarUbicacionX();
    void ordenarUbicacionY();
    void ordenarPuntuacion();



    Civilizacion* buscar(const Civilizacion &c);
    Civilizacion* modificar(Civilizacion &c);


    friend VideoGame& operator<<(VideoGame &v, const Civilizacion &p)
    {
        v.agregarPersonaje(p);

        return v;
    }

  /*   friend ostream& operator<<(ostream &out, const VideoGame &c)
    {
        out << left;
        out << setw(20) << c.nombreGame;
        out << endl;
        return out;
    }
    friend istream& operator>>(istream &in, VideoGame &v){
        cout << "Nombre de usuario: ";
        getline(cin, v.nombreGame);
        
        return in;
    }   */

};


#endif