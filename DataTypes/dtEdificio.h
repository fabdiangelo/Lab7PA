// Daniel

#ifndef DTEDIFICIO_H
#define DTEDIFICIO_H

#include <iostream>
using namespace std;

class dtEdificio {
    private:
      string nombre;
      int cantPisos;
      int gastosComunes;
    public:
      dtEdificio(string nombre,int cantPisos,int gastosComunes);
      string getNombre();
      int getCantPisos();
      int getGastosComunes();
      ~dtEdificio();
};
#endif