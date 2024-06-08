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
    edificio(string nombre,int cantPisos,int gastosComunes);
    string getNombre();
    int getCantPisos();
    int getGastosComunes();
    void setNombre(string nombre);
    void setCantPisos(int cantPisos);
    void aniadirAEdificio(propiedad);
    void desvincularEd(string);
    ~edificio();
};

#endif
