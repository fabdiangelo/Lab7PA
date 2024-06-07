#include "zona.h"

// CONSTRUCTOR

zona::zona(string nombre, string codigo){
    this->nombre = nombre;
    this->codigo = codigo;
}

// DESTRUCTOR

zona::~zona(){
    cout << "SOY ~ DE ZONA";
}

// GETTERS

string zona::getNombre(){
    return this->nombre;
}

string zona::getCodigo(){
    return this->codigo;
}

// SETTERS

void zona::setNombre(string nombre){
    this->nombre = nombre;
}

void zona::setCodigo(string codigo){
    this->codigo = codigo;
}

// FUNCIONALIDADES

List zona::listarEdificios(){
    
}




/*    
edificio seleccionarEdificio(string nombre);
void anidarAZona(propiedad prop);
void desvincularZona(string nombre);
List listarPropMens();
void encontrar(string nombre);
*/