#include "videogame.h"
#include <fstream>
#include <algorithm>

VideoGame::VideoGame()
{

}

void VideoGame::agregarPersonaje(const Civilizacion &p)
{   
    _civilizacion.push_back(p);
}

void VideoGame::mostrar()
{
    cout << left;
    cout << setw(20) << "Sistema Operativo";
    cout << setw(20) << "Nombre Usuario";
    cout << setw(20) << "Almacenamiento";
    cout << setw(15) << "RAM";
    cout << endl;

    for (size_t i = 0; i < _civilizacion.size(); i++){
        Civilizacion &p = _civilizacion[i];
        cout << p;
        // cout<<"Sistema Operativo: "<<p.getSo()<<endl;
        // cout<<"Nombre de Usuario: "<<p.getNomuser()<<endl;
        // cout<<"Almacenamiento: "<<p.getAlmacenamiento()<<endl;
        // cout<<"RAM: "<<p.getRam()<<endl;
        // cout<<endl;
    }
    
}

void VideoGame::respaldar_tabla(){
    ofstream archivo("_civilizacion_tabla.txt");
    if (archivo.is_open()) {

        archivo << left;
        archivo << setw(20) << "Sistema Operativo";
        archivo << setw(20) << "Nombre Usuario";
        archivo << setw(20) << "Almacenamiento";
        archivo << setw(15) << "RAM";
        archivo << endl;

        for (size_t i = 0; i < _civilizacion.size(); i++){
            Civilizacion &p = _civilizacion[i];
            archivo << p;
        }
    }
    archivo.close();
}

void VideoGame::respaldar(){
    ofstream archivo("_civilizacion.txt");
    if (archivo.is_open()) {
        for (size_t i = 0; i < _civilizacion.size(); i++){
            Civilizacion &p = _civilizacion[i];
            archivo << p.getSo()<< endl;
            archivo << p.getNomuser()<< endl;
            archivo << p.getAlmacenamiento()<< endl;
            archivo << p.getRam()<< endl;
        }
    }
    archivo.close();
}

void VideoGame::recuperar(){
    ifstream archivo("_civilizacion.txt");
    if (archivo.is_open()){
        string temp;
        int ram;
        Civilizacion p;

        while (true){
            getline(archivo, temp); //sistema operativo
            if(archivo.eof()){ break;}
            p.setSo(temp);

            getline(archivo, temp); // nombre usuario
            p.setNomuser(temp);
            
            getline(archivo, temp); // Almacenamiento
            p.setAlmacenamiento(temp);
            
            getline(archivo, temp); // memoria RAM
            ram = stoi(temp);       // string to int
            p.setRam(ram);

            agregarPersonaje(p);
        }
        
    }
    archivo.close();
}

void VideoGame::insertar(const Civilizacion &c, size_t pos){
    _civilizacion.insert(_civilizacion. begin()+pos, c);
}

size_t VideoGame::size(){
    return _civilizacion.size();
}

void VideoGame::inicializar(const Civilizacion &c, size_t n){
 _civilizacion = vector<Civilizacion>(n, c);
}

void VideoGame::eliminar(size_t pos){
    _civilizacion.erase(_civilizacion.begin()+pos);
}

void VideoGame::ordenar(){
    sort(_civilizacion.begin(), _civilizacion.end());
}

Civilizacion* VideoGame::buscar(const Civilizacion &c){
    // vector<Computadora>::iterator
    auto it = find(_civilizacion.begin(), _civilizacion.end(), c);

    if (it == _civilizacion.end()){
        return nullptr;
    }
    else {
        return &(*it);
    }
    
}