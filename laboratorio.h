#ifndef LABORATORIO_H
#define LABORATORIO_H

#include "computadora.h"
#include <vector>

class Laboratorio
{
    vector<Computadora> computadoras;

public:
    Laboratorio();
    void agregarPersonaje(const Computadora &p);
    void mostrar();
    void respaldar_tabla();
    void respaldar();
    void recuperar();

    void insertar(const Computadora &c, size_t pos);
    size_t size();
    void inicializar(const Computadora &c, size_t n);
    void eliminar(size_t pos);
    void ordenar();
    Computadora* buscar(const Computadora &c);

    friend Laboratorio& operator<<(Laboratorio &v, const Computadora &p)
    {
        v.agregarPersonaje(p);

        return v;
    }
};


#endif