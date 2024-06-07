#include "usuario.h"

// CONSTRUCTOR
usuario::usuario(string correo, string contrasenia){
    this -> correo = correo;
    this -> contrasenia = contrasenia;
}

// DESTRUCTOR

usuario::~usuario(){
    cout << "SOY EL ~ DE USUARIO" <<endl;
}

// GETTERS

string usuario::getCorreo(){
    return this->correo;
}

string usuario::getContrasenia(){
    return this->contrasenia;
}

// SETTERS

void usuario::setCorreo(string correo){
    this -> correo = correo;
}

void usuario::setContrasenia(string getContrasenia){
    this -> contrasenia = contrasenia;
}