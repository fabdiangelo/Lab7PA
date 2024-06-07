#include "dtMensaje.h"

// CONSTRUCTOR:
dtMensaje::dtMensaje(string mensaje, int hora){
    this -> mensaje = mensaje;
    this -> hora = hora;
}

// DESTRUCTOR:
dtMensaje::~dtMensaje(){
    cout << "destruct de dtMensaje" << endl;
}

// GETTERS:
string dtMensaje::getMensaje(){
    return this -> mensaje;
}

int dtMensaje::getHora(){
    return this -> hora;
}