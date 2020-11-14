#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include "civilizacion.h"
#include <vector>

class VideoGame
{ 
    vector<Civilizacion> _civilizacion;

public:
    VideoGame();
    void agregarPersonaje(const Civilizacion &p);
    void mostrar();
    void respaldar_tabla();
    void respaldar();
    void recuperar();

    void insertar(const Civilizacion &c, size_t pos);
    size_t size();
    void inicializar(const Civilizacion &c, size_t n);
    void eliminar(size_t pos);
    void ordenar();
    Civilizacion* buscar(const Civilizacion &c);

    friend VideoGame& operator<<(VideoGame &v, const Civilizacion &p)
    {
        v.agregarPersonaje(p);

        return v;
    }
};


#endif