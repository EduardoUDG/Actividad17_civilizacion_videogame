#include "civilizacion.h"

Civilizacion::Civilizacion()
{

}

Civilizacion::Civilizacion(const string &so, const string &nomuser, const string &almacenamiento, int ram)
{
    this->so = so;
    this->nomuser = nomuser;
    this->almacenamiento = almacenamiento;
    this->ram = ram;
}
void Civilizacion::setSo(const string &v){
    so = v;
}
string Civilizacion::getSo(){
    return so;
}
void Civilizacion::setNomuser(const string &v){
    nomuser = v;
}
string Civilizacion::getNomuser(){
    return nomuser;
}
void Civilizacion::setAlmacenamiento(const string &v){
    almacenamiento = v;
}
string Civilizacion::getAlmacenamiento(){
    return almacenamiento;
}
void Civilizacion::setRam(int v){
    ram = v;
}
int Civilizacion::getRam(){
    return ram;
}