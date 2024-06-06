#include "inmobiliaria.h"

// CONSTRUCTOR:
inmobiliaria::inmobiliaria(string nom, direccion* dir){
    this -> nombre = nom;
    this -> direccion = dir;
    this -> propiedades = NULL
}

// DESTRUCTOR:
inmobiliaria::~inmobiliaria(){
}

// GETTERS:
string inmobiliaria::getNombre(){
    return this -> nombre;
}

direccion* inmobiliaria::getDireccion()
{
    return this -> direccion;
}

// SETTERS:
void inmobiliaria::setNombre(string nom){
    this -> nombre = nom;
}

void inmobiliaria::setDireccion(direccion* dir){
    this -> direccion = dir;
}

// FUNCIONALIDAD:
//pendiente...
propiedad IngresarDatosApartamento(int cantAmb, int cantDorm, int cantBa, bool garage, direccion* dir, int m2);

propiedad IngresarDatosCasa(int cantAmb, int cantDorm, int cantBa, bool garage, direccion* dir, int m2Edif, int m2Verd);

void IngresarPrecioAlquiler(int precio);

void IngresarPrecioVenta(int precio);

void BorrarPropiedad(string prop);

propiedad ModificarDatosApartamento(int cantAmb, int cantDorm, int cantBa, bool garage, direccion* dir, int m2);

propiedad ModifiarDatosCasa(int cantAmb, int cantDorm, int cantBa, bool garage, direccion* dir, int m2Edif, int m2Verd);

void MostrarDatos();