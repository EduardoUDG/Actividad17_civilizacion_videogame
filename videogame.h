#ifndef LABORATORIO_H
#define LABORATORIO_H

#include "civilizacion.h"
#include <vector>

class Laboratorio
{
    vector<Civilizacion> computadoras;

public:
    Laboratorio();
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

    friend Laboratorio& operator<<(Laboratorio &v, const Civilizacion &p)
    {
        v.agregarPersonaje(p);

        return v;
    }
};


#endif