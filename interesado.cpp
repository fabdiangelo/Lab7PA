#include "interesado.h"

// CONSTRUCTOR:
interesado::interesado(string correo, string contrasenia, int edad, string nombre, string apellido) : usuario(correo, contrasenia){
    this -> edad = edad;
    this -> nombre = nombre;
    this -> apellido = apellido;
}

// DESTRUCTOR:
interesado::~interesado(){
    cout << "destruct del interesado";
}

// GETTERS:
int interesado::getEdad(){
    return this -> edad;
}

string interesado::getNombre(){
    return this -> nombre;
}

string interesado::getApellido(){
    return this -> apellido;
}

// SETTERS:
void interesado::setEdad(int edad){
    this -> edad = edad;
}

void interesado::setNombre(string nombre){
    this -> nombre = nombre;
}

void interesado::setApellido(string apellido){
    this -> apellido = apellido;
}