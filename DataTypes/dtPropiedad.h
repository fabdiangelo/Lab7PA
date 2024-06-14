#ifndef DTPROPIEDAD_H
#define DTPROPIEDAD_H

#include "direccion.h"

class dtPropiedad
{
private:
    string codigo;
    direccion *dir;
    bool enVenta, enAlquiler;
public:
    dtPropiedad(string codigo, direccion* dir, bool enVenta, bool enAlquiler);
    ~dtPropiedad();
    string getCodigo();
    direccion* getDir();
    bool getEnVenta();
    bool getEnAlquiler(); 
};

#endif