#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H

#include <iostream>
#include "DataTypes/direccion.h"
#include "usuario.h"
#include "propiedad.h"

using namespace std;

class interesado : usuario
{
private:
    int edad;
    string nombre, apellido;
public:
    interesado(int edad, string nombre, string apellido);
    ~interesado();
    int getEdad();
    string getNombre();
    string getApellido();
    void setEdad(int edad);
    void setNombre(string nombre);
    void setApellido(string apellido);
};

#endif