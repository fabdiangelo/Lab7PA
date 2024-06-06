#include "dtZona.h"

// CONSTRUCTOR:
dtZona::dtZona(string nombre, string codigo){
    this -> nombre = nombre;
    this -> codigo = codigo;
}

// DESTRUCTOR:
dtZona::~dtZona(){
    cout << "destruct de dtZona"
}

// GETTERS:
string dtZona::getNombre(){
    return this -> nombre;
}

string dtZona::getCodigo(){
    return this -> codigo;
}