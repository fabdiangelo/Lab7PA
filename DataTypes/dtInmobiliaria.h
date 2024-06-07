#ifndef DTINMOBILIARIA_H
#define DTINMOBILIARIA_H

#include <iostream>
#include "direccion.h"

using namespace std;

class dtInmobiliaria
{
private:
    string nombre, correo;
    direccion dir;
public:
    dtInmobiliaria(string nombre, string correo, direccion * dir);
    ~dtInmobiliaria();
    string getNombre();
    string getCorreo();
    direccion* getDireccion();
};

#endif