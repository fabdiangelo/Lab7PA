// Leandro
#include "registroMensajes.h"

// Constructor

registroMensajes::registroMensajes(List mensajes){
    this->mensajes = mensajes;
}

// Destructor

registroMensajes::~registroMensajes(){
    cout << "SOY EL ÑOQUIS DE REGISTROMENSAJES DE DATATYPES";
}

// Getters

List registroMensajes::getMensajes(){
    return mensajes;
}