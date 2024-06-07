#include "mensaje.h"

// CONTRUCTOR:
mensaje::mensaje(int hora, string mensaje){
    this -> contenido = mensaje;
    this -> hora = hora;
}

// DESTRUCTOR:
mensaje::~mensaje(){
    cout << "detruct de mensaje";
}

// GETTERS:
int mensaje::getHora(){
    return this -> hora;
}

string mensaje::getMensaje(){
    return this -> contenido;
}

// SETTERS:
void mensaje::setMensaje(string mens){
    this -> contenido = mens; 
}