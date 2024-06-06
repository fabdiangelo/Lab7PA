#include "dtZona.h"

// CONSTRUCTOR:
dtInmobiliaria::dtInmobiliaria(string nombre, string codigo, direccion *direccion){
    this -> nombre = nombre;
    this -> codigo = codigo;
    this -> direccion = direccion;
}

// DESTRUCTOR:
dtInmobiliaria::~dtInmobiliaria(){
    cout << "destruct de dtZona";
}

// GETTERS:
string dtInmobiliaria::getNombre(){
    return this -> nombre;
}

string dtInmobiliaria::getCodigo(){
    return this -> codigo;
}

direccion *dtInmobiliaria::getDireccion(){
    return this -> direccion;
}