#include "dtPropiedad.h"

//CONSTRUCTOR:
dtPropiedad::dtPropiedad(string codigo, direccion* dir, bool enVenta, bool enAlquiler){
    this -> codigo = codigo;
    this -> dir = dir;
    this -> enVenta = enVenta;
    this -> enAlquiler = enAlquiler;
}

// DESTRUCTOR:
dtPropiedad::~dtPropiedad(){
    cout << "destruct de dtPropiedad" << endl;
}

// GETTERS:
string dtPropiedad::getCodigo(){
    return this -> codigo;
}

direccion* dtPropiedad::getDir(){
    return this -> dir;
}

bool dtPropiedad::getEnVenta(){
    return this -> enVenta;
}

bool dtPropiedad::getEnAlquiler(){
    return this -> enAlquiler;
}