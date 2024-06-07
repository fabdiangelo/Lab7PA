#include "zona.h"

// CONSTRUCTOR:
zona::zona(string nombre, string codigo){
    this -> nombre = nombre;
    this -> codigo = codigo;
}

// DESTRUCTOR:
zona::~zona(){
    cout << "destruct de zona";
}

// GETTERS:
string zona::getNombre(){
    return this -> nombre;
}

string zona::getCodigo(){
    return this -> codigo;
}

// SETTERS:
void zona::setNombre(string nombre){
    this -> nombre = nombre;
}

void zona::setCodigo(string codigo){
    this -> codigo = codigo;
}

// FUNCIONALIDADES:
List zona::listarEdificios(){
    // return NULL;
}

edificio zona::seleccionarEdificio(string nombre){
    // return NULL;
}

void zona::anidarAZona(propiedad prop){

}

void zona::desvincularZona(string nombre){

}

List zona::listarPropMens(){
    // return NULL;
}

void zona::encontrar(string nombre){

}