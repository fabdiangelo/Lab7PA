#ifndef DTINMOBILIARIA_H
#define DTINMOBILIARIA_H

#include <iostream>
#include "direccion.h"

using namespace std;

class dtInmobiliaria
{
private:
    string nombre, correo;
    direccion *direccion;
public:
    dtInmobiliaria(string nombre, string codigo, direccio *direccion);
    ~dtInmobiliaria();
    string getNombre();
    string getCorreo();
    direccion *direccion();
};

#endif