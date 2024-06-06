#include "administrador.h"

administrador::administrador(string corre, string contra){
    this->correo = corre;
    this->contrasenia = contra;
}

administrador::~administrador(){
    cout << "murio...";
}

