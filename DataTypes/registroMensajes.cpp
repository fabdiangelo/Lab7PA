// Leandro
#include "registroMensajes.h"

// Constructor

registroMensajes::registroMensajes(dtMensaje mensajes[5]){
    for(int i=0; i < 5; i++){
        this->mensajes[i] = mensajes[i];
    }
}

// Destructor

registroMensajes::~registroMensajes(){
    cout << "SOY EL ÑOQUIS DE REGISTROMENSAJES DE DATATYPES";
}

// Getters

dtMensaje registroMensajes::getMensajes(){

}