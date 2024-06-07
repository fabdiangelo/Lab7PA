#include "fecha.h"

// CONSTRUCTOR:
fecha::fecha(string d, string m, string a){
    this -> dia = d;
    this -> mes = m;
    this -> anio = a;
}

// DESTRUCTOR:
fecha::~fecha(){
    cout << "destruct de fecha" << endl;
}

// GETTERS:
string fecha::getDia(){
    return this -> dia;
}

string fecha::getMes(){
    return this -> mes;
}

string fecha::getAnio(){
    return this -> anio;
}