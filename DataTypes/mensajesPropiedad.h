// Leandro
#ifndef MENSAJESPROPIEDAD_H
#define MENSAJESPROPIEDAD_H
#include <iostream>
#include "dtPropiedad.h"

using namespace std;

class mensajesPropiedad
{
private:
    int cantMensajes;
    dtPropiedad propiedad;
public:
    mensajesPropiedad(int cantidadMensajes, dtPropiedad propiedad);
    ~mensajesPropiedad();
    int getCantMensajes();
    dtPropiedad getPropiedad();
};


#endif