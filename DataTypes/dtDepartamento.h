// Bernardo

#ifndef DTDEPARTAMENTO_H
#define DTDEPARTAMENTO_H

#include <iostream>

using namespace std;

class dtDepartamento
{
private:
    string nombre;
    char identificador;
public:
    dtDepartamento(string nombre, char identificador);
    ~dtDepartamento();
    string getNombre();
    char getIdentificador();
};


#endif