#include "zona.h"

// CONSTRUCTOR:
zona::zona(string nombre, string codigo, departamento* dep){
    this -> nombre = nombre;
    this -> codigo = codigo;
    this -> dep = dep;
    this -> edificios = new OrderedDictionary();
    this -> propiedades = new OrderedDictionary();
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
IDictionary* zona::listarEdificios(){
    return this -> edificios;
}
edificio* zona::seleccionarEdificio(string nombre){

}
void zona::agegarEdificio(edificio* prop){

}
void zona::desvincularEdifico(string nombre){

}
IDictionary* zona::listarPropiedades(){
    return this -> propiedades;
}
propiedad* zona::seleccionarPropiedad(string codigo){

}
void zona::agegarPropiedad(propiedad* prop){

}
void zona::desvincularPropiedad(string codigo){

}
List* zona::listarPropMens(){

}
void zona::encontrar(string nombre){

}