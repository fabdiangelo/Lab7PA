#ifndef DTPROPIEDADINMO_H
#define DTPROPIEDADINMO_H

#include <iostream>
#include "direccion.h"

using namespace std;

class dtPropiedadInmo
{
private:
    string nombreInmo, codigo;
    int cantAmbientes, cantDormitorios, cantBanios, m2Edificados;
    bool garage, enVenta, enAlquiler;
    direccion * dir;
    direccion * direccionInmo;
public:
    dtPropiedadInmo(string codigo, int cantAmbientes, int cantDormitorios, int cantBanios, bool garage, int m2Edificados, direccion* dir, bool enVenta, bool enAlquiler, string nombreInmo, direccion *direccionInmo);
    ~dtPropiedadInmo();
    string getCodigo();
    int getCantAmbientes();
    int getCantDormitorios();
    int getCantBanios();
    bool getGarage();
    int getM2Edificados();
    direccion *getDireccion();
    bool getEnVenta();
    bool getEnAlquiler();
    string getNombreInmo();
    direccion *getDireccionInmo();
};

#endif