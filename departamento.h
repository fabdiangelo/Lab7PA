#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H

#include "zona.h"
#include "DataTypes/dtZona.h"
#include "ICollection/interfaces/IDictionary.h"

class zona;

class departamento : public ICollectible
{
  private:
    string nombre;
    char id;
    IDictionary* zonas;
  public:
    departamento(string nombre, char id);
    ~departamento();
    string getNombre();
    char getId();
    IDictionary *getZonas();
    void setNombre(string nombre);
    void setId(char id);
    void agregarZona(string nombre, string codigo);
    zona* seleccionarZona(string);
    friend ostream& operator<<(ostream& os, departamento* dep);
};

#endif
