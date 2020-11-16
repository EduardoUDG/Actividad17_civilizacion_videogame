
#include "videogame.h"
#include <fstream>
#include <algorithm>

VideoGame::VideoGame()
{

}

VideoGame::VideoGame(const string &nombreGame){
    this->nombreGame = nombreGame;
}

void VideoGame::setNombreGame(const string &v){
    nombreGame = v;
}

string VideoGame::getNombreGame(){
    return nombreGame;
}


/* ------------------------------------------------------ */    
void VideoGame::agregarPersonaje(const Civilizacion &p)
{   
    _civilizacion.push_back(p);
}

void VideoGame::mostrar()
{

    cout << left;
    cout << setw(20) << "Nombre";
    cout << setw(20) << "Ubicacion en X";
    cout << setw(20) << "Ubicacion en Y";
    cout << setw(15) << "Puntuacion";
    cout << endl;
    for (int i=0;i<80;i++){ cout << "-"; }
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
        archivo << setw(20) << "Nombre";
        archivo << setw(20) << "Ubicacion en X";
        archivo << setw(20) << "Ubicacion en Y";
        archivo << setw(15) << "Puntuacion";
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
            archivo << p.getNombre()<< endl;
            archivo << p.getUbicacionX()<< endl;
            archivo << p.getUbicacionY()<< endl;
            archivo << p.getPuntuacion()<< endl;
        }
    }
    archivo.close();
}

void VideoGame::recuperar(){
    ifstream archivo("_civilizacion.txt");
    if (archivo.is_open()){
        string temp;
        float ubicacionX;
        float ubicacionY;
        float puntuacion;
        Civilizacion p;

        while (true){
            getline(archivo, temp); // Lee nombre
            if(archivo.eof()){ break;}
            p.setNombre(temp);

            getline(archivo, temp); // Lee UbicacionX
            ubicacionX = stof(temp);       // string to float
            p.setUbicacionX(ubicacionX);
            
            getline(archivo, temp); // Lee UbicacionY
            ubicacionY = stof(temp);       // string to float
            p.setUbicacionY(ubicacionY);
            
            getline(archivo, temp); // Lee Puntuacion
            puntuacion = stoi(temp);       // string to float
            p.setPuntuacion(puntuacion);

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
size_t VideoGame::total(){
    return _civilizacion.size();
}

void VideoGame::inicializar(const Civilizacion &c, size_t n){
 _civilizacion = vector<Civilizacion>(n, c);
}

void VideoGame::eliminar(size_t pos){
    _civilizacion.erase(_civilizacion.begin()+pos);
}

void VideoGame::primera(){
    if (_civilizacion.empty()){
        cout << "Vector esta vacio" << endl;
    }
    else {
        cout << _civilizacion.front() << endl;
    }
}

void VideoGame::ultimo(){
    if (_civilizacion.empty()){
        cout << "Vector esta vacio" << endl;
    }
    else {
        cout << _civilizacion.back() << endl;
    }
}

/* ----------------------------------------------------- */
void VideoGame::ordenarNombre(){
    sort(_civilizacion.begin(), _civilizacion.end(),
    [](Civilizacion c1, Civilizacion c2){return c1.getNombre() < c2.getNombre();});
}
void VideoGame::ordenarUbicacionX(){
    sort(_civilizacion.begin(), _civilizacion.end(),
    [](Civilizacion c1, Civilizacion c2){return c1.getUbicacionX() < c2.getUbicacionX();});
}
void VideoGame::ordenarUbicacionY(){
    sort(_civilizacion.begin(), _civilizacion.end(),
    [](Civilizacion c1, Civilizacion c2){return c1.getUbicacionY() < c2.getUbicacionY();});
}
void VideoGame::ordenarPuntuacion(){
    sort(_civilizacion.begin(), _civilizacion.end(),
    [](Civilizacion c1, Civilizacion c2){return c1.getPuntuacion() < c2.getPuntuacion();});
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