#ifndef DTINMOBILIARIA_H
#define DTINMOBILIARIA_H

#include "direccion.h"

class dtInmobiliaria
{
private:
    string nombre, correo;
    direccion* dir;
public:
    dtInmobiliaria(string nombre, string correo, direccion * dir);
    ~dtInmobiliaria();
    string getNombre();
    string getCorreo();
    direccion* getDireccion();
};

#endif