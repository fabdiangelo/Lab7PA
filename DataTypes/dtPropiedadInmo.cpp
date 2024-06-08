#include "dtPropiedadInmo.h"

// CONSTRUCTOR:
dtPropiedadInmo::dtPropiedadInmo(string codigo, int cantAmbientes, int cantDormitorios, int cantBanios, bool garage, int m2Edificados, direccion* dir, bool enVenta, bool enAlquiler, string nombreInmo, direccion *direccionInmo){
    this -> codigo = codigo;
    this -> cantAmbientes = cantAmbientes;
    this -> cantDormitorios = cantDormitorios;
    this -> cantBanios = cantBanios;
    this -> garage = garage;
    this -> m2Edificados = m2Edificados;
    this -> dir = dir;
    this -> enVenta = enVenta;
    this -> enAlquiler = enAlquiler;
    this -> nombreInmo = nombreInmo;
    this -> direccionInmo = direccionInmo;
}

// DESTRUCTOR:
dtPropiedadInmo::~dtPropiedadInmo(){
    cout << "destruct de dtPropiedadInmo" << endl;
}

// GETTERS:
string dtPropiedadInmo::getCodigo(){
    return this -> codigo;
}

int dtPropiedadInmo::getCantAmbientes(){
    return this -> cantAmbientes;
}

int dtPropiedadInmo::getCantDormitorios(){
    return this -> cantDormitorios;
}

int dtPropiedadInmo::getCantBanios(){
    return this -> cantBanios;
}

bool dtPropiedadInmo::getGarage(){
    return this -> garage;
}

int dtPropiedadInmo::getM2Edificados(){
    return this -> m2Edificados;
}

direccion *dtPropiedadInmo::getDireccion(){
    return this -> dir;
}

bool dtPropiedadInmo::getEnVenta(){
    return this -> enVenta;
}

bool dtPropiedadInmo::getEnAlquiler(){
    return this -> enAlquiler;
}

string dtPropiedadInmo::getNombreInmo(){
    return this -> nombreInmo;
}

direccion *dtPropiedadInmo::getDireccionInmo(){
    return this -> direccionInmo;
}