#include "dtInmobiliaria.h"

// CONSTRUCTOR:
dtInmobiliaria::dtInmobiliaria(string nombre, string correo, direccion *dir){
    this -> nombre = nombre;
    this -> correo = correo;
    this -> dir = dir;
}

// DESTRUCTOR:
dtInmobiliaria::~dtInmobiliaria(){
    cout << "destruct de dtInmobiliaria";
}

// GETTERS:
string dtInmobiliaria::getNombre(){
    return this -> nombre;
}

string dtInmobiliaria::getCorreo(){
    return this -> correo;
}

direccion *dtInmobiliaria::getDireccion(){
    //return this -> dir;
}