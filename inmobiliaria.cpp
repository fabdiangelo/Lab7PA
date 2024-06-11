#include "inmobiliaria.h"

// CONSTRUCTOR:
inmobiliaria::inmobiliaria(string correo, string contrasenia, string nom, direccion* dir) : usuario(correo, contrasenia){
    this -> nombre = nom;
    this -> dir = dir;
    this -> propiedades = new OrderedDictionary();
}

// DESTRUCTOR:
inmobiliaria::~inmobiliaria(){
    cout << "destruct de inmobiliaria" << endl;
}

// GETTERS:
string inmobiliaria::getNombre(){
    return this -> nombre;
}

direccion* inmobiliaria::getDireccion(){
    return this -> dir;
}

// SETTERS:
void inmobiliaria::setNombre(string nom){
    this -> nombre = nom;
}

void inmobiliaria::setDireccion(direccion* dir){
    this -> dir = dir;
}

// FUNCIONALIDAD:
propiedad* inmobiliaria::IngresarDatosApartamento(string cod, int cantAmb, int cantDorm, int cantBa, bool garage, direccion* dir, int m2, int precioAlquiler, int precioVenta, int m2T){
    propiedad *prop = new apartamento(cod, cantAmb, cantDorm, cantBa, garage, dir, m2, precioAlquiler, precioVenta);
    IKey *k = new String(cod.c_str());
    this -> propiedades -> add (k, prop);
    return prop;
}

propiedad* inmobiliaria::IngresarDatosCasa(string cod, int cantAmb, int cantDorm, int cantBa, bool garage, direccion* dir, int m2, int precioAlquiler, int precioVenta, int m2V){
    propiedad *ca = new casa(cod, cantAmb, cantDorm, cantBa, garage, dir, m2, precioAlquiler, precioVenta, m2V);
    IKey *k = new String(cod.c_str());
    this -> propiedades -> add (k, ca);
    return ca;
}

void inmobiliaria::IngresarPrecioAlquiler(int precio){

}

void inmobiliaria::IngresarPrecioVenta(int precio){

}

void inmobiliaria::BorrarPropiedad(string prop){

}

propiedad* inmobiliaria::ModificarDatosApartamento(int cantAmb, int cantDorm, int cantBa, bool garage, direccion* dir, int m2){
    return NULL;
}

propiedad* inmobiliaria::ModifiarDatosCasa(int cantAmb, int cantDorm, int cantBa, bool garage, direccion* dir, int m2Edif, int m2Verd){
    return NULL;
}

void inmobiliaria::MostrarDatos(){

}