// Bernardo
#include "dtDepartamento.h"

// CONSTRUCTOR

dtDepartamento::dtDepartamento(string nombre, char identificador){
    this->nombre = nombre;
    this->identificador = identificador;
}

// DESTRUCTOR

dtDepartamento::~dtDepartamento(){
    cout << "SOY EL ~ DE DTDEPARTAMENTO" << endl;
}

// GETTERS

string dtDepartamento::getNombre(){
    return this->nombre;
}

char dtDepartamento::getIdentificador(){
    return this->identificador;
}