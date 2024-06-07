#include "registroMensajes.h"

// COSNTRUCTOR:
registroMensajes::registroMensajes(){
    this -> mensajes = new List();
}

// DESTRUCTOR:
registroMensajes::~registroMensajes(){
    cout << "destruct de registroMensajes" << endl;
}

// GETTERS:
List *registroMensajes::getMensajes(){
    List * mensajes = (List *) this -> mensajes; 
    return mensajes;
}

// FUNCIONALIDADES:
void registroMensajes::agregarMensaje(dtMensaje * mens){
    if (this -> mensajes -> getSize() < 5){
        this -> mensajes -> add(mens);
    }else{
        cout << "Limite de mensajes superado" << endl; 
    }
}