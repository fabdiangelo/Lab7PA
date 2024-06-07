#include "propiedad.h"

// CONSTRUCTOR:
propiedad::propiedad(string codigo, int cantAmbientes, int cantDormitorios, int cantBanios, bool garage, direccion* dir, int m2Edificados, int precioAlquiler, int precioVenta){
    this -> codigo = codigo;
    this -> cantAmbientes = cantAmbientes;
    this -> cantDormitorios = cantDormitorios;
    this -> cantBanios = cantBanios;
    this -> garage = garage;
    this -> dir = dir;
    this -> m2Edificados = m2Edificados;
    this -> precioAlquiler = precioAlquiler;
    this -> precioVenta = precioVenta;
    this -> chats = NULL;
}

// DESTRUCTOR:
propiedad::~propiedad(){
    cout << "destruct de propiedad";
}

// GETTERS:
string propiedad::getCodigo(){
    return this -> codigo;
}

int propiedad::getCantAmbientes(){
    return this -> cantAmbientes;
}

int propiedad::getCantDormitorios(){
    return this -> cantDormitorios;
}

int propiedad::getCantBanios(){
    return this -> cantBanios;
}

bool propiedad::getGarage(){
    return this -> garage;
}

direccion* propiedad::getDireccion(){
    return this -> dir;
}

int propiedad::getM2Edificados(){
    return this -> m2Edificados;
}

int propiedad::getPrecioAlquiler(){
    return this -> precioAlquiler;
}

int propiedad::getPrecioVenta(){
    return this -> precioVenta;
}

// SETTERS:
void propiedad::setPrecioAlquiler(int precio){
    this -> precioAlquiler = precio;
}

void propiedad::setPrecioVenta(int precio){
    this -> precioVenta = precio;
}

//FUNCIONALIDAD
//pendiente...
void propiedad::CortarLazos(string codigo){

}

registroMensajes propiedad::MostrarMensajes(){
    return NULL;
}

chat *propiedad::CrearChat(){
    return NULL;
}

void propiedad::IngresarMensaje(string mensaje){
    
}