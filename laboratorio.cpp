#include "laboratorio.h"
#include <fstream>
#include <algorithm>

Laboratorio::Laboratorio()
{

}

void Laboratorio::agregarPersonaje(const Computadora &p)
{   
    computadoras.push_back(p);
}

void Laboratorio::mostrar()
{
    cout << left;
    cout << setw(20) << "Sistema Operativo";
    cout << setw(20) << "Nombre Usuario";
    cout << setw(20) << "Almacenamiento";
    cout << setw(15) << "RAM";
    cout << endl;

    for (size_t i = 0; i < computadoras.size(); i++){
        Computadora &p = computadoras[i];
        cout << p;
        // cout<<"Sistema Operativo: "<<p.getSo()<<endl;
        // cout<<"Nombre de Usuario: "<<p.getNomuser()<<endl;
        // cout<<"Almacenamiento: "<<p.getAlmacenamiento()<<endl;
        // cout<<"RAM: "<<p.getRam()<<endl;
        // cout<<endl;
    }
    
}

void Laboratorio::respaldar_tabla(){
    ofstream archivo("computadoras_tabla.txt");
    if (archivo.is_open()) {

        archivo << left;
        archivo << setw(20) << "Sistema Operativo";
        archivo << setw(20) << "Nombre Usuario";
        archivo << setw(20) << "Almacenamiento";
        archivo << setw(15) << "RAM";
        archivo << endl;

        for (size_t i = 0; i < computadoras.size(); i++){
            Computadora &p = computadoras[i];
            archivo << p;
        }
    }
    archivo.close();
}

void Laboratorio::respaldar(){
    ofstream archivo("computadoras.txt");
    if (archivo.is_open()) {
        for (size_t i = 0; i < computadoras.size(); i++){
            Computadora &p = computadoras[i];
            archivo << p.getSo()<< endl;
            archivo << p.getNomuser()<< endl;
            archivo << p.getAlmacenamiento()<< endl;
            archivo << p.getRam()<< endl;
        }
    }
    archivo.close();
}

void Laboratorio::recuperar(){
    ifstream archivo("computadoras.txt");
    if (archivo.is_open()){
        string temp;
        int ram;
        Computadora p;

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

void Laboratorio::insertar(const Computadora &c, size_t pos){
    computadoras.insert(computadoras. begin()+pos, c);
}

size_t Laboratorio::size(){
    return computadoras.size();
}

void Laboratorio::inicializar(const Computadora &c, size_t n){
 computadoras = vector<Computadora>(n, c);
}

void Laboratorio::eliminar(size_t pos){
    computadoras.erase(computadoras.begin()+pos);
}

void Laboratorio::ordenar(){
    sort(computadoras.begin(), computadoras.end());
}

Computadora* Laboratorio::buscar(const Computadora &c){
    // vector<Computadora>::iterator
    auto it = find(computadoras.begin(), computadoras.end(), c);

    if (it == computadoras.end()){
        return nullptr;
    }
    else {
        return &(*it);
    }
    
}