#include "departamento.h"

// CONSTRUCTOR:
departamento::departamento(string nombre, char id){
    this -> nombre = nombre;
    this -> id = id;
    this -> zonas = new List();
}

// DESTRUCTOR:
departamento::~departamento(){
    cout << "destruct de departamento" << endl;
}

// GETTERS:
string departamento::getNombre(){
    return this -> nombre;
}

char departamento::getId(){
    return this -> id;
}

// SETTERS:
void departamento::setNombre(string nombre){
    this -> nombre = nombre;
}

void departamento::setId(char id){
    this -> id = id;
}

// FUNCIONALIDADES:
void departamento::agregarZona(string nombre, string codigo){
    zona* z = new zona(nombre, codigo, this);
    this -> zonas -> add(z);
}

ICollection* departamento::obtenerListado(){
    ICollection* listado = new List();
    for(IIterator *iter = this -> zonas -> getIterator(); iter -> hasCurrent(); iter -> next()){
        zona *z =(zona*) iter -> getCurrent();
        dtZona *dtZ = new dtZona(z -> getNombre(), z -> getCodigo());
        listado -> add (dtZ);
    }
    return listado;
}

zona* departamento::seleccionarZona(string cod){
    for(IIterator *iter = this -> zonas -> getIterator(); iter -> hasCurrent(); iter -> next()){
        zona *z =(zona*) iter -> getCurrent();
        if (z -> getCodigo() == cod){
            return z;
        }
    }
    cout << "No se encontró una zona con ese código dentro de " << this -> getNombre();
    return NULL;
}