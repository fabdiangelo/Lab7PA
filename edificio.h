#ifndef EDIFICIO_H
#define EDIFICIO_H

#include "inmobiliaria.h"
#include "ICollection/collections/OrderedDictionary.h"
#include "ICollection/String.h"

class apartamento;

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
    IDictionary* getApartamentos();
    void setNombre(string nombre);
    void setCantPisos(int cantPisos);
    void setGastosComunes(int gastos);
    void agreagrPropiedad(apartamento* prop);
    void desvincularProp(string codigo);
    friend ostream& operator<<(ostream& os, edificio *ed);
};

#endif
