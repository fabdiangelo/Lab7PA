#ifndef EDIFICIO_H
#define EDIFICIO_H

#include "propiedad.h"
#include "ICollection/collections/OrderedDictionary.h"
#include "ICollection/String.h"

class propiedad;

class edificio : public ICollectible{
  private:
    string nombre;
    int cantPisos;
    int gastosComunes;
    IDictionary *apartamentos;
  public:
    edificio(string nombre,int cantPisos,int gastosComunes);
    ~edificio();
    string getNombre();
    int getCantPisos();
    int getGastosComunes();
    void setNombre(string nombre);
    void setCantPisos(int cantPisos);
    void setGastosComunes(int gastos);
    void agreagrPropiedad(propiedad* prop);
    void desvincularProp(string codigo);
    friend ostream& operator<<(ostream& os, edificio *ed);
};

#endif
