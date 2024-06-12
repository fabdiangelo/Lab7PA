#include "propiedad.h"

// CONSTRUCTOR:
propiedad::propiedad(string codigo, int cantAmbientes, int cantDormitorios, int cantBanios, bool garage, direccion* dir, int m2Edificados, zona* z){
    this -> codigo = codigo;
    this -> cantAmbientes = cantAmbientes;
    this -> cantDormitorios = cantDormitorios;
    this -> cantBanios = cantBanios;
    this -> garage = garage;
    this -> dir = dir;
    this -> m2Edificados = m2Edificados;
    this -> precioAlquiler = 0;
    this -> precioVenta = 0;
    this -> chats = NULL;
    this -> z = z;
}

// DESTRUCTOR:
propiedad::~propiedad(){
    cout << "destruct de propiedad" << endl;
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

registroMensajes *propiedad::MostrarMensajes(){
    return NULL;
}

chat *propiedad::CrearChat(){
    return NULL;
}

void propiedad::IngresarMensaje(string mensaje){
    
}
int propiedad::obtenerCantMensajes(){
    return 1;
}