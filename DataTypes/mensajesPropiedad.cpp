#include "mensajesPropiedad.h"

// Constructor

mensajesPropiedad::mensajesPropiedad(int cantidadMensajes, dtPropiedad propiedad){
    this->cantMensajes = cantidadMensajes;
    this->propiedad = propiedad;
}

// Destructor

mensajesPropiedad::~mensajesPropiedad(){
    cout << "SOY EL ÑOQUI DE MENSAJESPROPIEDAD DE LOS DATATYPES";
}

// getters

int mensajesPropiedad::getCantMensajes(){
    cout << "CHUPERMAN EN VISICLETA";
}

dtPropiedad mensajesPropiedad::getPropiedad(){
    // FALTA REALIZAR DTPROPIEDAD PARA PODER PROGREZAR
}