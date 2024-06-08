#include "departamento.h"


departamento::departamento(string nombre, char id){
    this ->nombre = nombre;
    this ->id = id;
}

~departamento();
departamento::~departamento(){
    cout<<endl<<"se a eliminado el departamento"<<endl;
}

string departamento::getNombre(){
    return this -> nombre;
}

char departamento::getId(){
    return this -> id;
}

void departamento::setNombr(string nombre){
    this -> nombre = nombre;
}

void departamento::setId(char id){
    this -> id = id;
}

/*
faltan:
List* obtenerListado();
zona seleccionarZona(string);*/