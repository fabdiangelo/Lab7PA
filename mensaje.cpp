#include "mensaje.h"

// CONTRUCTOR:
mensaje::mensaje(int hora, string cont, string ahora){
    this -> contenido = cont;
    this -> hora = hora;
    this -> momento = ahora;
}

// DESTRUCTOR:
mensaje::~mensaje(){
    cout << "detruct de mensaje" << endl;
}

// GETTERS:
int mensaje::getHora(){
    return this -> hora;
}

string mensaje::getMensaje(){
    return this -> contenido;
}

string mensaje::getMomento(){
    return this -> momento;
}

// SETTERS:
void mensaje::setMensaje(string mens){
    this -> contenido = mens; 
}