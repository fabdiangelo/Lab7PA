#include "mensajesPropiedad.h"

// CONSTRUCTOR:
mensajesPropiedad::mensajesPropiedad(int cantidadMensajes, dtPropiedad *propiedad){
    this -> cantMensajes = cantidadMensajes;
    this -> propiedad = propiedad;
}

// DESTRUCTOR:
mensajesPropiedad::~mensajesPropiedad(){
    cout << "destruct de mensajesPropiedad" << endl;
}

// GETTERS:
int mensajesPropiedad::getCantMensajes(){
    return this -> cantMensajes;
}

dtPropiedad *mensajesPropiedad::getPropiedad(){
    return this -> propiedad;
}