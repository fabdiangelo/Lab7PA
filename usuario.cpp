#include "usuario.h"

// CONSTRUCTOR:
usuario::usuario(string correo, string contrasenia){
    this -> correo = correo;
    this -> contrasenia = contrasenia;
}

// DESTRUCTOR:
usuario::~usuario(){
    cout << "destruct de usuario" << endl;
}

// GETTERS:
string usuario::getCorreo(){
    return this -> correo;
}

string usuario::getContrasenia(){
    return this -> contrasenia;
}

// SETTERS:
void usuario::setCorreo(string correo){
    this -> correo = correo;
}

void usuario::setContrasenia(string contrasenia){
    this -> contrasenia = contrasenia;
}