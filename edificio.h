// Daniel
#ifndef EDIFICIO_H
#define EDIFICIO_H

#include "apartamento.h"

class edificio{
  private:
    string nombre;
    int cantPisos;
    int gastosComunes;
  public:
    string getNombre();
    int getCantPisos();
    int getGasto();
};

#endif