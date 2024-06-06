#include "inmobiliaria.h"

// CONSTRUCTOR:
inmobiliaria::inmobiliaria(string nom, direccion* dir)
{
    this -> nombre = nom;
    this -> direccion = dir;
}

// DESTRUCTOR:
inmobiliaria::~inmobiliaria()
{
}

// GETTERS:
string inmobiliaria::getNombre()
{
    return this -> nombre;
}

direccion * inmobiliaria::getDireccion()
{
    return this -> direccion;
}

// FUNCIONALIDAD:
//pendiente...