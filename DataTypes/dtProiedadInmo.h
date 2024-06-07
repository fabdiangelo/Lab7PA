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
    direccion * direccion, direccionInmo;
public:
    dtProiedadInmo(char* codigo, int cantAmbientes, int cantDormitorios, int cantBanios, bool garage, direccion* direccion);
    ~dtProiedadInmo();
};
#endif
