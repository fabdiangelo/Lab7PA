#include "edificio.h"

// CONSTRUCTOR:
edificio::edificio(string nombre,int cantPisos,int gastosComunes){
    this -> nombre = nombre;
    this -> cantPisos = cantPisos;
    this -> gastosComunes = gastosComunes;
    this -> apartamentos = new OrderedDictionary();
}

// DESTRUCTOR:
edificio::~edificio(){ 
    cout << "destruct de edificio" << endl;   
}

// GETTERS:
string edificio::getNombre(){
    return this -> nombre;
}

int edificio::getCantPisos(){
    return this -> cantPisos;
}

int edificio::getGastosComunes(){
    return this -> gastosComunes;
}

// SETTERS:
void edificio::setNombre(string nombre){
    this -> nombre = nombre;
}    

void edificio::setCantPisos(int cantPisos){
    this -> cantPisos = cantPisos;
}

void edificio::setGastosComunes(int gastos){
    this -> gastosComunes = gastos;
}

// FUNCIONALIDAD:
void edificio::agreagrPropiedad(propiedad* prop){
    string codigo = prop -> getCodigo();
    IKey *k = new String(codigo.c_str());
    this -> apartamentos -> add(k, prop);
}

void edificio::desvincularProp(string codigo){
    IKey *k = new String(codigo.c_str());
    if(this -> apartamentos -> member(k)){
        this -> apartamentos -> remove(k);
        cout << "La propiedad con codigo " << codigo << " se desvinculo del edificio " << this -> getNombre() << endl;
    }else{
        cout << "La propiedad con codigo " << codigo << " no se encontraba vinculada con el edificio " << this -> getNombre() << endl;
    }
}

// SOBRECARGA:
ostream& operator<<(ostream& os, edificio* ed){
    os << "  " << ed -> getNombre() << ") Cant pisos: " << ed -> getCantPisos() << " | Gastos comunes: " << ed -> getGastosComunes() << endl;
    return os;
}