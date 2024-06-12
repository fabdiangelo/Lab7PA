#include "propiedad.h"

// CONSTRUCTOR:
propiedad::propiedad(string codigo, int cantAmbientes, int cantDormitorios, int cantBanios, bool garage, direccion* dir, int m2Edificados , zona* z){
    this -> codigo = codigo;
    this -> cantAmbientes = cantAmbientes;
    this -> cantDormitorios = cantDormitorios;
    this -> cantBanios = cantBanios;
    this -> garage = garage;
    this -> dir = dir;
    this -> m2Edificados = m2Edificados;
    this -> z = z;
    this -> precioAlquiler = 0;
    this -> precioVenta = 0;
    this -> chats = new List();
}

// DESTRUCTOR:
propiedad::~propiedad(){
    cout << ": propiedad" << endl;
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
zona* propiedad::getZona(){
    return this -> z;
}


// SETTERS:
void propiedad::setCantAmbientes(int cant){
    this -> cantAmbientes = cant;
}

void propiedad::setCantDormitorios(int cant){
    this -> cantDormitorios = cant;
}

void propiedad::setCantBanios(int cant){
    this -> cantBanios = cant;
}

void propiedad::setGarage(bool garage){
    this -> garage = garage;
}

void propiedad::setDireccion(direccion* dir){
    this -> dir = dir;
}

void propiedad::setM2Edificados(int m2){
    this -> m2Edificados = m2;
}

void propiedad::setPrecioAlquiler(int precio){
    this -> precioAlquiler = precio;
}

void propiedad::setPrecioVenta(int precio){
    this -> precioVenta = precio;
}

//FUNCIONALIDAD
void propiedad::CortarLazos(string codigo){

}

registroMensajes *propiedad::MostrarMensajes(){
    return NULL;
}

chat* propiedad::CrearChat(){
    return NULL;
}

void propiedad::IngresarMensaje(string mensaje){
    
}
int propiedad::obtenerCantMensajes(){
    return 1;
}