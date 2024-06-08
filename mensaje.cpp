#include "mensaje.h"

// CONTRUCTOR:
mensaje::mensaje(int hora, string cont){
    this -> contenido = cont;
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