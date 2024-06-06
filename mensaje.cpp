#include "mensaje.h"

// CONTRUCTOR:
mensaje::mensaje(int hora, string mensaje){
}

// DESTRUCTOR:
mensaje::~mensaje(){
    cout << "detruct del mensaje"
}

// GETTERS:
int mensaje::getHora(){
    return this -> hora;
}

string mensaje::getMensaje(){
    return this -> mensaje;
}

// SETTERS:
void mensaje::setMensaje(string mens){
    this -> mensaje = mens; 
}