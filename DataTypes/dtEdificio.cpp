#include "dtEdificio.h"

// CONSTRUCTOR:
dtEdificio::dtEdificio(string nombre, int cantPisos, int gastosComunes){
    this -> nombre = nombre;
    this -> cantPisos = cantPisos;
    this -> gastosComunes = gastosComunes;
}

// DESTRUCTOR:
dtEdificio::~dtEdificio(){
    cout << "destruct de dtEdificio" << endl;
}

// GETTERS:
int dtEdificio::getCantPisos(){
    return this -> cantPisos;
}

int dtEdificio::getGastosComunes(){
    return this -> gastosComunes;
}

string dtEdificio::getNombre(){
    return this -> nombre;
}