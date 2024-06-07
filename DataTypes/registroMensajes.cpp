#include "registroMensajes.h"

// COSNTRUCTOR:
registroMensajes::registroMensajes(List *mensajes){
    // if(mensajes -> getSize() > 5){
    //     IIterator *iter = mensajes -> getIterator();
    //     List * temp;
    //     for (int i = 0; i < 5; i++){
    //         temp -> add( iter -> getCurrent() );
    //         iter -> next();
    //     }
    // }else{
        this -> mensajes = mensajes;
    // }
}

// DESTRUCTOR:
registroMensajes::~registroMensajes(){
    cout << "destruct de registroMensajes" << endl;
}

// GETTERS:
List *registroMensajes::getMensajes(){
    return this -> mensajes;
}