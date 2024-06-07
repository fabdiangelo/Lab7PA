#include "administrador.h"

// CONSTRUCTOR:
administrador::administrador(string correo, string contrasenia) : usuario(correo, contrasenia){
}

// DESTRUCTOR:
administrador::~administrador(){
    cout << "destruct de administrador";
}