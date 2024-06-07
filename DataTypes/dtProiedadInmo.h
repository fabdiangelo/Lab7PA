#ifndef DTPROPIEDADINMO_H
#define DTPROPIEDADINMO_H

#include <iostream>
#include "DataTypes/direccion.h"

using namespace std;

class dtProiedadInmo
{
private:
    char * codigo;
    string nombreInmo;
    int cantAmbientes, cantDormitorios, cantBanios, m2Edificados;
    bool garage, enVenta, enAlquiler;
    direccion * dir, direccionInmo;
public:
    dtProiedadInmo(char* codigo, int cantAmbientes, int cantDormitorios, int cantBanios, bool garage, direccion* dir);
    ~dtProiedadInmo();
};
#endif
