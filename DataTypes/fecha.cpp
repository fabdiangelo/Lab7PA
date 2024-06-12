#include "fecha.h"

// CONSTRUCTOR:
fecha::fecha(int d, int m, int a){
    this -> dia = d;
    this -> mes = m;
    this -> anio = a;
}

// DESTRUCTOR:
fecha::~fecha(){
    cout << "destruct de fecha" << endl;
}

// GETTERS:
int fecha::getDia(){
    return this -> dia;
}

int fecha::getMes(){
    return this -> mes;
}

int fecha::getAnio(){
    return this -> anio;
}