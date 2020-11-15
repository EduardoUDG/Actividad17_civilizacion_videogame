#include "civilizacion.h"

Civilizacion::Civilizacion()
{

}

Civilizacion::Civilizacion(const string &nombre, float ubicacionX, float ubicacionY, float puntuacion)
{
    this->nombre = nombre;
    this->ubicacionX = ubicacionX;
    this->ubicacionY = ubicacionY;
    this->puntuacion = puntuacion;
}
void Civilizacion::setNombre(const string &v){
    nombre = v;
}
string Civilizacion::getNombre(){
    return nombre;
}
/* ------------------------------------ */

void Civilizacion::setUbicacionX(float v){
    ubicacionX = v;
}
float Civilizacion::getUbicacionX(){
    return ubicacionX;
}

/* ------------------------------------ */
void Civilizacion::setUbicacionY(float v){
    ubicacionY = v;
}
float Civilizacion::getUbicacionY(){
    return ubicacionY;
}

/* ------------------------------------ */
void Civilizacion::setPuntuacion(float v){
    puntuacion = v;
}
float Civilizacion::getPuntuacion(){
    return puntuacion;
}