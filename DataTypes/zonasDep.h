#ifndef ZONASDEP_H
#define ZONASDEP_H

#include <iostream>
#include "../departamento.h"
#include "propZona.h"

class zonasDep : public ICollectible
{
private:
    departamento* dep;
    IDictionary *propZonas;
public:
    zonasDep(departamento* dep);
    ~zonasDep();
    departamento* getDepartamento();
    IDictionary* getZonas();
    void agregarZona(zona* z);
};

#endif