#include "direccion.h"

// CONSTRUCTOR:
direccion::direccion(string ciudad, string calle, string numero)
{
    this -> ciudad = ciudad;
    this -> calle = calle;
    this -> numero = numero;
}

// DESTRUCTOR: 
direccion::~direccion()
{
}

// GETTERS:
string direccion::getCiudad(){
    return this -> ciudad;
}

string direccion::getCalle(){
    return this -> calle;
}

string direccion::getNumero(){
    return this -> numero;
}